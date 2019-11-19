#include "Respuesta.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <algorithm>    // std::binary_search, std::sort
using namespace std;
int main()
{
    Respuesta resp(7200);
    vector <int> registros;
    cout << "Servidor iniciado....\n";
    std::ofstream file1("registros.txt", std::ofstream::out | std::ofstream::trunc);
    file1.close();
    ofstream output;
    while (true) {
        struct mensaje *msj = resp.getRequest();
        if(msj != NULL) {
            output.open("registros.txt", ios::out | ios::app );
            struct registro r;
            memcpy(&r, &msj->arguments, sizeof(struct registro));
            timeval actual;
            actual.tv_sec = 0;
            actual.tv_usec = 0;
            if(!binary_search(registros.begin(), registros.end(),atoi(r.celular))){
                registros.push_back(atoi(r.celular));
                sort(registros.begin(), registros.end());
                gettimeofday(&actual,NULL);
                string regs = r.toString();
                cout << actual.tv_sec << endl;
                cout << actual.tv_usec << endl;
                regs += to_string(actual.tv_sec) + to_string(actual.tv_usec);
                output.write(regs.c_str(), regs.length());
                output.write("\n",1);
                output.flush();
                resp.sendReply((char *)&actual);
            }else{
            	cout << "Telefono ya registrado" << endl;
                resp.sendReply((char *)&actual);
            }
            output.close();
        }
        cout << endl;
    }
}