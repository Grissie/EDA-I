#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo 
{
    char pasajero[50];
    int asiento;
    int ocupado; // 0 = desocupado, 1 = ocupado
    struct Nodo *sig;
    struct Nodo *ant;
} TAsiento;

typedef struct Avion
{
	char tipo[10];
	char destino[20];
    int asientos;
    int hora;
    char piloto[50];
    TAsiento *frente;
    TAsiento *atras;
} TAvion;

//-------------------------------

TAvion *crearAvion(void)
{
	TAvion *avion;
	
	avion = (TAvion *)malloc(sizeof(TAvion));
	if (avion)
	{
		avion->asientos = 0;
		avion->hora = 0;
		avion->frente = NULL;
		avion->atras = NULL;
	}

  return(avion);
}

//------------------------------

int insertar(TAvion *avion, int asiento)
{
	TAsiento *asientoNuevo;
	
	asientoNuevo = (TAsiento *)malloc(sizeof(TAsiento));
	if (!asientoNuevo)
		return(0);
		
	asientoNuevo->asiento = asiento;
	asientoNuevo->ocupado = 0;
	asientoNuevo->sig = NULL;
	asientoNuevo->ant = NULL;
	
	if (avion->asientos == 0)
		avion->frente = asientoNuevo;
	else 
	{
		avion->atras->sig = asientoNuevo;
		asientoNuevo->ant = avion->atras;
	}
	
	avion->atras = asientoNuevo;
	(avion->asientos)++;
	
	return(1);
}

//---------------------------------

TAvion *jetAvion()
{
	int i;
	TAvion *jet;
	
	jet = crearAvion();
	
	for(i = 0; i < 6; i++)
	{
		insertar(jet, i+1);
	}
	
	
	
	return jet;
}

//---------------------------

TAvion *airAvion()
{
	int i;
	TAvion *air;
	
	air = crearAvion();
	
	for(i = 0; i < 70; i++)
	{
		insertar(air, i+1);
	}
	
	return air;
}

TAvion *jumboAvion()
{
	int i;
	TAvion *jumbo;
	
	jumbo = crearAvion();
	
	for(i = 0; i < 500; i++)
	{
		insertar(jumbo, i+1);
	}
	
	return jumbo;
}

//--------------------------------

void imprimirAvion(TAvion *avion)
{
	TAsiento *tmp;
	int contador = 0;
	
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("**                                         **\n");
	printf("**                   CABINA                **\n");
	printf("**                                         **\n");
	printf("*********************************************\n");
	printf("*********************************************\n\n");
	
	printf("Piloto: %s\n\n", avion->piloto);
	
	printf("%c Disponible   %c Ocupado\n", 176, 219);
	
	
	printf("\n");
	if (avion->asientos == 0)
		printf("Avion lleno\n");
	else 
	{
		tmp = avion->frente;
		while (tmp != NULL)
		{
			contador++;
			
			if(tmp->ocupado == 0)
			{
				printf("%d -> %c   ",tmp->asiento, 176);
				if(contador == 2)
				{
					printf("            ");
				}
				if(contador > 3)
				{
					printf("\n\n");
					contador = 0;
				}
			}
			else
			{
				printf("%d -> %c   ",tmp->asiento, 219);
				if(contador == 2)
				{
					printf("            ");
				}
				if(contador > 3)
				{
					printf("\n\n");
					contador = 0;
				}
			}
			
			tmp = tmp->sig;
		}
	}
	printf("\n\n");
}

//-----------------------------------

void imprimirAsientosArchivo(TAvion *avion, char destinoLugares[])
{
	TAsiento *tmp;
	FILE *archivo;
	
	archivo = fopen(destinoLugares,"w+");
	
	if(archivo == NULL)
	{
		printf("No Existen Vuelos disponibles.\n");
	}
	else
	{
		if (avion->asientos == 0)
			printf("Avion lleno\n");
		else 
		{
			tmp = avion->frente;
			while (tmp != NULL)
			{	
				fprintf(archivo,"%d %d\n",tmp->asiento, tmp->ocupado);
				tmp = tmp->sig;
			}
		}
    }
    
    fclose(archivo);	
}

//----------------------------------

