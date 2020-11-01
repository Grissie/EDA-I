//Librerias
#include <stdio.h>
#include <stdlib.h>//Para usar memoria dinamica
#include <string.h>//Para usar strcpy
#include <time.h>//Para administrar el tiempo
#include <math.h>//Para calcular las distancias entre dos lugares
#include <conio.h>//Para usar kbhit()
#include "estruFun.h"

//LUGAR
//Funciones basicas del lugar

void imprimirLugar(Lugar *aux) {
	printf("%s\t\t%lf\t%lf",aux->nombre,aux->x,aux->y);
}

void guardarLugares(Lugar *lista, int cantidad, char nombreArchivo[20]) {
	FILE *archivo = fopen(nombreArchivo,"rb");
	if (archivo==NULL) printf("\nError al abrir archivo Lugares");
	int i;
	for (i=0; i<cantidad; i++) {
		fread(lista+i,sizeof(Lugar),1,archivo);
	}
	fclose(archivo);
}

//ASIENTO
//Funciones basicas de un asiento

int ocuparAsiento(Asiento *asiento) {
	if (asiento->ocupado == 1) {
		return -1;
	} else {
		printf("\nIntroduzca el nombre del ocupante: ");
		scanf("%[^\n]s",asiento->ocupante);
		getchar();
		return 0;
	}
}


//AVION
//Funciones basicas del avion

void imprimirAvionSNombre(Avion *aux) {
	printf("%s\tCapacidad: %d",aux->tipo,aux->capacidad);
}

void imprimirAvion(Avion *aux) {
	printf("Avion %s\t%s",aux->nombre,aux->tipo);
}

void guardarAviones(Avion *lista, char nombreArchivo[20]) {
	FILE *archivo = fopen(nombreArchivo,"rb");
	if (archivo==NULL) printf("\nError al abrir archivo Aviones");
	int i;
	for (i=0; i<3; i++) {
		fread(lista+i,sizeof(Avion),1,archivo);
	}
	fclose(archivo);
}

void copiarAvion(Avion *nuevo, Avion *viejo) {
	strcpy(nuevo->tipo,viejo->tipo);
	nuevo->capacidad=viejo->capacidad;
}

void imprimirAsientos(Avion *aux) {
	int i,j,a,b,contador=0;
	if (aux->capacidad == 6) {
		a=1;
		b=6;
	} else if (aux->capacidad == 70) {
		a=10;
		b=7;
	} else {
		a=20;
		b=25;
	}
	for (i=0; i<a; i++) {
		printf("\n");
		for(j=0; j<b; j++) {
			printf("%d - ",contador);
			contador++;
		}
	}
}

void limpiarAsientos(Avion *aux) {
	int i;
	for (i=0; i<(aux->capacidad); i++) {
		(aux->asientos+i)->ocupado=0;
	}
}

void imprimirOcupante(Asiento *asiento) {
        printf("\n\t- %s",asiento->ocupante);
}

//PILOTO
//Funciones basicas del piloto

void imprimirPiloto(Piloto *aux) {
	printf("%s",aux->nombre);
}

void guardarPilotos(Piloto *lista, int cantidad, char nombreArchivo[20]) {
	FILE *archivo = fopen(nombreArchivo,"rb");
	if (archivo==NULL) printf("\nError al abrir archivo %s",nombreArchivo);
	int i;
	for (i=0; i<cantidad; i++) {
		fread(lista+i,sizeof(Piloto),1,archivo);
	}
	fclose(archivo);
}

//VUELO
//Funciones basicas del vuelo

int calcularDuracion(Lugar *origen, Lugar *destino) {
	double distancia=sqrt(pow(origen->x - destino->x,2)+pow(origen->y - destino->y,2));
	return (int) (distancia);
}

void imprimirVuelo(Vuelo *aux) {
	printf("De %s A %s\tAvion %s - %s",aux->origen->nombre,aux->destino->nombre,aux->avion->nombre,aux->avion->tipo);
}

//CONTROL AUTOMATICO
//Estas funciones le permiten a la computadora hacer una simulacion sin interaccion
//por parte del usuario

char alfabeto[]={'A','B','C','D','E','F'};

