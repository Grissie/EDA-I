#include <stdio.h>
#include "estructura.h"

void escritura(TNodo *x)
{
    printf("\nClave del producto: %d",x->clave);
    printf("\nCantidad del producto: %d",x->cantidad);
    printf("\nPrecio del producto: $ %.2f",x->precio);
    printf("\nSucursal producto: %d",x->sucursal);
}
