#include <stdio.h>

int main()
{
  int arreglo[10]={1,3,10,-5,6,78,9,11,0,18};
  int opcion;
  int i;
  while(1){
    printf("\nIngrese un numero: ");
    scanf("%d",&opcion);
    if(opcion == -1)
      return 0;
    for(i=0; i<10; i++){
        if(arreglo[i] == opcion){
            printf("El numero %d esta en la posicion %d",opcion,i);
            break;
            }
    }
    if(i > 9)
        printf("El numero no existe !");
  }
}