void asignarAvionesPilotos(Linea *linea1, Linea *linea2, Avion *listaAv, Piloto *listaPi) {
	srand(time(NULL));
	int i,aux;
	int pilotosOcupados[9];
	linea1->cantidadAviones=4;
	for(i=0; i<4; i++) {
		*(linea1->aviones+i)->nombre=alfabeto[i];
		copiarAvion(linea1->aviones+i,listaAv+(rand()%3));
		do {
			aux=rand()%9;
			*(linea1->pilotos+i)=*(listaPi+aux);
			if (pilotosOcupados[aux] == 1) break;
		} while(1);
		pilotosOcupados[aux]=1;
	}
	linea2->cantidadAviones=5;
	for(i=0; i<5; i++) {
		*(linea2->aviones+i)->nombre=alfabeto[i];
		copiarAvion(linea2->aviones+i,listaAv+(rand()%3));
		do {
			aux=rand()%9;
			*(linea2->pilotos+i)=*(listaPi+aux);
			if (pilotosOcupados[aux] == 1) break;
		} while (1);
		pilotosOcupados[aux]=1;
	}
}

int auxiliarGlobal=0;

int numAl(int lim) {
	srand(auxiliarGlobal+=1);
	return rand()%lim;
}

void crearVuelo(Vuelo *ap,Lugar *lugares) {
	ap->origen=ap->destino;
	do {
		ap->destino=lugares+numAl(9);
	} while (ap->destino==ap->origen);
	ap->duracion=calcularDuracion(ap->origen,ap->destino);
	ap->lugares=ap->avion->capacidad;
	limpiarAsientos(ap->avion);

	ap->despegue=0;
	time_t aux;
	struct tm *aux2;
	aux=time(NULL);
	aux2=localtime(&aux);
	aux2->tm_sec += 30;//30 segundos de descanso entre vuelo y vuelo
	ap->inicio=mktime(aux2);
	aux2->tm_sec += ap->duracion;//Se le asigna un tiempo de duracion de vuelo
	ap->fin=mktime(aux2);

}

void inicializarVuelos(Linea *linea,Lugar *lugares) {
	int i;
	for (i=0; i<linea->cantidadAviones; i++) {
		(linea->vuelos+i)->avion=linea->aviones+i;
		(linea->vuelos+i)->piloto=linea->pilotos+i;
		(linea->vuelos+i)->origen=lugares+0;
		(linea->vuelos+i)->destino=lugares+0;
		crearVuelo(linea->vuelos+i, lugares);
	}
}

void imprimirVuelos(Linea *l1, Linea *l2) {
	int i;
	time_t aux;
	aux = time(NULL);
	printf("\nHora local: %s\n\n",ctime(&aux));
	printf("\n\nLinea A");
	for (i=0; i<4; i++) {
		printf("\n");
		imprimirVuelo(l1->vuelos + i);
		if ((l1->vuelos+i)->despegue==0) {
			printf("  En espera");
			printf("   \t%.f",difftime((l1->vuelos + i)->inicio,time(NULL)));
		} else {
			printf("  En el aire");
			printf("   \t%.f",difftime((l1->vuelos + i)->fin,time(NULL)));
		}
	}
	printf("\n\nLinea B");
	for (i=0; i<5; i++) {
		printf("\n");
		imprimirVuelo(l2->vuelos + i);
		if ((l2->vuelos+i)->despegue==0) {
			printf("  En espera");
			printf("   \t%.f",difftime((l2->vuelos + i)->inicio,time(NULL)));
		} else {
			printf("  En el aire");
			printf("   \t%.f",difftime((l2->vuelos + i)->fin,time(NULL)));
		}
	}
}

void actualizarVuelo(Vuelo *aux, Lugar *lugares) {
	if (aux->despegue==0) {
		if (difftime(aux->inicio,time(NULL))<0) {
			aux->despegue=1;
		}
	} else {
		double auxT = difftime(aux->fin,time(NULL));
		if (auxT<0) {
			imprimirVuelo(aux);
			crearVuelo(aux,lugares);
		}
	}
}

void actualizarVuelos(Linea *l1, Linea *l2, Lugar *lugares) {
	int i;
	for (i=0; i<4; i++) {
		actualizarVuelo(l1->vuelos+i,lugares);
	}
	for (i=0; i<5; i++) {
		actualizarVuelo(l2->vuelos+i,lugares);
	}
}

void automatico(Linea *linea1, Linea *linea2, Lugar *lLugares) {
	while (1) {
		if (kbhit()) break;
		system("cls");
		printf("\n--");
		imprimirVuelos(linea1,linea2);
		actualizarVuelos(linea1,linea2,lLugares);
		printf("\n-");
	}
}

