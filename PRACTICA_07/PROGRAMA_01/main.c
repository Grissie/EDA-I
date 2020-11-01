#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

int main()
{
    int respuesta;
    char persona[30];
    Nodo *nuevo;
    Nodo *B;
    Nodo *E;
    Lista *cabeza;
    cabeza=creaLista();
    printf("\n\t\t\tBienvenido al menu");
    do
    {
        printf("\nQue desea hacer ?:  \n\t1->Agregar elemento  \n\t2->Borrar elemento \n\t3->Buscar elemento \n\t4->Listar elementos  \n\t5->Salir \t\t\tOpcion: ");
        scanf("%d",&respuesta);
        switch(respuesta)
        {
        case 1:
            nuevo=creaNodo();
            agregaNodo(cabeza,nuevo);
            break;
        case 2:
            printf("\nA quien desea borrar ?: ");
            fflush(stdin);
            scanf("%[^\n]s",persona);
            B=borraNodo(cabeza,persona);
            printf("\nSe borro ha %s con %d anios",B->nombre,B->edad);
            break;
        case 3:
            printf("\nA quien desea buscar ?: ");
            fflush(stdin);
            scanf("%[^\n]s",persona);
            E=buscaNodo(cabeza,persona);
            if(E == NULL)
                printf("\nNo se encontro a la persona !");
            else
                printf("\nSe encontro a %s con %d anios",E->nombre,E->edad);
            break;
        case 4:
            imprimeLista(cabeza);
            break;
        }

    }while(respuesta != 5);

    return 0;
}
