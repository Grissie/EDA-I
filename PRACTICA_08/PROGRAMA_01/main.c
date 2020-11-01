#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

int main()
{
    int respuesta;
    char persona[30];
    Nodo *nuevo;
    Nodo *personaborrada;
    Nodo *personaencontrada;
    Lista *cabeza;
    cabeza=creaLista();
    printf("\n\t\t\tBienvenido al menu");
    do
    {
        printf("\nQue desea hacer ?:  \n\t1->Agregar alemento  \n\t2->Borrar elemento  \n\t3->Buscar elemento\n\t4->Listar elementos \n\t5->Salir \nOpcion: ");
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
            scanf("%[^\n]s",persona);
            personaborrada=borraNodo(cabeza,persona);
            printf("\nSe borro ha: %s con %d anios",personaborrada->nombre,personaborrada->edad);
            break;
        case 3:
            printf("\nA quien desea buscar: ");
            fflush(stdin);
            scanf("%[^\n]s",persona);
            personaencontrada=buscaNodo(cabeza,persona);
            if(personaencontrada == NULL)
                printf("\nPersona no encontrada !");
            else
                printf("\nSe encontro ha: %s con %d anios",personaencontrada->nombre,personaencontrada->edad);
            break;
        case 4:
            imprimeLista(cabeza);
            break;
        }

    }while(respuesta != 5);

    return 0;
}
