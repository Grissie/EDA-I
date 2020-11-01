#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int clave;
    int cantidad;
    float precio;
}TProducto;

int main()
{
    TProducto A;
    TProducto *p = &A;
    p=(TProducto *)malloc(sizeof(TProducto));
    printf("\nClave del producto A ?:  ");
    scanf("%d",&((*p).clave));
    printf("\nCantidad de productos de A ?:  ");
    scanf("%d",&((*p).cantidad));
    printf("\nPrecio del producto A ?:  ");
    scanf("%f",&((*p).precio));
    printf("\n\nLa clave del producto A:  %d",((*p).clave));
    printf("\n\nLa cantidad del productos de A son: %d",((*p).cantidad));
    printf("\n\nEl precio del producto A es : $ %.2f",((*p).precio));
    printf("\n");
    return 0;
}