void asientos(TAvion *avion, char destino[])
{
	TAsiento *tmp;
	FILE *archivo;
	
	archivo = fopen(destino,"r");
	
	if (archivo == NULL)
		imprimirAsientosArchivo(avion, destino);
	else
	{
		tmp = avion->frente;
	    while (feof(archivo) == 0)
	    {
	        fscanf(archivo,"%d %d\n",&tmp->asiento, &tmp->ocupado);
	        tmp = tmp->sig;
	    }
	}
    
    fclose(archivo);
}

//----------------------------------

void vuelos(char destino[], int nVuelo)
{
	char tipo[10];
	int asientos, hora;
	FILE *archivo;

	if((archivo = fopen(destino,"r+")) == NULL)
	{
		printf("No Existen Vuelos disponibles.\n");
	}
	else
	{
        while (feof(archivo) == 0)
        {
            fscanf(archivo,"%30s %10s %d %d\n", destino, tipo, &asientos, &hora);
            printf("%d)\tTipo: %s \n\tAsientos: %d \n\tDestino: %s \n\tHora: %d\n\n\n", nVuelo, tipo, asientos, destino, hora);
        }
    }
    
    fclose(archivo);
    //imprimirAvion(avion);
}

//----------------------------------------

void misVuelos(TAvion *avion, char nombrePasajero[], int asientosPasajero)
{
	int i;
	int total;
	
	FILE *archivo;
	
	archivo = fopen("DatosPasajeros.txt","a");
	
	if((i = strcmp( avion->destino, "Monterrey" )) == 0)
		total = asientosPasajero * 1050;
		
	if((i = strcmp( avion->destino, "Guadalajara" )) == 0)
		total = asientosPasajero * 1120;
		
	if((i = strcmp( avion->destino, "Puebla" )) == 0)
		total = asientosPasajero * 880;
		
	if((i = strcmp( avion->destino, "Tijuana" )) == 0)
		total = asientosPasajero * 2320;
		
	if((i = strcmp( avion->destino, "Chicago" )) == 0)
		total = asientosPasajero * 4350;
		
	if((i = strcmp( avion->destino, "Lima" )) == 0)
		total = asientosPasajero * 10500;
		
	if((i = strcmp( avion->destino, "Berlin" )) == 0)
		total = asientosPasajero * 16800;
		
	if((i = strcmp( avion->destino, "Tokio" )) == 0)
		total = asientosPasajero * 27450;	
		
	if((i = strcmp( avion->destino, "Sidney" )) == 0)
		total = asientosPasajero * 31600;
	
	fprintf(archivo,"%s:%s:%s:%d:%d:%d:%s:\n", nombrePasajero, avion->tipo, avion->destino, avion->hora, asientosPasajero, total, avion->piloto);
	
	
	printf("\nTotal de compra: $ %d\n\n", total);
	system("pause");
	
	fclose(archivo);
}

//----------------------------------

void actualizarVuelos(TAvion *avion1, char destino[])
{
	FILE *archivo;
	
	archivo = fopen(destino,"w+");

	fprintf( archivo,"%s %s %d %d\n", avion1->destino, avion1->tipo, avion1->asientos, avion1->hora);
    
    fclose(archivo);
}

//-----------------------------------------


void reservarAsientos(TAvion *avion, char destino[])
{
	int nAsientos = 1;
	int asientoReservado = 0;
	int asientosPasajero = 0;
	int i = 0, car;
	char nombrePasajero[50];
	
	TAsiento *tmp;
	
	system("cls");
	asientos(avion, destino);
	imprimirAsientosArchivo(avion, destino);
	actualizarVuelos(avion, destino);
	imprimirAvion(avion);
	
	if(avion->asientos == 0)
	{
		printf("Avion lleno\n\n");
		system("pause");
		system("cls");
		return;
	}
	printf("A que nombre desea hacer su reservacion?: ");
	fflush(stdin);
	gets(nombrePasajero);
	
	while (nAsientos != -1)
	{
		printf("\nCuantos asientos desea reservar?: ");
		scanf("%d", &nAsientos);
		
		if(avion->asientos < nAsientos  || nAsientos < 1)
		{
			system("cls");
			printf("\nAsientos No validos\n\n");
			system("pause");
		}
		else
		{
			for (i = 1; i <= nAsientos; i++) 
			{
				system("cls");
				imprimirAvion(avion);
				
				printf("Que asientos desea reservar?\n\n");
				printf("Asiento: ");
				scanf("%d", &asientoReservado);
				
				tmp = avion->frente;
				while (tmp != NULL)
				{
					if(tmp->asiento == asientoReservado)
					{
						if (tmp->ocupado == 1)
						{
							printf("\n\nAsiento Ocupado\n\n");
							system("pause");
						}
						else
						{
							(avion->asientos)--;
							asientosPasajero++;
						}
					}
					tmp = tmp->sig;
			 	}

				
				tmp = avion->frente;
				while (tmp != NULL)
				{
					if(tmp->asiento == asientoReservado)
						tmp->ocupado = 1;
					tmp = tmp->sig;
				}
				
			}
			nAsientos = -1;
			system("cls");
			imprimirAvion(avion);
			system("Pause");
		}	
	}
	imprimirAsientosArchivo(avion, destino);
	misVuelos(avion, nombrePasajero, asientosPasajero);
}

