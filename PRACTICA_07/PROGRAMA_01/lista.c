#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "lista.h"

Lista *creaLista()
{
    Lista *q;
    q=(Lista *)malloc(sizeof(Lista));
    q->inicio=q->fin=NULL;
    return q;
}

void agregaNodo(Lista *lista,Nodo *nuevo)
{
    Nodo *p;
    if(lista->inicio == NULL)
    {
        lista->inicio=nuevo;
        lista->fin=nuevo;
        return;
    }
    if(strcmp(lista->inicio->nombre,nuevo->nombre)>0)
    {
        lista->inicio->anterior=nuevo;
        nuevo->siguiente=lista->inicio;
        lista->inicio=nuevo;
        return;
    }
    if(strcmp(lista->fin->nombre,nuevo->nombre)<0)
    {
        lista->fin->siguiente=nuevo;
        nuevo->anterior=lista->fin;
        lista->fin=nuevo;
        return;
    }
    p=lista->inicio;
    while(strcmp(p->nombre,nuevo->nombre)<0)
    {
        p=p->siguiente;
        nuevo->siguiente=p;
        nuevo->anterior=p->anterior;
        p->anterior->siguiente=nuevo;
        p->anterior=nuevo;
    }
}

Nodo *borraNodo(Lista *lista,char *nombre)
{
    Nodo *p;
    p=lista->inicio;
    while(p != NULL && (strcmp(p->nombre,nombre)!= 0))
    {
        p=p->siguiente;
        if(p == NULL)
            return NULL;
    }
    if(lista->inicio == lista->fin)
    {
        lista->inicio=NULL;
        lista->fin=NULL;
        return p;
    }
    if(p == lista->inicio)
    {
        lista->inicio=p->siguiente;
        lista->inicio->anterior=NULL;
        p->siguiente=NULL;
        return p;
    }
    p->anterior->siguiente=p->siguiente;
    p->siguiente->anterior=p->anterior;
    p->siguiente=NULL;
    p->anterior=NULL;
    return p;
}

Nodo *buscaNodo(Lista *lista,char *nombre)
{
    Nodo *p;
    p=lista->inicio;
    while(p != NULL && (strcmp(p->nombre,nombre)!= 0))
    {
        p=p->siguiente;
    }
    return p;
}

void imprimeLista(Lista *lista)
{
    Nodo *x;
    x=lista->inicio;
    if(x != NULL)
    {
        printf("\n\nLa lista es: \n");
        do
        {
            imprimeNodo(x);
            x=x->siguiente;
        }while(x != NULL);
    }
    else
    {
        printf("\n\nLa lista esta VACIA !");
    }
}
