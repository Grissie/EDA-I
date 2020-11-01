#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
#include "nodo.h"

typedef struct{
    Tnodo2 *h, *t;
}TLista2;


TLista2 *crearLista2();
void agregaLista2(TLista2 *Lista,Tnodo2 *nodo);
Tnodo2 *borrarLista2(TLista2 *Lista, char *nombre);
void imprimirLista2(TLista2 *Lista);


#endif // LISTA2_H_INCLUDED

