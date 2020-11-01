#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

Tnodo2 *crearNodo2(){
    Tnodo2 *p;
    p=(Tnodo2 *)malloc(sizeof(Tnodo2));
    p->sig=p->ant=NULL;
    printf("\nNombre del producto: ");
    setbuf(stdin ,NULL);
    scanf("%[^\n]s", p->nombre);
    printf("Precio: ");
    setbuf(stdin, NULL);
    scanf("%f", &(p->precio));
    printf("Existencias: ");
    setbuf(stdin, NULL);
    scanf("%d", &(p->existencia));
    return p;
}
void imprime2(Tnodo2 *nodo){
    printf("\n%s\tcantidad: %d\t$%2.f", nodo->nombre, nodo->existencia, nodo->precio);
}
