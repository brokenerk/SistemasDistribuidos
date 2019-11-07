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
    /* data */
public:
    void saveFile(string path,vector<char>);
};
#endif // FILESAVER_H_
