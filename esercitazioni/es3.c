#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int fibonacci(int n);
int factorial(int n);

int main(){
    // printf("I primi 3 numeri di fibonacci corrispondono a %d",fibonacci(10));
    printf("FACTORIAL:\t%d", factorial(5));
    printf("\n");
    return 0;
}

// int fibonacci(int n){
//     Pila* p = pilaVuota();
//     for (int i = 0; i <= n; i++){
//         T x;
//         if(i == 0)

//         else if (i == 1)

//         else
//             x.a = i-2; x.b = i-1;
//         inPila(p,x);
//         n -= 1;
//     }
//     T x;
//     x.a = 0; x.b = 1;
//     inPila(p,x);
//     int res;
//     while(!estPilaVuota(p)){
//         printf("ITERAZIONE con res = %d\n", res);
//         res += outPila(p).a + outPila(p).b;
//     }
//     return res;
// }

int factorial(int n){
    Pila* p = pilaVuota();
    // for (int i = 0; i <= n; i++){
    //     T x;
    //     if (i == 0)
    //         x.a = 1;
    //     else
    //         x.a = i;
    //     inPila(p,x);
    // }
    T x; x.a = n;
    inPila(p, x);
    int ris = -1;
    while(!estPilaVuota(p)){
        T val;
        if (primoPila(p).a == 0){
            printf("caso base\n");
            outPila(p);
            ris = 1;
        }
        else if (primoPila(p).a > 0 && ris == -1){
            printf("caso ricorsivo\n");
            val.a = primoPila(p).a - 1;
            inPila(p, val);
        }
        else if (ris > 0){
            printf("caduta pila\n");
            ris *= outPila(p).a;
        }
    }
    return ris;
}