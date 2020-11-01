#ifndef lista_h
    #define lista_h
    #include "nodo.h"
    typedef struct
    {
        Nodo *inicio;
        Nodo *fin;
    }Lista;
    Lista *creaLista();
    void agregaNodo(Lista *,Nodo *);
    Nodo *borraNodo(Lista *,char *);
    void imprimeLista(Lista *);

#endif // lista_h
