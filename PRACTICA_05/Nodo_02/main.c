#include <stdio.h>
#include <stdlib.h>
#include "estructura.h"
#include "Lectura.h"
#include "Escritura.h"

int main()
{
    int respuesta;
    TNodo *p,*t,*h;
    h=lectura();
    t=h;
    p=h;
	do{
        printf("\nDesea guardar otro producto ? \n\t1 -> Si  \n\t2 -> No \n");
	    scanf("%d",&respuesta);
	    if(respuesta == 1){
	    	p=lectura();
	    	t->siguiente=p;
	    	t=p;
		}
		else{
            break;
		}
	}
	while(respuesta != 2);

    escritura(h);
    return 0;
}
