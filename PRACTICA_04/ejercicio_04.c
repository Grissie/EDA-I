#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int clave;
    int cantidad;
    float precio;
    float inversion_producto;
}TProducto;

int main()
{
    int k;
    int n;
    float inversion_total=0;
    TProducto A;
    TProducto *p=&A;
    printf("\nCuantos productos deseas guardar: ");
    scanf("%d",&n);
    p=(TProducto *)malloc((sizeof (TProducto))*n);
    for(k=0; k<n; k++)
    {
        printf("\n\nProducto %d \n",k+1);
        printf("Clave:  ");
        scanf("%d",&((*(p+k)).clave));
        printf("Cantidad:  ");
        scanf("%d",&((*(p+k)).cantidad));
        printf("Precio:  ");
        scanf("%f",&((*(p+k)).precio));
        (*(p+k)).inversion_producto = (*(p+k)).cantidad*((*(p+k)).precio);
    }
    for(k=0; k<n; k++)
    {
        printf("\n\nProducto %d",k+1);
        printf("\nClave:  %d",(*(p+k)).clave);
        printf("\nCantidad: %d",(*(p+k)).cantidad);
        printf("\nPrecio: $ %.2f",(*(p+k)).precio);
        printf("\nInversion: $ %.2f",(*(p+k)).inversion_producto);
    }
    for(k=0; k<n; k++)
    {
        inversion_total = inversion_total +((*(p+k)).inversion_producto);
    }
    printf("\n\nLa inversion total: $ %.2f",inversion_total);
    printf("\n");
    return 0;
}
