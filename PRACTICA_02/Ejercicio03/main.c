#include <stdio.h>
#include "dameNumero.h"
#include "imprime.h"
#include "opera.h"

int main()
{
    int a,b,c;
    a=dameNumero();
    b=dameNumero();
    c=opera(a,b);
    printf("La suma es: \n");
    imprime(c);
    return 0;
}
