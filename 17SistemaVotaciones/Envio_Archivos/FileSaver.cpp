#include "FileSaver.h"
#include <iostream>
#include <fstream>
using namespace std;
void FileSaver::saveFile(string ruta,vector<char> info){
    std::ofstream file1(ruta, std::ofstream::out | std::ofstream::trunc);
    file1.close();
    std::ofstream file(ruta, std::ios::out | std::ios::binary | std::ios::app);
    for(int i = 0;i<info.size();i++){
        file.write((const char *)info[i],1);
    }
    file.close();
}