//gcc Numericos.c -lm -o num1
#include <math.h>
#include <stdio.h> 

int main(){
    double max = 1757600.0; 
    double seno,cose,tang,logn,raiz;
    double i = 0.0;
    while(i < max){
        seno += sin(i);
        cose += cos(i);
        tang += tan(i);
        logn += log(i);
        raiz += sqrt(i);
        i++;
    }
    return 0;
}