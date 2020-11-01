#include <stdio.h>
#include "suma.h"
#include "imprime.h"

void comparar(int n1,int n2,float *x,float *y)
{
    int i;
    float E[10];
    if(n1 == n2)
    {
        printf("La suma es  \n");
        suma(n1,x,y,E);
        imprime(n1,E,x,y);

    }
    else
    {
        printf("\nNO SE PUEDEN SUMAR LOS VECTORES"
               "\nYA QUE TIENEN DIFERENTE DIMENSION !");
    }
}
