#include <stdio.h>

int dameNumero()
{
    int x;
    printf("Dame un numero: ");
    scanf("%d",&x);
    return x;
}

void imprime(int valor)
{
    printf("El valor: %d",valor);
}

int opera(int a,int b)
{
    return a+b;
}

int main()
{
    int a,b,c;
    a=dameNumero();
    b=dameNumero();
    c=opera(b,a);
    printf("La suma es: \n");
    imprime(c);
    return 0;
}

