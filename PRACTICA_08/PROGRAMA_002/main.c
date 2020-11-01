#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"
#include "buscar.h"

int main()
{
    int res;
    char nombre[30];
    Tnodo2 *nodo2, *nodoz;
    TLista2 *q;
    q=crearLista2();
    printf("\n\t\t      ***** ALMACEN DE PRODUCTOS *****\n");
    do{

        printf("\n\t1->Agregar un producto \n\t2->Listar productos");
        printf("\n\t3->Vender producto \n\t4->Buscar un producto \n\t5->Salir \nOpcion: ");
        scanf("%d", &res);
        switch(res){
        case 1:
                nodo2=crearNodo2();
                agregaLista2(q,nodo2);

                break;

            case 2:
               imprimirLista2(q);
               break;

            case 3:
                   if(q->h==NULL){
                      printf("\nLISTA VACIA");
                      break;
                   }
                   printf("\nProducto a comprar: ");
                   setbuf(stdin, NULL);
                   scanf("%[^\n]s", nombre);
                   nodoz=vender(q, nombre);
                   if(nodoz==NULL)
                      printf("\nNo se encontro en el almacen");
                   else
                      printf("\nSe vendio  %s y quedan %d existencias\n", nodoz->nombre, nodoz->existencia);
                break;

            case 4:
                if(q->h==NULL){
                    printf("\nLista VACIA");
                    break;
                }
                printf("\nProducto a buscar: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", nombre);
                buscar(q, nombre);
                break;

        }
    }while(res != 5);
    return 0;
}
