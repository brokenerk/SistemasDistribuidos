#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#if !defined(FILESAVER_H_)
#define FILESAVER_H_
class FileSaver
{
private:
    std::ofstream file;
public:
    void saveFile(string);
    FileSaver(string ruta);
    void closeFile();
};
#endif // FILESAVER_H_