//----------------------------------

void vuelosAerolinea1(TAvion *jet1, TAvion *jet2, TAvion *air1, TAvion *air2)
{
	char destino1[] = "Monterrey";
	char destino2[] = "Guadalajara";
	char destino3[] = "Puebla";
	char destino4[] = "Tijuana";
	
	char destinoA[] = "MonterreyAsientos";
	char destinoB[] = "GuadalajaraAsientos";
	char destinoC[] = "PueblaAsientos";
	char destinoD[] = "TijuanaAsientos";

	FILE *archivo;
	
	archivo = fopen(destino1,"r+");
	
	strcpy(jet1->destino, "Monterrey");
	strcpy(jet1->piloto, "Miguel Dominguez");
	strcpy(jet1->tipo, "Jet");
	jet1->hora = 1700;
	fscanf(archivo,"%30s %10s %d %d\n", jet1->destino, jet1->tipo, &jet1->asientos, &jet1->hora);
	asientos(jet1,destinoA);
	actualizarVuelos(jet1, destino1);
	vuelos(destino1, 1);
	
	fclose(archivo);
	
	archivo = fopen(destino2,"r+");
	
	strcpy(jet2->destino, "Guadalajara");
	strcpy(jet2->piloto, "Juan Pablo Jimenez");
	strcpy(jet2->tipo, "Jet");
	jet2->hora = 1300;
	fscanf(archivo,"%30s %10s %d %d\n", jet2->destino, jet2->tipo, &jet2->asientos, &jet2->hora);
	actualizarVuelos(jet2, destino2);
	vuelos(destino2, 2);
	
	fclose(archivo);
	
	archivo = fopen(destino3,"r+");
	
	strcpy(air1->destino, "Puebla");
	strcpy(air1->piloto, "Gustavo Muñoz");
	strcpy(air1->tipo, "Air");
	air1->hora = 900;
	fscanf(archivo,"%30s %10s %d %d\n", air1->destino, air1->tipo, &air1->asientos, &air1->hora);
	actualizarVuelos(air1, destino3);
	vuelos(destino3, 3);
	
	fclose(archivo);
	
	archivo = fopen(destino4,"r+");
	
	strcpy(air2->destino, "Tijuana");
	strcpy(air2->piloto, "Rafael Garcia");
	strcpy(air2->tipo, "Air");
	air2->hora = 2200;
	fscanf(archivo,"%30s %10s %d %d\n", air2->destino, air2->tipo, &air2->asientos, &air2->hora);
	actualizarVuelos(air2, destino4);
	vuelos(destino4, 4);
	
	fclose(archivo);
}

