#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "lista.h"
#include "nodo.h"
TLista2 *crearLista()
{
    TLista2 *lista;
    lista=(TLista2*)malloc(sizeof(TLista2));
    lista->h=NULL;
    lista->t=NULL;
    return lista;
}

void agregarNodo(TLista2 *lista,TNodo2 *nodo)
{
    TNodo2 *p;
    if(lista->h==NULL)
    {
        lista->h=nodo;
        lista->t=nodo;
        return ;
    }
    if((strcmp(lista->h->nombre,nodo->nombre)>0))
    {
        lista->h->ant=nodo;
        nodo->sig=lista->h;
        lista->h=nodo;
        return ;
    }
    if(strcmp(lista->t->nombre,nodo->nombre)<0)
    {
        lista->t->sig=nodo;
        nodo->ant=lista->t;
        lista->t=nodo;
        return;
    }
    p=lista->h;
    while(strcmp(p->nombre,nodo->nombre)<0)
    {
        p=p->sig;
        nodo->sig=p;
        nodo->ant=p->ant;
        p->ant->sig=nodo;
        p->ant=nodo;
    }
}

TNodo2 *borrarNodo(TLista2 *lista,char *nombre)
{
    TNodo2 *p;
    p=lista->h;
    while((p!=NULL)&&(strcmp(p->nombre,nombre)!=0))
        p=p->sig;
    if(p==NULL)
        return NULL;
    if(p==lista->h)
    {
        lista->h=p->sig;
        lista->h->ant=NULL;
        p->sig=NULL;
        return p;
    }


    if(lista->h==lista->t)
    {
        lista->h=NULL;
        lista->t=NULL;
        return p;
    }

    if(p==lista->t)
    {
        lista->t=p->ant;
        lista->t->sig=NULL;
        p->ant=NULL;
        return p;
    }
    (p->ant)->sig=p->sig;
    (p->sig)->ant=p->ant;
    p->sig=NULL;
    p->ant=NULL;
    return p;
}

void imprirLista(TLista2 *lista)
{
    TNodo2 *p;
    if(lista->h==NULL)
    {
        printf("Lista vacia");
    }
    p=lista->h;
    do
    {
        imprimirNodo(p);
        p=p->sig;
    }
    while(p!=NULL);

}
