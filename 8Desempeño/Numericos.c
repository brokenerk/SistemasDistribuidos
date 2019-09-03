#include <math.h>
#include <stdio.h> 

int main(){
    int max = 1757600; 
    float seno,cose,tang,logn,raiz;
    int i = 0;
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