void vuelosAerolinea2(TAvion *jet1, TAvion *air1, TAvion *air2, TAvion *jumbo1, TAvion *jumbo2)
{
	char destino1[] = "Chigago";
	char destino2[] = "Lima";
	char destino3[] = "Berlin";
	char destino4[] = "Tokio";
	char destino5[] = "Sidney";
	
	char destinoA[] = "ChicagoAsientos";
	char destinoB[] = "LimaAsientos";
	char destinoC[] = "BerlinAsientos";
	char destinoD[] = "TokioAsientos";
	char destinoE[] = "SidneyAsientos";

	FILE *archivo;
	
	archivo = fopen(destino1,"r+");
	
	strcpy(jet1->destino, "Chicago");
	strcpy(jet1->piloto, "John Wayne");
	strcpy(jet1->tipo, "Jet");
	jet1->hora = 430;
	fscanf(archivo,"%30s %10s %d %d\n", jet1->destino, jet1->tipo, &jet1->asientos, &jet1->hora);
	asientos(jet1,destinoA);
	actualizarVuelos(jet1, destino1);
	vuelos(destino1, 1);
	
	fclose(archivo);
	
	archivo = fopen(destino2,"r+");
	
	strcpy(air1->destino, "Lima");
	strcpy(air1->piloto, "Sergio Leone");
	strcpy(air1->tipo, "Air");
	air1->hora = 1430;
	fscanf(archivo,"%30s %10s %d %d\n", air1->destino, air1->tipo, &air1->asientos, &air1->hora);
	actualizarVuelos(air1, destino2);
	vuelos(destino2, 2);
	
	fclose(archivo);
	
	archivo = fopen(destino3,"r+");
	
	strcpy(air2->destino, "Berlin");
	strcpy(air2->piloto, "Vicente Marquez");
	strcpy(air2->tipo, "Air");
	air2->hora = 900;
	fscanf(archivo,"%30s %10s %d %d\n", air2->destino, air2->tipo, &air2->asientos, &air2->hora);
	actualizarVuelos(air2, destino3);
	vuelos(destino3, 3);
	
	fclose(archivo);
	
	archivo = fopen(destino4,"r+");
	
	strcpy(jumbo1->destino, "Tokio");
	strcpy(jumbo1->piloto, "Francisco Hernandez");
	strcpy(jumbo1->tipo, "Jumbo");
	jumbo1->hora = 1800;
	fscanf(archivo,"%30s %10s %d %d\n", jumbo1->destino, jumbo1->tipo, &jumbo1->asientos, &jumbo1->hora);
	actualizarVuelos(jumbo1, destino4);
	vuelos(destino4, 4);
	
	fclose(archivo);
	
	archivo = fopen(destino5,"r+");
	
	strcpy(jumbo2->destino, "Sidney");
	strcpy(jumbo2->piloto, "Jack Daniels");
	strcpy(jumbo2->tipo, "Jumbo");
	jumbo2->hora = 1800;
	fscanf(archivo,"%30s %10s %d %d\n", jumbo2->destino, jumbo2->tipo, &jumbo2->asientos, &jumbo2->hora);
	actualizarVuelos(jumbo2, destino5);
	vuelos(destino5, 5);
	
	fclose(archivo);
}

//----------------------------------

void comprarBoletos1(TAvion *jet1, TAvion *jet2, TAvion *air1, TAvion *air2)
{
	int vuelo;
	
	char destino1[] = "Monterrey";
	char destino2[] = "Guadalajara";
	char destino3[] = "Puebla";
	char destino4[] = "Tijuana";
	
	char destinoA[] = "MonterreyAsientos";
	char destinoB[] = "GuadalajaraAsientos";
	char destinoC[] = "PueblaAsientos";
	char destinoD[] = "TijuanaAsientos";
	
	vuelosAerolinea1(jet1, jet2, air1, air2);
	
	printf("Precione 0 para regresar al menu anterior.\n\n");
	printf("Que destino desea: ");
	scanf("%d", &vuelo);
	
	switch (vuelo)
	{
		case 0:
			return;
		break;
		
		case 1:
			actualizarVuelos(jet1, destino1);
			reservarAsientos(jet1, destinoA);
			actualizarVuelos(jet1, destino1);
			imprimirAsientosArchivo(jet1, destinoA);
		break;
		
		case 2:
			actualizarVuelos(jet2, destino2);
			reservarAsientos(jet2, destinoB);
			actualizarVuelos(jet2, destino2);
			imprimirAsientosArchivo(jet2, destinoB);
		break;
		
		case 3:
			actualizarVuelos(air1, destino3);
			reservarAsientos(air1, destinoC);
			actualizarVuelos(air1, destino3);
			imprimirAsientosArchivo(air1, destinoC);
		break;
		
		case 4:
			actualizarVuelos(air2, destino4);
			reservarAsientos(air2, destinoD);
			actualizarVuelos(air2, destino4);
			imprimirAsientosArchivo(air2, destinoD);
		break;
		
		default:
			printf("\nOpcion no valida\n");
			system("cls");
		break;
	}
}

