#include "FileSaver.h"
#include <iostream>
#include <fstream>
using namespace std;

FileSaver::FileSaver(string ruta){
    std::ofstream file1(ruta, std::ofstream::out | std::ofstream::trunc);
    file1.close();
    file.open(ruta);
}

void FileSaver::saveFile(string info){
    if(file){
        info=info+"\n";
        file.write(info.c_str(),32);
    }else{
        cerr<<"open file error\n";
    }
}

void FileSaver::closeFile(){
    file.close();
}