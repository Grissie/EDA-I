#include <stdio.h>
#include <stdlib.h>
#include "estructura1.h"
#include "estructura2.h"
#include "crearCola.h"

TCola *crearCola()
{
    TCola *g;
    g =(TCola*)malloc(sizeof(TCola));
    g->h=NULL;
    g->t=NULL;

    return g;
}





