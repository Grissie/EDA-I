#include <stdio.h>
#include <stdlib.h>
#include "estructura1.h"
#include "estructura2.h"
#include "crearCola.h"

TNodo *nuevoNodo(int n)
{
    TNodo *f;
    f=(TNodo *)malloc(sizeof(TNodo));
    f->num = n;
    f->sig = NULL;

    return f;
}



