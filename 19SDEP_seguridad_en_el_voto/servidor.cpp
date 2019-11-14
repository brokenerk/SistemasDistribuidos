#include "Respuesta.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sys/time.h>
#include <algorithm>    // std::binary_search, std::sort

using namespace std;
struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
	string toString()
	{
		return string(celular)+string(CURP)+string(partido);
	}
    bool operator<(const registro & other) const
    {
        return atoi(celular) < atoi(other.celular);
    }
};


bool exist (registro r1,registro r2) {
    if(string(r1.celular)==string(r2.celular))
        return false;
    return true;
}


int main()
{
    Respuesta resp(7200);
    vector <registro> registros;
    cout << "Servidor iniciado....\n";
    std::ofstream file1("registros.txt", std::ofstream::out | std::ofstream::trunc);
    file1.close();
    ofstream output;
    while (true) {
        struct mensaje *msj = resp.getRequest();
        if(msj != NULL) {
            output.open("registros.txt", ios::out | ios::app );
        	struct registro r;
	        memcpy(&r, &msj->arguments, sizeof(registro));
            sort (registros.begin(), registros.end());
            if(!binary_search(registros.begin(), registros.end(), r,exist)){
                registros.push_back(r);
                timeval actual;
                gettimeofday(&actual,NULL);
                string regs = r.toString();
                output.write(regs.c_str(),regs.length());
                output.write("\n",1);
                cout<<actual.tv_sec<<endl;
                cout<<actual.tv_usec<<endl;
                resp.sendReply((char *)&actual);
            }else{
                struct timeval actual;
                resp.sendReply((char *)&actual);
            }
            output.close();
        }
    }
}