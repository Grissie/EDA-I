from time import time
def main():
 print("Algoritmo Insercion Directa")
 print("1) Mejor caso")
 print("2) Peor caso")
 print("3) Caso aleatorio")
 z=int(input("Ingresa el caso: "))
 if(z==1):
     x=[]
     y=int(input("Cuantos numeros quieres generar:"))
     x=list(range(y))
     print("Mejor caso(Lista ordenada)")
     print(x)
     tiempo_inicial= time()
     insercionDirecta(x,len(x))
     tiempo_final= time()
     print("Lista ordenada nuevamente")
     print(x)
     tiempo_ejecucion = tiempo_final - tiempo_inicial
     print("Tiempo de ejecucion", tiempo_ejecucion)
 elif(z==2):
     z=[]
     y=int(input("Cuantos numeros quieres generar:"))
     z=list(range(0,y))
     z.reverse()
     print("Peor caso(Lista invertida)")
     print(z)
     print("Lista ordenada")
     tiempo_inicial= time()
     insercionDirecta(z,len(z))
     tiempo_final= time()
     print(z)
     tiempo_ejecucion = tiempo_final - tiempo_inicial
     print("Tiempo de ejecucion", tiempo_ejecucion)
 else:
     A=leeLista()
     print("Caso Aleatorio")
     print(A)
     tiempo_inicial= time()
     insercionDirecta(A,len(A))
     tiempo_final= time()
     print("Lista ordenada")
     print(A)
     tiempo_ejecucion = tiempo_final - tiempo_inicial
     print("Tiempo de ejecucion", tiempo_ejecucion)
 return



main()