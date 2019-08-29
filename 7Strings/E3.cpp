#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include <string>
using namespace std;
std::string random_string(std::size_t length);
int findAllOccurances(std::string data, std::string toSearch);

int main(int argc, const char **argv)
{
    cout << "Teclea n" << endl;
    int n = 0;
    cin >> n;
    auto t_start = std::chrono::high_resolution_clock::now();
    string cadena = "";
    for (int i = 0; i < n; i++)
    {
        cadena += random_string(3);
    }
    cout << findAllOccurances(cadena, "IPN") << endl;
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << elapsed_time_ms << " ms" << endl;
}

std::string random_string(std::size_t length)
{
    static const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    static std::default_random_engine rng(std::time(nullptr));
    static std::uniform_int_distribution<std::size_t> distribution(0, alphabet.size() - 1);
    std::string str;
    while (str.size() < length)
        str += alphabet[distribution(rng)];
    return str + " ";
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