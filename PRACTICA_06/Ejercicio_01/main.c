#include <stdio.h>
#include <stdlib.h>
#include "estructura1.h"
#include "estructura2.h"
#include "crearCola.h"
#include "nuevoNodo.h"
#include "agregaNodo.h"
#include "retiraNodo.h"
#include "imprime.h"

int main()
{
    int respuesta;
    int numero;
    TNodo *w;
    TCola *p;

    p=crearCola();
    do{
        printf("\n\t\t\tBIENVENIDO AL MENU  \n");
        printf("\nQue desea hacer ?:  \n\t1-> Agregar nodo  \n\t2->Borrar nodo  \n\t3->Listar los nodos \n");
        scanf("%d",&respuesta);

        switch(respuesta){
        case 1:
            {
                 printf("\nQue numero desea guardar ?: ");
                 scanf("%d",&numero);
                 w=nuevoNodo(numero);
                 agregaNodo(p,w);
                 break;
            }
        case 2:
            {
                retiraNodo(p);
                break;
            }
        case 3:
            {
                imprime(p);
                break;
            }
        }
    }while(respuesta != 4);

    return 0;
}
