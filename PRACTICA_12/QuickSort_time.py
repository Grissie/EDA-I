from time import time

def quicksort(lista,izq,der):
    i=izq
    j=der
    x=(lista[i ]+lista[j])/2

    while( i <= j ):
        while lista[i]<x and j<=der:
            i=i+1
        while x<lista[j] and j>izq:
            j=j-1
        if i<=j:
            aux = lista[i]; lista[i] = lista[j]; lista[j] = aux;
            i=i+1;  j=j-1;

        if izq < j:
            quicksort( lista, izq, j );
    if i < der:
        quicksort(lista,i,der);


def leeLista():
    lista=[]
    cn=int(input("Cantidad de numeros a ingresar: "))

    for i in range(0,cn):
        from random import randint
        lista.append(randint(0,1000))
    return lista

def main():
 print("Algoritmo QuickSort")
 print("1) Mejor caso")
 print("2) Peor caso")
 print("3) Caso aleatorio")
 z=int(input("Ingresa el caso: "))
 if(z==1):
     z=int(input("Cuantos numeros quieres generar"))
     A=list(range(0,z))
     print("Mejor caso(Lista ordenada)")
     print(A)
     tiempo_inicial= time()
     quicksort(A,0,len(A)-1)
     tiempo_final= time()
     print("Lista ordenada nuevamente")
     print(A)
     tiempo_ejecucion = tiempo_final - tiempo_inicial
     print("Tiempo de ejecucion", tiempo_ejecucion)
 elif(z==2):
     z=int(input("Cuantos numeros quieres generar"))
     A=list(range(0,z))
     A.reverse()
     print("Peor caso(Lista invertida)")
     print(A)
     print("Lista ordenada")
     tiempo_inicial= time()
     quicksort(A,0,len(A)-1)
     tiempo_final= time()
     print(A)
     tiempo_ejecucion = tiempo_final - tiempo_inicial
     print("Tiempo de ejecucion", tiempo_ejecucion)
 else:
     A=leeLista()
     print("Caso Aleatorio")
     print(A)
     tiempo_inicial= time()
     quicksort(A,0,len(A)-1)
     tiempo_final= time()
     print("Lista ordenada")
     print(A)
     tiempo_ejecucion = tiempo_final - tiempo_inicial
     print("Tiempo de ejecucion", tiempo_ejecucion)
 return



main()