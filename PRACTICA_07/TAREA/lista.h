#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"
typedef struct
{
    TNodo2 *h;
    TNodo2 *t;
} TLista2;

TLista2 *crearLista();
void agregarNodo(TLista2 *,TNodo2 *);
TNodo2 *borrarNodo(TLista2 *,char *);
void imprirLista(TLista2 *);

#endif // LISTA_H_INCLUDED