void comprarBoletos2(TAvion *jet1, TAvion *air1, TAvion *air2, TAvion *jumbo1, TAvion *jumbo2)
{
	int vuelo;
	
	char destino1[] = "Chigago";
	char destino2[] = "Lima";
	char destino3[] = "Berlin";
	char destino4[] = "Tokio";
	char destino5[] = "Sidney";
	
	char destinoA[] = "ChicagoAsientos";
	char destinoB[] = "LimaAsientos";
	char destinoC[] = "BerlinAsientos";
	char destinoD[] = "TokioAsientos";
	char destinoE[] = "SidneyAsientos";
	
	vuelosAerolinea2(jet1, air1, air2, jumbo1, jumbo2);
	
	printf("Precione 0 para regresar al menu anterior.\n\n");
	printf("Que destino desea: ");
	scanf("%d", &vuelo);
	
	switch (vuelo)
	{
		case 0:
			return;
		break;
		
		case 1:
			actualizarVuelos(jet1, destino1);
			reservarAsientos(jet1, destinoA);
			actualizarVuelos(jet1, destino1);
			imprimirAsientosArchivo(jet1, destinoA);
		break;
		
		case 2:
			actualizarVuelos(air1, destino2);
			reservarAsientos(air1, destinoB);
			actualizarVuelos(air1, destino2);
			imprimirAsientosArchivo(air1, destinoB);
		break;
		
		case 3:
			actualizarVuelos(air2, destino3);
			reservarAsientos(air2, destinoC);
			actualizarVuelos(air2, destino3);
			imprimirAsientosArchivo(air2, destinoC);
		break;
		
		case 4:
			actualizarVuelos(jumbo1, destino4);
			reservarAsientos(jumbo1, destinoD);
			actualizarVuelos(jumbo1, destino4);
			imprimirAsientosArchivo(jumbo1, destinoD);
		break;
			
		case 5:
			actualizarVuelos(jumbo2, destino5);
			reservarAsientos(jumbo2, destinoE);
			actualizarVuelos(jumbo2, destino5);
			imprimirAsientosArchivo(jumbo2, destinoE);
		break;
		
		default:
			printf("\nOpcion no valida\n");
			system("cls");
		break;
	}
}
//------------------------------------------

 void consultarViajes()
 {
 	char nombrePasajero[50];
 	char *buscarUsuario;
 	char cadena[200];
	char s2[2] = ":";
	char *ptr;
 	FILE *archivo;
 	
 	archivo = fopen("DatosPasajeros.txt", "r");
 	
 	system("cls");
 	
 	printf("Nombre a quien se hizo la reservacion: ");
 	fflush(stdin);
	gets(nombrePasajero);
	
	system("cls");
	
	printf("Estimado: %s\n\n", nombrePasajero);
	printf("Avion           Destino        Hora         No. Asientos        Total\n\n");
	
	while(!feof(archivo))
	{
		fgets(cadena,200,archivo);
		ptr = strtok(cadena,s2);
		buscarUsuario = strstr(cadena,nombrePasajero);
		
		if(buscarUsuario != NULL)
		{
			while( (ptr = strtok( NULL, s2 )) != NULL )
     			printf( "%s\t\t", ptr );
 	
		}
		
  	}
  	
  	 printf("<--- Piloto\n\n");	

  	system("pause");
 	
 }

//------------------------------------------

int aeroFer()
{
	int opcion = 0;
	TAvion *jet1, *air1, *jet2, *air2;
	
	jet1 = jetAvion();
	jet2 = jetAvion();
	air1 = airAvion();
	air2 = airAvion();
	
	
	while(opcion != 5)
	{
		system("cls");
	
		printf("\t*****************************************\n");
		printf("\t*  -----------------------------------  *\n");
		printf("\t* | ***  ***  ***  ***  ***  ***  *** | *\n");
		printf("\t* | * *  *    * *  * *  *    *    * * | *\n");
		printf("\t* | ***  ***  ***  * *  ***  ***  *** | *\n");
		printf("\t* | * *  *    **   * *  *    *    **  | *\n");
		printf("\t* | * *  ***  * *  ***  *    ***  * * | *\n");
		printf("\t*  -------------------------------------*\n");
		printf("\t*****************************************\n\n");
		
		printf("\t*****************************************\n");
		printf("\t*   VIAJES AL INTERIOR DE LA REPUBLICA  *\n");
		printf("\t*****************************************\n\n");
		
		printf("1) Vuelos\n");
		printf("2) Comprar Boletos\n");
		printf("3) Consultar mis viajes\n");
		printf("4) Regresar al menu anterior\n\n");
		
		printf("Eleccion: ");
		scanf("%d", &opcion);
		
		switch (opcion)
		{
			case 1:
				system("cls");
				vuelosAerolinea1(jet1, jet2, air1, air2);
				system("pause");
				
				system("cls");
			break;
				
			case 2:
				system("cls");
				comprarBoletos1(jet1, jet2, air1, air2);
			break;
			
			case 3:
				consultarViajes();
				return;
			break;
			
			case 4:
				return opcion;
			break;
			
			default:
				system("cls");
				printf("\nEsa no es una opcion, por favor eliga que hacer: \n\n");
				system("pause");
		}
	}	
}

