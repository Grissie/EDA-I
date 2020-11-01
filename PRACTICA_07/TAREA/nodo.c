#include<stdlib.h>
#include<stdio.h>
#include "nodo.h"
TNodo2 *crearNodo()
 {
    TNodo2 *q;
    q=(TNodo2*)malloc(sizeof(TNodo2));

    printf("Ingresa nombre:\n");
    scanf("%[^\n]s",q->nombre);
    printf("Ingresa edad:\n");
    scanf("%d",&q->edad);
    q->sig=q->ant=NULL;
    return q;
}

void imprimirNodo(TNodo2 *nodo)
{
    printf("%s\t\t%d\n",nodo->nombre,nodo->edad);
}
