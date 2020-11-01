#include <stdio.h>
#include <stdlib.h>
#include "estructura1.h"
#include "estructura2.h"
#include "crearCola.h"

TNodo *retiraNodo(TCola *cola)
{
    TCola y;
    y.h = NULL;
    y.t = NULL;

    if(cola->h==NULL)
    {
        return NULL;
    }
    if(cola->h == cola->t)
    {
        y.h = cola->h;
        cola->h = NULL;
        cola->t = NULL;
        return y.h;
    }
    else
    {
        y.h=cola->h;
        cola->h=cola->h->sig;
        y.h->sig=NULL;
        return y.h;
    }

    return 0;
}
