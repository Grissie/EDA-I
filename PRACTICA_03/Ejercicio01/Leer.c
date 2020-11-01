#include <stdio.h>

void Leer(int *v, int *a, int *b)
{
    int i;
    printf("Cuantos valores desea guardar menor a 10?: \n");
    scanf("%d",a);
    printf("Ingrese la constante: \n");
    scanf("%d",b);

    for(i=0; i<*a; i++)
    {
        printf("Valor en [%d]: ",i);
        scanf("%d",v+i);
    }

}
