#include <stdio.h>
#include <stdlib.h>
#define TAM 2
typedef struct
{
    int clave;
    int cantidad;
    float precio;
    float inversion;
}TProducto;

int main()
{
    int k;
    float inversionTotal = 0;
	TProducto A[TAM];
	for(k=0; k<TAM; k++)
	{
		printf("\n\nProducto %d  \n",k+1);
		printf("Clave: ");
		scanf("%d",&(A[k].clave));
		printf("Cantidad: ");
		scanf("%d",&(A[k].cantidad));
		printf("Precio: ");
		scanf("%f",&(A[k].precio));

		A[k].inversion = (A[k].cantidad)*(A[k].precio);
	}

	for(k=0; k<TAM; k++)
	{
		printf("\n\nProducto %d \n",k+1);
		printf("\nClave: %d",(A[k].clave));
		printf("\nCantidad: %d",(A[k].cantidad));
		printf("\nPrecio: $ %.2f",(A[k].precio));
		printf("\nInversion del producto: $ %.2f",(A[k].inversion));
	}
	for(k=0; k<TAM; k++)
	{
		inversionTotal = inversionTotal + (A[k].inversion);
	}
	printf("\n\nLa inversion total del inventario es:  $ %.2f",inversionTotal);
	printf("\n");
	return 0;
}
