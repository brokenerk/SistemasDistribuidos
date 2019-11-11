#include "FileSaver.h"
#include <iostream>
#include <fstream>
using namespace std;
void FileSaver::saveFile(string ruta,vector<PaqueteDatagrama> paquetes){
    std::ofstream file1(ruta, std::ofstream::out | std::ofstream::trunc);
    file1.close();
    std::ofstream file(ruta, std::ios::out | std::ios::binary | std::ios::app);
    for(int i = 0;i<paquetes.size();i++){
        file.write(paquetes[i].obtieneDatos(),paquetes[i].obtieneLongitud());
    }
    file.close();
}