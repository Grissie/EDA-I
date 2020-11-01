#ifndef NODO2_H_INCLUDED
#define NODO2_H_INCLUDED

typedef struct nodo2{
    char nombre[30];
    float precio;
    int existencia;
    struct nodo2 *sig;
    struct nodo2 *ant;
}Tnodo2;
Tnodo2 *crearNodo2();
void imprime2(Tnodo2 *nodo);

#endif // NODO2_H_INCLUDED

