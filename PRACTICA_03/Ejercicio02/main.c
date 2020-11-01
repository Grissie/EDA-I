#include <stdio.h>
#include "Leer.h"
#include "comparar.h"

int main()
{
    float A[10],B[10],C[10],D[10];
    int N[4];
    printf("Valores del arreglo A  \n");
    Leer(A,&N[0]);
    printf("Valores del arreglo B  \n");
    Leer(B,&N[1]);
    printf("Valores del arreglo C  \n");
    Leer(C,&N[2]);
    printf("Valores del arreglo D  \n");
    Leer(D,&N[3]);
    printf("\nLa suma de A + B  \n");
    comparar(N[0],N[1],A,B);
    printf("\nLa suma de A + C  \n");
    comparar(N[0],N[2],A,C);
    printf("\nLa suma de A + D  \n");
    comparar(N[0],N[3],A,D);
    printf("\nLa suma de B + C  \n");
    comparar(N[1],N[2],B,C);
    printf("\nLa suma de B + D  \n");
    comparar(N[1],N[3],B,D);
    printf("\nLa suma de C + D  \n");
    comparar(N[2],N[3],C,D);
    return 0;
}





