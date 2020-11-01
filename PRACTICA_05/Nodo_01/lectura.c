#include <stdio.h>
#include <stdlib.h>
#include "estructura.h"

TNodo *lectura()
{
    TNodo *q;
    q = (TNodo *)malloc(sizeof(TNodo));
    printf("\nClave del producto: ");
    scanf("%d",&(q->clave));
    printf("Cantidad de producto: ");
    scanf("%d",&(q->cantidad));
    printf("Precio del producto: ");
    scanf("%f",&(q->precio));
    printf("Sucursal del producto: ");
    scanf("%d",&(q->sucursal));
    q->sig = NULL;
    return q;
}
