#include <stdio.h>

void Leer(float *vector,int *n)
{
    int i;
    printf("Cuantos  valores menores a 10, desea guardar ?: ");
    scanf("%d",n);
    for(i=0; i<*n; i++)
    {
        scanf("%f",vector+i);
    }
}
