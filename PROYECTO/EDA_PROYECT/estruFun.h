#ifndef ESTRUFUN_H_INCLUDED
#define ESTRUFUN_H_INCLUDED

//LUGAR
//Estructura y prototipo de funciones basicas del lugar

typedef struct {
	char nombre[25];
	double x,y;
} Lugar;

void imprimirLugar(Lugar *aux);
void guardarLugares(Lugar *lista, int cantidad, char nombreArchivo[20]);

//ASIENTO
//Estructura y prototipo de funciones basicas de un asiento

typedef struct {
	char ocupante[20];
	int ocupado;
} Asiento;

int ocuparAsiento(Asiento *asiento);

//AVION
//Estructura y prototipo de funciones basicas del avion

typedef struct {
	char nombre[2];
	char tipo[10];
	int capacidad;
	Asiento asientos[200];
} Avion;

void imprimirAvionSNombre(Avion *aux);
void imprimirAvion(Avion *aux);
void guardarAviones(Avion *lista, char nombreArchivo[20]);
void copiarAvion(Avion *nuevo, Avion *viejo);
void imprimirAsientos(Avion *aux);
void limpiarAsientos(Avion *aux);
void imprimirOcupante(Asiento *asiento);
//PILOTO
//Estructura y prototipo de funciones basicas del piloto

typedef struct {
	char nombre[25];
} Piloto;

void imprimirPiloto(Piloto *aux);
void guardarPilotos(Piloto *lista, int cantidad, char nombreArchivo[20]);
//VUELO
//Estructura y prototipo de funciones basicas del vuelo

typedef struct {
	Avion *avion;
	Piloto *piloto;
	int lugares;
	Lugar *origen;
	Lugar *destino;
	int duracion;
	time_t inicio;
	time_t fin;
	int despegue;//1: Si ya ha despegado 0: Si no ha despegado
} Vuelo;

int calcularDuracion(Lugar *origen, Lugar *destino);
void imprimirVuelo(Vuelo *aux);

//AEROLINEA
//Estructura y prototipo de funciones basicas de la aerolinea

typedef struct {
	char nombre;
	Avion aviones[5];
	Piloto pilotos[5];
	int cantidadAviones;
	Vuelo vuelos[5];
} Linea;

//CONTROL AUTOMATICO
//Estos prototipos de funciones le permiten a la computadora hacer una simulacion sin interaccion
//por parte del usuario

void asignarAvionesPilotos(Linea *linea1, Linea *linea2, Avion *listaAv, Piloto *listaPi);
//int auxiliarGlobal=0;
int numAl(int lim);
void crearVuelo(Vuelo *ap,Lugar *lugares);
void inicializarVuelos(Linea *linea,Lugar *lugares);
void imprimirVuelos(Linea *l1, Linea *l2);
void actualizarVuelo(Vuelo *aux, Lugar *lugares);
void actualizarVuelos(Linea *l1, Linea *l2, Lugar *lugares);
void automatico(Linea *linea1, Linea *linea2, Lugar *lLugares);
//CONTROL MANUAL
//Estos prototipos de funciones funciones le permiten al usuario realizar diversas acciones de administracion
//de manera manual
void imprimirPasajeros(Linea *linea1, Linea *linea2, Lugar *lugares);
void ocuparAsiento2(Avion *avion, Piloto *piloto);
void imprimirVuelos2(Linea *l1, Linea *l2);
void reservarVuelo(Linea *linea1, Linea *linea2, Lugar *lugares);
#endif // ESTRUCFUN_H_INCLUDED
