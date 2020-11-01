#include <stdio.h>

void imprime(int x,float *c,float *a,float*b)
{
    int i;
    for(i=0; i<x; i++)
    {
        printf("\n%.2f = %.2f + %.2f ",*(c+i),*(a+i),*(b+i));
    }
}
