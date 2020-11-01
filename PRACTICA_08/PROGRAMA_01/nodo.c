#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

Nodo *creaNodo()
{
    Nodo *p;
    p=(Nodo *)malloc(sizeof(Nodo));
    printf("\nNombre: ");
    fflush(stdin);
    scanf("%[^\n]s",p->nombre);
    printf("Edad: ");
    scanf("%d",&(p->edad));
    fflush(stdin);
    p->anterior=p->siguiente=NULL;
    return p;
}

void imprimeNodo(Nodo *nodo)
{
    printf("\n%s : %d anios",nodo->nombre,nodo->edad);
}


