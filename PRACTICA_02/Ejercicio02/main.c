#include <stdio.h>
/*Al colocar el main justo despues del archivo de encabezado, me marcaba warnings debido a que las funciones que se usan en
la funcion main no esta definidas, el compilador deja pasar esa alerta, ya que de alguna manera las declaraciones de las funciones
"dameNumero","opera" e "imprime"  estan implicitamente declaradas, para el correcto uso del codigo, justo despues de los archivos
de encabezado van los prototipos de las funciones, que comunmente se conocen como las declaraciones de las mismas*/

int dameNumero();
void imprime(int);
int opera(int, int);

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

int dameNumero()
{
    int x;
    printf("Dame un numero: ");
    scanf("%d",&x);
    return x;
}

void imprime(int valor)
{
    printf("Valor: %d",valor);
}

int opera(int a,int b)
{
    int res;
    res=a+b;
    return res;

}


