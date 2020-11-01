#include <stdio.h>
int main(){
    int i=0,j=0,x=0,y=0;
    int suma1=0,suma2=0,suma3=0,suma4=0,suma5=0,suma6=0,suma7=0,suma8=0;
    int sumaA=0,sumaB=0,sumaC=0,sumaD=0,sumaE=0,sumaF=0,sumaG=0,sumaH=0;
    int cuadro[3][3]={{8,1,6},{3,5,7},{4,9,2}};
    int cuadro2[3][3] = {{8,3,6},{3,5,7},{4,9,2}};
    printf("\nEl cuadro introducido es: \n");
    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            printf("\t%d",cuadro[x][y]);
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
        for(j=2; j>=0; j--){
            if(j == 2-j){
                suma8 = suma8 + cuadro[i][j];
            }
        }
    }

    if(suma1 == suma2 && suma1 == suma3 && suma1 == suma4 && suma1 == suma5 && suma1 == suma6 && suma1 == suma7 && suma1 == suma8){
        printf("\nES un cuadro magico, ya que cada uno de sus renglones suman %d",suma1);
        printf("\ny cada una de sus columnas suman %d asi como sus",suma1);
        printf("\ndiagonales suman %d!",suma1);
    }
    printf("\n\nEl cuadro introducido es: \n");
    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            printf("\t%d",cuadro2[x][y]);
        }
        printf("\n");
    }

    i=0;
    for(j=0; j<3; j++){
        sumaA = sumaA + cuadro2[i][j];
    }

    i=i+1;
    for(j=0; j<3; j++){
        sumaB = sumaB + cuadro2[i][j];
    }

    i=i+1;
    for(j=0; j<3; j++){
        sumaC = sumaC +cuadro2[i][j];
    }

    j=0;
    for(i=0; i<3; i++){
        sumaD = sumaD + cuadro2[i][j];
    }

    j=j+1;
    for(i=0; i<3; i++){
        sumaE = sumaE + cuadro2[i][j];
    }

    j=j+1;
    for(i=0; i<3; i++){
        sumaF = sumaF + cuadro2[i][j];
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(i == j){
                sumaG = sumaG + cuadro2[i][j];
            }
        }
    }

    for(i=2; i>=0; i--){
        for(j=0; j<3; j++){
            if(j == 2-i){
                sumaH = sumaH + cuadro2[i][j];
            }
        }
    }

    printf("\nNO es un cuadro magico, ya que cada uno de sus renglones"
           "\nsuman %d,%d y %d, cada una de sus columnas suman"
           "\n %d,%d y %d, asi como sus diagonales suman %d y %d",
           sumaA,sumaB,sumaC,sumaD,sumaE,sumaF,sumaG,sumaH);
    printf("\n");
    return 0;
}
