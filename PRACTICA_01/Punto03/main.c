#include <stdio.h>

int main()
{
    int arreglo[10];
    int elementos;
    int i;

    while(1){
        printf("\nCuantos elementos desea guardar ?: ");
        scanf("%d",&elementos);
        if(elementos == -1)
            return 0;
        if(elementos < 10){
            printf("\nIngrese los valores: \n");
            for(i=0; i<elementos; i++){
                printf("Ingrese el valor en la posicion arreglo[%d]: ",i);
                scanf("%d",&arreglo[i]);
            }
       }
       if(elementos >  10){
        printf("\nNO es posible guardar todos esos numeros ! \n");
       }
    }
    return 0;
}

