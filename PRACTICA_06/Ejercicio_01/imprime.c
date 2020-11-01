#include <stdio.h>
#include <stdlib.h>
#include "estructura1.h"
#include "estructura2.h"
#include "crearCola.h"

void imprime(TCola *cola)
{
    int i;
    TCola r;
    r.h = NULL;
    r.t = NULL;
    i = 1;
    r.h = cola->h;
    if(r.h == NULL)
    {
        printf("No se encuentran elementos !");
        return;
    }
    else
    {
        do
        {
            printf("\n\tEl valor %d es: %d\n",i,r.h->num);
            i++;
            r.h = r.h->sig;
        }while(r.h != NULL);
    }
}