//CONTROL MANUAL
//Estas funciones le permiten al usuario realizar diversas acciones de administracion
//de manera manual

void imprimirPasajeros(Linea *linea1, Linea *linea2, Lugar *lugares) {
        char auxC;
        int auxI,i;
        Linea *auxL;
        Avion *auxA;
        actualizarVuelos(linea1, linea2, lugares);
        imprimirVuelos(linea1, linea2);
        do {
                getchar();
                printf("\nElija el nombre de la linea que le interesa (solo un caracter): ");
                scanf("%c",&auxC);
                printf("\nElija el numero de vuelo: ");
                scanf("%d",&auxI);
                if((auxC=='A' || auxC=='a') && (auxI<4)) {
                        auxL=linea1;
                        break;
                }
                if((auxC=='B' || auxC=='b') && (auxI<5)) {
                        auxL=linea2;
                        break;
                }
                printf("\nError al registrar el avion. Intente nuevamente.");
        } while(1);
        auxA=(auxL->vuelos+auxI)->avion;
        printf("\nEstos son los pasajeros:");
        for (i=0; i<(auxA->capacidad); i++) {
                if ((auxA->asientos+i)->ocupado == 1) imprimirOcupante(auxA->asientos+i);
        }
}


void ocuparAsiento2(Avion *avion, Piloto *piloto) {
	int aux;
	system("cls");
	printf("\nEl piloto del avion se llama %s",piloto->nombre);
	printf("\nEstos son los asientos del avion");
	imprimirAsientos(avion);
	do {
		printf("\nSeleccione el asiento de su preferencia: ");
		scanf("%d",&aux);
		if ((avion->asientos+aux)->ocupado == 0) {
			break;
		} else {
			printf("\nAsiento ocupado por %s",(avion->asientos+aux)->ocupante);
			printf("\nFavor de seleccionar otro asiento");
		}
	} while (1);
	getchar();
	printf("\nEl asiento se puede ocupar exitosamente\nPor favor, ingrese su nombre: ");
	scanf("%[^\n]s",(avion->asientos+aux)->ocupante);
	(avion->asientos+aux)->ocupado = 1;
}

void imprimirVuelos2(Linea *l1, Linea *l2) {
	int i;
	time_t aux;
	aux = time(NULL);
	printf("\nHora local: %s\n",ctime(&aux));
	printf("\nVUELOS DISPONIBLES");
	printf("\nNo.Vuelo  Tiempo\tVuelo");
	printf("\n\nLinea A");
	for (i=0; i<4; i++) {
		if ((l1->vuelos+i)->despegue == 0) {
			printf("\n%d",i+1);
			printf("\t%5.0f ",difftime((l1->vuelos + i)->inicio,time(NULL)));
			imprimirVuelo(l1->vuelos + i);
		}
	}
	printf("\n\nLinea B");
	for (i=0; i<5; i++) {
		if ((l2->vuelos+i)->despegue == 0) {
			printf("\n%d",i+1);
			printf("\t%5.0f ",difftime((l2->vuelos + i)->inicio,time(NULL)));
			imprimirVuelo(l2->vuelos + i);
		}
	}
}

void reservarVuelo(Linea *linea1, Linea *linea2, Lugar *lugares) {
	char auxC;
	int auxI;
	system("cls");
	actualizarVuelos(linea1, linea2, lugares);
	imprimirVuelos2(linea1,linea2);
	do {
		getchar();
		printf("\nElija el nombre de la linea que le interesa (solo un caracter): ");
		scanf("%c",&auxC);
		printf("\nElija el numero de vuelo: ");
		scanf("%d",&auxI);
		if((auxC=='A' || auxC=='a') && (auxI<4) && ((linea1->vuelos+auxI)->despegue==0)) {
			break;
		}
		if((auxC=='B' || auxC=='b') && (auxI<5) && ((linea2->vuelos+auxI)->despegue==0)) {
			break;
		}
		printf("\nError al registrar el avion. Intente nuevamente.");

	} while(1);
	if (auxC=='A' || auxC== 'a') ocuparAsiento2((linea1->vuelos+auxI)->avion,(linea1->vuelos+auxI)->piloto);
	if (auxC=='B' || auxC== 'b') ocuparAsiento2((linea2->vuelos+auxI)->avion,(linea2->vuelos+auxI)->piloto);
}

