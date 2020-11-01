#include <stdio.h>

int main(){
    int i,j,x=0,y=0;
    int suma1=0,suma2=0,suma3=0,suma4=0,suma5=0,suma6=0,suma7=0,suma8=0;
    int cuadro[3][3];

    printf("\nIngrese los valores del cuadro magico: \n");
    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            printf("Valor en cuadro[%d][%d]: ",x,y);
            scanf("%d",&cuadro[x][y]);
        }
        printf("\n");
    }

    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            printf("%d\t",cuadro[x][y]);
        }
     printf("\n");
    }

    i=0;
    for(j=0; j<3; j++){
        suma1 = suma1 + cuadro[i][j];
    }

    i=i+1;
    for(j=0; j<3; j++){
        suma2 = suma2 + cuadro[i][j];
    }

    i=i+1;
    for(j=0; j<3; j++){
        suma3 = suma3 +cuadro[i][j];
    }

    j=0;
    for(i=0; i<3; i++){
        suma4 = suma4 + cuadro[i][j];
    }

    j=j+1;
    for(i=0; i<3; i++){
        suma5 = suma5 + cuadro[i][j];
    }

    j=j+1;
    for(i=0; i<3; i++){
        suma6 = suma6 + cuadro[i][j];
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(i == j){
                suma7 = suma7 + cuadro[i][j];
            }
        }
    }

    for(i=2; i>=0; i--){
        for(j=0; j<3; j++){
            if(j == 2-i){
                suma8 = suma8 + cuadro[i][j];
            }
        }
    }

    printf("\n");

    if(suma1 == suma2 && suma1 == suma3 && suma1 == suma4 && suma1 == suma5 && suma1 == suma6 && suma1 == suma7 && suma1 == suma8){
        printf("\nEl cuadro ingresado ES magico, ya que la suma tanto en reglones, columnas y \ndiagonales suman %d!",suma1);
    }
    else{
        printf("\nNO es un cuadro magico, ya que cada uno de sus renglones"
               "\nsuman %d,%d y %d, cada una de sus columnas suman"
               "\n %d,%d y %d, asi como sus diagonales suman %d y %d",
               suma1,suma2,suma3,suma4,suma5,suma6,suma7,suma8);
    }
    return 0;
}

