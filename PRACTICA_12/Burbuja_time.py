from time import time

def ordenamientoBurbuja(lista,tam):
    for i in range(1,tam):
        for j in range(0,tam-i):
            if(lista[j] > lista[j+1]):
                k = lista[j+1]
                lista[j+1] = lista[j]
                lista[j] = k;
    return lista

def leeLista(cn):
    lista=[]
    for i in range(0,cn):
        from random import randint
        lista.append(randint(0,cn))
    return lista

def main():

    lis=[]
    cn=int(input("Cantidad de numeros a ingresar: "))
    print("Que caso quieres realizar 1)Ordenado 2)Inverso 3)Aleatorio")
    tipo=int(input("Caso a realizar"))
    if tipo==1:
        print("Lista antes del ordenamiento")
        lis=list(range(0,cn))
        print(lis)
        tiempo_inicial= time()
        ordenamientoBurbuja(lis,len(lis))
        tiempo_final= time()
        print("Lista despues del ordenamiento")
        print(lis)
        tiempo_ejecucion = tiempo_final - tiempo_inicial
        print("Tiempo de ejecucion", tiempo_ejecucion)
    elif tipo==2:
        print("Lista antes del ordenamiento")
        lis=list(range(0,cn))
        lis.reverse()
        print(lis)
        tiempo_inicial= time()
        ordenamientoBurbuja(lis,len(lis))
        tiempo_final= time()
        print("Lista despues del ordenamiento")
        print(lis)
        tiempo_ejecucion = tiempo_final - tiempo_inicial
        print("Tiempo de ejecucion", tiempo_ejecucion)
    elif tipo==3:
        print("Lista antes del ordenamiento")
        lis=leeLista(cn)
        print(lis)
        tiempo_inicial= time()
        ordenamientoBurbuja(lis,len(lis))
        tiempo_final= time()
        print("Lista despues del ordenamiento")
        print(lis)
        tiempo_ejecucion = tiempo_final - tiempo_inicial
        print("Tiempo de ejecucion", tiempo_ejecucion)

main()