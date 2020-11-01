#include <stdio.h>
#include "dameNumero.h"
#include "imprime.h"
#include "opera.h"

int main()
{
    int a,b,c;
    dameNumero(&a);
    dameNumero(&b);
    opera(a,b,&c);
    printf("La suma es: \n");
    imprime(c);
    return 0;
}
