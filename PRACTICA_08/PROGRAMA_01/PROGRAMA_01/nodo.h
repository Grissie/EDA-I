#ifndef  nodo_h
    #define nodo_h
    typedef struct nodo
    {
        char nombre[30];
        int edad;
        struct nodo *anterior;
        struct nodo *siguiente;
    }Nodo;
    Nodo *creaNodo();
    void imprimeNodo(Nodo *);
#endif // nodo_h

