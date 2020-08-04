#ifndef SERVIDORWEB_H_
#define SERVIDORWEB_H_
#include "mongoose.h"
#include <iostream>
using namespace std;

class ServidorWeb{
	public:
		ServidorWeb(char* directorio, char* pto);
		void inicializaDatos(char* dirIp, int u, int s);
		void escuchar();
	private:
		static void manejarEvento(struct mg_connection *nc, int ev, void *ev_data);
		static void cargarImagenes(struct mg_connection *nc);
		struct mg_mgr mgr;
		struct mg_connection* nc;
		const char* port;
};
#endif