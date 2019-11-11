#include "FileOpener.h"

vector<char> FileOpener::getInfo(string ruta){
    ifstream in(ruta, ios::binary );
    if( in.fail() ) throw 0;
    vector<char> const contents(
        (istreambuf_iterator<char>(in)),
        (istreambuf_iterator<char>())
        );
    return contents;
}