#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

int main()
{
    int respuesta;
    char persona[30];
    Nodo *nuevo;
    Lista *cabeza;
    cabeza=creaLista();
    printf("\n\t\t\tBienvenido al menu");
    do
    {
        printf("\nQue desea hacer ?:  \n\t1->Agregar alemento  \n\t2->Borrar elemento \n\t3->Listar elementos");
        scanf("%d",&respuesta);
        switch(respuesta)
        {
        case 1:
            nuevo=creaNodo();
            agregaNodo(cabeza,nuevo);
            break;
        case 2:
            printf("\nA quien desea borrar: ");
            fflush(stdin);
            scanf("%s[^\n]",persona);
            borraNodo(cabeza,persona);
            break;
        case 3:
            imprimeLista(cabeza);
            break;
        }

    }while(respuesta != 4);

    return 0;
}
