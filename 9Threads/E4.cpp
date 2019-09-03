//g++ -std=c++11  E4.cpp -o E4 -lpthread
#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;

int valor = 0;
atomic<int> globalv(0);

void decre() {
    for (int i = 0; i < 10; i++) {
        globalv -= 1;
        cout << "Hilo: " << this_thread::get_id() << " ejecutando inc() el valor es= " << globalv << endl;
        sleep(1);
    }
}

void incre() {
    for (int i = 0; i < 10; i++) {
        globalv += 1;
        cout << "Hilo: " << this_thread::get_id() << " ejecutando inc() el valor es= " << globalv << endl;
        sleep(1);
    }
}

int main() {
    thread th1(incre), th2(decre);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    cout << "El hilo principal termina\n";
    cout << "el valor es" << globalv << endl;
    exit(0);
}