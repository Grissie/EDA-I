#include <stdio.h>
#include "estructura1.h"
#include "estructura2.h"
#include "crearCola.h"

void agregaNodo(TCola *cola,TNodo *nodo)
{
    if(cola->h == NULL)
    {
        cola->h = nodo;
        cola->t = nodo;
    }
    else
    {
       (cola->t)->sig = nodo;
        cola->t = nodo;
    }
}


