#include <string>
#include <iostream>
#include <fstream>
#include "PaqueteDatagrama.h"
#include <vector>
using namespace std;
#if !defined(FILESAVER_H_)
#define FILESAVER_H_
class FileSaver
{
private:
    /* data */
public:
    void saveFile(string ruta,vector<PaqueteDatagrama> paquetes);
};
#endif // FILESAVER_H_
