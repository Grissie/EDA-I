#include <stdio.h>
#include "estructura.h"

void escritura(TNodo *x)
{
    printf("\nLos producto almacenados son:  \n");
    do{
       printf("\n\nProducto  \n");
       printf("\nClave: %d",x->clave);
       printf("\nCantidad: %d",x->cantidad);
       printf("\nPrecio: $ %.2f",x->precio);
       printf("\nSucursal: %d",x->sucursal);
       x=x->siguiente;
    }while(x != NULL);
}


