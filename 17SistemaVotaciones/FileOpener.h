#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#if !defined(FILEOPENER_H_)
#define FILEOPENER_H_
class FileOpener
{
private:
    /* data */
public:
    vector<char> getInfo(string path);
};

#endif // FILEOPENER_H_
