#include <stdio.h>
#include <stdlib.h>
#include "estructura.h"
#include "lectura.h"
#include "escritura.h"

int main()
{
    TNodo *p;
    p = lectura();
    escritura(p);
    return 0;
}
