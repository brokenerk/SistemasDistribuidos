#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    Respuesta resp(7200);
    struct mensaje * mensaje;
    while (true)
    {
        mensaje = resp.getRequest();
        //char * info="A";
        //resp.sendReply(info);
    }
}