#include <stdio.h>

void imprime(int *v, int a)
{
    int i;
    for(i=0; i<a; i++){
        printf("\t%d",v[i]);
    }
}
