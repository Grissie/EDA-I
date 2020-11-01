#include <stdio.h>
#include "Leer.h"
#include "suma.h"
#include "imprime.h"

int main()
{
    int v[10];
    int a;
    int b;
    Leer(v,&a,&b);
    suma(v,a,b);
    imprime(v,a);

    return 0;
}
