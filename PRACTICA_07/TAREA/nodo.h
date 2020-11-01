#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
typedef struct Nodo
{
    char nombre[80];
    int edad;
    struct Nodo *sig;
    struct Nodo *ant;
} TNodo2;

TNodo2 *crearNodo();
void imprimirNodo(TNodo2 *);

#endif // NODO_H_INCLUDED
