#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

int main()
{
    int opcion;
    char nombre[30];
    TNodo2 *nuevo,*borrado;
    TLista2 *cabeza;
    cabeza=crearLista();
    printf("\n\t\t\Bienvenido al menu");
    do
    {
        printf("\nElija una opcion: ");
        printf("\n\t1->Agregar persona \n\t2->Borrar persona \n\t3->Listar personas \n\t4->Salir");
        printf("\nOpcion: ");
        scanf("%d",&opcion);
        setbuf(stdin,NULL);
        switch(opcion)
        {
        case 1:
            nuevo=crearNodo();
            agregarNodo(cabeza,nuevo);
            break;
        case 2:
            printf("\nPersona ha borrar: ");
            fflush(stdin);
            scanf("%[^\n]s",nombre);
            borrado=borrarNodo(cabeza,nombre);
            if(borrado == NULL)
                printf("\nNo se encontro a la persona");
            else
                printf("\nSe borro ha: %s",borrado->nombre);
            break;
        case 3:
            imprirLista(cabeza);
            break;
        }
    }while(opcion != 4);

    return 0;
}
