#include "PCLab.h"

PaqueteDatagrama handshake = PaqueteDatagrama(4);

PCLab::PCLab() {
	s = new SocketDatagrama(7200);
}

void PCLab::recibePeticion() { 
    s->recibe(handshake, 0, 0);
    memcpy(&resolucion, handshake.obtieneDatos(), 4);
    //printf("\nResol: %d\n", resolucion);
}

void PCLab::capturaPantalla() {
    int status = mkdir("screenshots", 0777);
    if(status != 0 && errno != EEXIST) {
        cerr << "Error :  " << strerror(errno) << endl; 
        exit(EXIT_FAILURE);
    }
    else {
	   system(("scrot ./screenshots/captura.jpg -q " + to_string(resolucion)).c_str());
    }
}

void PCLab::enviaImagen() {
	ifstream in("./screenshots/captura.jpg", ios::in|ios::binary|ios::ate);
    int tam = in.tellg();
    printf("\nTam: %d", tam);

    handshake.inicializaDatos((char*)&tam);
    s->envia(handshake);

    int enviados = 0;
    while(enviados < tam) {
        int n = 65000;
        if(tam - enviados < n)
            n = tam - enviados;

        PaqueteDatagrama p1 = PaqueteDatagrama((char*)&n, 4, handshake.obtieneDireccion(), handshake.obtienePuerto());
        s->envia(p1);

        char* imagen = new char[n];
        in.seekg(enviados, ios::beg);
        in.read(imagen, n);

        PaqueteDatagrama p2 = PaqueteDatagrama(imagen, n, handshake.obtieneDireccion(), handshake.obtienePuerto());
        s->envia(p2);
        enviados += n;

        //printf("\nBytes leidos: %d", n);
        delete[] imagen;
    }

    in.close();
    cout << "\ncaptura.jpg enviada" << endl;
}