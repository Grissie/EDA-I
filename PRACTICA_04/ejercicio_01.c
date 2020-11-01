#include <stdio.h>

typedef struct
{
    int clave;
    int cantidad;
    float precio;
}TProducto;

int main()
{
    TProducto A;
    printf("\nCual es la clave del producto A ?: ");
    scanf("%d",&A.clave);
    printf("\nCantidad de productos de A ?:  ");
    scanf("%d",&A.cantidad);
    printf("\nPrecio del producto A ?:  ");
    scanf("%f",&A.precio);

    printf("\n\nLa clave del producto A es: %d",A.clave);
    printf("\n\nLa cantidad de productos de A son: %d",A.cantidad);
    printf("\n\nEl precio del producto  A es: $ %.2f",A.precio);
    puts("\n");

    return 0;
}
