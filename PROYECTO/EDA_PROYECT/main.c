//Librerias
#include <stdio.h>
#include <stdlib.h>//Para usar memoria dinamica
#include <string.h>//Para usar strcpy
#include <time.h>//Para administrar el tiempo
#include <math.h>//Para calcular las distancias entre dos lugares
#include <conio.h>//Para usar kbhit()
#include "estruFun.h"

int menu()
{
	int opcion;
	printf("\n\t\t\t *** AEROPUERTO ***");
	printf("\n\t1->Visualizar en tiempo real los vuelos");
	printf("\n\t2->Reservar un asiento");
	printf("\n\t3->Ver los pasajeros de un vuelo");
	printf("\n\t4->Salir");
	while(1)
    {
		printf("\n\nElija la opcion de su preferencia: ");
		scanf("%d",&opcion);
		if (opcion<5 && opcion>0)
		{
			break;
		}
	}
	return opcion;
}
//MAIN
int main() {
    char Archivo2[20]="Aviones.bin\0";
    char Archivo3[20]="Pilotos.bin\0";
    char Archivo1[20]="Lugares.bin\0";

	Lugar listaLugares[10];
	Avion listaAviones[3];
	Piloto listaPilotos[10];
	Linea lineaA,lineaB;
	int opcion;

	guardarLugares(listaLugares,10,Archivo1);
	guardarAviones(listaAviones,Archivo2);
	guardarPilotos(listaPilotos,9,Archivo3);
	asignarAvionesPilotos(&lineaA,&lineaB,listaAviones,listaPilotos);
	inicializarVuelos(&lineaA,listaLugares);
	inicializarVuelos(&lineaB,listaLugares);

	while (1)
    {
		opcion=menu();
		system("cls");
		switch(opcion)
		{
			case 1:
				automatico(&lineaA, &lineaB, listaLugares);
				break;
			case 2:
				reservarVuelo(&lineaA, &lineaB, listaLugares);
				break;
			case 3:
				imprimirPasajeros(&lineaA, &lineaB, listaLugares);
				break;
			case 4:
				return 0;
				break;
		}
	}
	return 0;
}
