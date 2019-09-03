//g++ -std=c++11  E2.cpp -o E2 -lpthread
#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;
int valor = 0;

void decre() {
    for(int i=0;i<10;i++)
    {
	valor -= 1;
	printf("Hilo %ld ejecutando dec(). Valor: %d\n", this_thread::get_id(), valor);
	sleep(1);
    }
}

void incre()
{
    for(int i=0; i<10;i++)
    {
	valor += 1;
	printf("Hilo %ld ejecutando inc(). Valor: %d\n", this_thread::get_id(), valor);
    sleep(1);
    }
}

int main()
{
    thread th1(incre), th2(decre);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    printf("VALOR: %d\n", valor);
    exit(0);
}