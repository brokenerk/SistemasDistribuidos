#include "ServidorWeb.h"
char ip[13];
int ult, segundos;
static struct mg_serve_http_opts opts;

ServidorWeb::ServidorWeb(char* directorio, char* pto) {
	cs_stat_t st;
	port = pto; // Puerto
	opts.document_root = directorio; // Directorio actual

	if (mg_stat(opts.document_root, &st) != 0) {
		fprintf(stderr, "%s", "No se encontro el directorio, saliendo\n");
		exit(1);
	}
}

void ServidorWeb::inicializaDatos(char* dirIp, int u, int s) {
	memcpy(ip, dirIp, 13);
	ult = u;
	segundos = s;
}

void ServidorWeb::escuchar() {
	mg_mgr_init(&mgr, NULL);
	nc = mg_bind(&mgr, port, ServidorWeb::manejarEvento);

	if (nc == NULL) {
		printf("Error al crear el listener\n");
		exit(EXIT_FAILURE);
	}

	//Establecer parametros servidor HTTP
	mg_set_protocol_http_websocket(nc);
	cout << "Servidor web en el puerto: " << port << " escuchando..." << endl;
	while(true) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
}

void ServidorWeb::manejarEvento(struct mg_connection *nc, int ev, void *ev_data) {
	struct http_message *hm = (struct http_message *) ev_data;
	if(ev == MG_EV_HTTP_REQUEST) {
		//URL del AJAX en JS
		if (mg_vcmp(&hm->uri, "/updateImg") == 0) {
			cout << "Peticion HTTP" << endl;
			ServidorWeb::cargarImagenes(nc);
		}
		else 
        	mg_serve_http(nc, hm, opts);  // Contenido estatico
	}
}

void ServidorWeb::cargarImagenes(struct mg_connection *nc){ 
	//Chunked encoding para evitar calcular la longitud del contenido
	mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");

	// Se envia un JSON con la direccion IP de las pcs del lab
	mg_printf_http_chunk(nc, "{ \"ip\": \"%s\",  \"ult\": %d, \"segs\": %d }", ip, ult, segundos);

	//Enviar chunk vacio, fin de la respuesta
	mg_send_http_chunk(nc, "", 0);
}