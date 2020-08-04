#include "Central.h"

Central::Central() {
	cl = new SocketDatagrama(0);	
}

void Central::inicializaResolucion(char* resol) {
	if(strcmp(resol, "alta") == 0)
		resolucion = 75;
	else if (strcmp(resol, "media") == 0)
		resolucion = 50;
	else if (strcmp(resol, "baja") == 0)
		resolucion = 5;
	else {
		cout << "Error. Resoluciones permitidas: alta, media, baja" << endl;
		exit(0);
	}
}

char* Central::calcularRangoIP(char* ip) {
	char* tokensIP;
	char* res = new char[13];
	int cont = 0;

	while ((tokensIP = strtok_r(ip, ".", &ip))){
		if(cont < 3) {
			strcat(res, tokensIP);
    		strcat(res, ".");
		}
		else
			ultIP = atoi(tokensIP);
		cont++;
	}
   	return res;
}

int Central::obtieneUltIP(){
	return ultIP;
}

int Central::enviaPeticion(char* ip) {
	PaqueteDatagrama req = PaqueteDatagrama((char*)&resolucion, 4, ip, 7200);
	cl->envia(req);
	int res = cl->recibe(req, 2, 0);

	int n = 1;
	while (res == -1 && n < 3) {
		cl->envia(req);
		res = cl->recibe(req, 2, 0);
		n++;
	}

	if (n == 3) {
		cout << "PC sin conexion." << endl;
	}
	else {
		memcpy(&tamImagen, req.obtieneDatos(), 4);
		//printf("Tam: %d", tamImagen);
	}
	return res;
}

void Central::guardaImagen(string ip) {
	int status = mkdir("www", 0777);
    if(status != 0 && errno != EEXIST) {
        cerr << "Error :  " << strerror(errno) << endl; 
        exit(EXIT_FAILURE);
    }
    else {
	    ofstream out("./www/" + ip + ".jpg", ios::out|ios::binary|ios::ate);
	    int recibidos = 0;
	    
	    while(recibidos < tamImagen) {
	    	PaqueteDatagrama p1 = PaqueteDatagrama(4);
	        cl->recibe(p1, 0, 0);

	        int n;
	        memcpy(&n, p1.obtieneDatos(), 4);

	        PaqueteDatagrama p2 = PaqueteDatagrama(n);
	        cl->recibe(p2, 0, 0);

	        out.seekp(recibidos, ios::beg);
	        out.write(p2.obtieneDatos(), n);
	        recibidos += n;

	        //printf("\nBytes recibidos: %d", n);
	    }
		out.close();
		cout << "\nImagen " + ip + " recibida" << endl;
	}
}