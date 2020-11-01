#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "nodo.h"

Tnodo2 *vender(TLista2 *Lista, char *nombre){
    Tnodo2 *p;
    int x,y;
    p=Lista->h;
    printf("\nElementos a comprar: ");
    scanf("%d", &x);
    do{
        if(strcmp(p->nombre, nombre)==0){
                if(p->existencia<x){
                    printf("Elementos insuficientes\n");
                    printf("\nOtra cantidad: ");
                    scanf("%d", &y);
                    p->existencia=(p->existencia)-y;
                    if(p->existencia==0)
                        borrarLista2(Lista, nombre);
                }
                if(p->existencia>=x){
                 p->existencia=(p->existencia)-x;
                 if(p->existencia==0)
                    borrarLista2(Lista, nombre);
                }
                return p;
        }else{
            p=p->sig;
        }
    }
      while(p!=NULL);
      return p;
}


void buscar(TLista2 *Lista, char *nombre){
    Tnodo2 *p;
    int x;
    p=Lista->h;
    do{
        if(strcmp(p->nombre, nombre)==0){
            imprime2(p);
            printf("\n  *** PRODUCTOS ***");
            printf("\n\t1->Producto siguiente\n\t2->Producto anterior\n\t3->Salir de la busqueda\n");
            scanf("%d", &x);
            switch(x){
            case 1:
                if(Lista->h==NULL){
                    printf("\nLa lista esta vacia\n");
                    break;
                }
                if(Lista->h==Lista->t){
                    printf("\nSolo hay un producto en la tienda\n");
                    break;
                }
                p=p->sig;
                printf("\nProducto siguiente: %s con %d existencias de precio: %2.f", p->nombre, p->existencia, p->precio);
                break;

            case 2:
                if(Lista->h==NULL){
                    printf("\nLa lista esta vacia\n");
                    break;
                }
                if(Lista->h==Lista->t){
                    printf("\nSolo hay un producto en la tienda\n");
                    break;
                }
                p=p->ant;
                printf("\nProducto anterior: %s con %d existencias de precio: %2.f", p->nombre, p->existencia, p->precio);
                break;

            case 3:
                break;
            }
            return;
        }
        else
            p=p->sig;
      }
      while(p!=NULL);
}



