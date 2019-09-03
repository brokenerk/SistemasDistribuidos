//g++ -std=c++11  E5.cpp -o E5 -lpthread
#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;
int valor = 0;

void decre(atomic<int> &globalv) {
    for (int i = 0; i < 10; i++) {
        globalv -= 1;
        cout << "Hilo: " << this_thread::get_id() << " ejecutando dec() el valor es= " << globalv << endl;
        sleep(1);
    }
}

void incre(atomic<int> &globalv) {
    for (int i = 0; i < 10; i++) {
        globalv += 1;
        cout << "Hilo: " << this_thread::get_id() << " ejecutando inc() el valor es= " << globalv << endl;
        sleep(1);
    }
}

int main() {
    atomic<int> globalv(0);
    thread th1(incre, ref(globalv)), th2(decre, ref(globalv));
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    cout << "el valor es:" << globalv << endl;
    exit(0);
}