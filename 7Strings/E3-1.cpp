#include <iostream>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <random>
#include <string.h>
using namespace std;
int random(int max);
char *random_string();
int findAllOccurances(std::string data, std::string toSearch);

int main(int argc, const char **argv)
{
    cout << "Teclea n" << endl;
    int n = 0;
    cin >> n;
    auto t_start = std::chrono::high_resolution_clock::now();
    char *cadenota = NULL;
    for (int i = 0; i < n; i++)
    {
        cadenota = (char *)realloc(cadenota, i * 4 + 4);
        strcat(cadenota, (char *)random_string());
    }
    cout << cadenota << endl;
    //cout << findAllOccurances(cadenota, "IPN") << endl;
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << elapsed_time_ms << " ms" << endl;
}

char *random_string()
{
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    char *cadena = "";
    for (int i = 0; i < 3; i++)
    {
        cadena = (char *)realloc(cadena, strlen(cadena) + 1);
        char caracter = alphabet[random(25)];
        memcpy(cadena, &caracter, strlen(cadena) + 1);
    }
    cout << cadena << endl;
    return cadena;
}

int findAllOccurances(std::string data, std::string toSearch)
{
    int i = 0;
    size_t pos = data.find(toSearch);
    while (pos != std::string::npos)
    {
        pos = data.find(toSearch, pos + toSearch.size());
        i++;
    }
    return i;
}

int random(int max)
{
    return rand() % (max + 1 - 0) + 0;
}