int aeroDavid()
{
	int opcion = 0;
	TAvion *jet1, *air1, *air2, *jumbo1, *jumbo2;
	
	jet1 = jetAvion();
	air1 = airAvion();
	air2 = airAvion();
	jumbo1 = jumboAvion();
	jumbo2 = jumboAvion();
	
	
	while(opcion != 5)
	{
		system("cls");
	
		printf("\t*************************************************\n");
		printf("\t*  -------------------------------------------  *\n");
		printf("\t* | ***  ***  ***  ***  **   ***  * *  *  **  | *\n");
		printf("\t* | * *  *    * *  * *  * *  * *  * *  *  * * | *\n");
		printf("\t* | ***  ***  ***  * *  * *  ***  * *  *  * * | *\n");
		printf("\t* | * *  *    **   * *  * *  * *  * *  *  * * | *\n");
		printf("\t* | * *  ***  * *  ***  **   * *   *   *  **  | *\n");
		printf("\t*  -------------------------------------------  *\n");
		printf("\t*************************************************\n\n");
		
		printf("\t*****************************************\n");
		printf("\t*      VIAJES      INTERNACIONALES      *\n");
		printf("\t*****************************************\n\n");
		
		printf("1) Vuelos\n");
		printf("2) Comprar Boletos\n");
		printf("3) Consultar mis viajes\n");
		printf("4) Regresar al menu anterior\n\n");
		
		printf("Eleccion: ");
		scanf("%d", &opcion);
		
		switch (opcion)
		{
			case 1:
				system("cls");
				vuelosAerolinea2(jet1, air1, air2, jumbo1, jumbo2);
				system("pause");
				
				system("cls");
			break;
				
			case 2:
				system("cls");
				comprarBoletos2(jet1, air1, air2, jumbo1, jumbo2);
			break;
			
			case 3:
				consultarViajes();
				return;
			break;
			
			case 4:
				return opcion;
			break;
			
			default:
				system("cls");
				printf("\nEsa no es una opcion, por favor eliga que hacer: \n\n");
				system("pause");
		}
	}	
}
//--------------------------------

//---------------------------------

int main()
{
	int opcion = 0;
	
	while(opcion != 3)
	{
		system("cls");
		
		printf("\t********************************************************\n");
		printf("\t*  --------------------------------------------------  *\n");
		printf("\t* | ***  ***  ***  ***  ***  * *  ***  ***  ***  *** | *\n");
		printf("\t* | * *  *    * *  * *  * *  * *  *    * *   *   * * | *\n");
		printf("\t* | ***  ***  ***  * *  ***  * *  ***  ***   *   * * | *\n");
		printf("\t* | * *  *    **   * *  *    * *  *    **    *   * * | *\n");
		printf("\t* | * *  ***  * *  ***  *    ***  ***  * *   *   *** | *\n");
		printf("\t*  --------------------------------------------------  *\n");
		printf("\t********************************************************\n\n");
		
		printf("1) Aerofer\n");
		printf("2) Aerodavid\n");
		printf("3) Salir\n\n");
		
		printf("%cCon qu%c aerol%cnea desea viajar?\n",168, 130, 161);
		printf("Aerolinea: ");
		scanf("%d", &opcion);
		switch (opcion)
		{
			case 1:
				opcion = aeroFer();
			break;
			
			case 2:
				opcion = aeroDavid();
			break;
			
			case 3:
				system("cls");
				printf("\n****************************************************\n");
				printf("*  Agradecemos su visita. Lo estaremos esperando.  *\n");
				printf("****************************************************\n");
				exit(0);
			break;
			
			default:
				system("cls");
				printf("\nEsa no es una opcion, por favor elija que hacer: \n\n");
				system("pause");
		}
	}
	
	system("cls");
	printf("\n**************************************************\n");
	printf("**    Gracias  por visitarnos. Regresa pronto   **\n");
	printf("**************************************************\n\n");
			
	system("pause");
	return 0;
	
	return 0;
}
