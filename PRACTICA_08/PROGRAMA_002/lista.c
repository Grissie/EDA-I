#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "lista.h"

TLista2 *crearLista2(){
    TLista2 *Lista;
    Lista=(TLista2 *)malloc(sizeof(TLista2));
    Lista->h=Lista->t=NULL;
    return Lista;
}

Tnodo2 *borrarLista2(TLista2 *Lista, char *nombre){
    Tnodo2 *p;
    p=Lista->h;
    while((p!=NULL)&&(strcmp(p->nombre, nombre)!=0))
        p=p->sig;
    if(p==NULL)
        return NULL;
    if(Lista->h==Lista->t){
        Lista->h=NULL;
        Lista->t=NULL;
        return p;
    }
    if(p==Lista->h){
        Lista->h=p->sig;
        Lista->h->ant=NULL;
        p->sig=NULL;
        return p;
    }
    if(p==Lista->t){
        Lista->t=p->ant;
        Lista->t->sig=NULL;
        p->ant=NULL;
        return p;
    }
    p->ant->sig=p->sig;
    p->sig->ant=p->ant;
    p->sig=NULL;
    p->ant=NULL;
    return p;
}
void imprimirLista2(TLista2 *Lista){

    Tnodo2 *p;
    printf("\nProductos del almacen");
    if(Lista->h==NULL)
        printf("  Lista vacia\n");
    else{
        p=Lista->h;
        printf("\nProducto         Existencia          Precio\n");
        do{

            printf("%s             %d             %.2f\n", p->nombre, p->existencia, p->precio);
            p=p->sig;
        }while(p!=NULL);
    }
}

void agregaLista2(TLista2 *Lista, Tnodo2 *nuevo){
    Tnodo2 *p;
    if(Lista->h==NULL){
        Lista->h=nuevo;
        Lista->t=nuevo;
        return;
    }
    if((strcmp(Lista->h->nombre, nuevo->nombre)>0)){
        Lista->h->ant=nuevo;
        nuevo->sig=Lista->h;
        Lista->h=nuevo;
        return;
    }
    if((strcmp(Lista->t->nombre, nuevo->nombre)<0)){
        Lista->t->sig=nuevo;
        nuevo->ant=Lista->t;
        Lista->t=nuevo;
        return;
    }
    p=Lista->h;
    while(strcmp(p->nombre, nuevo->nombre)<0){
        p=p->sig;
    nuevo->sig=p;
    nuevo->ant=p->ant;
    p->ant->sig=nuevo;
    p->ant=nuevo;
    }
}

