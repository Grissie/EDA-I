visitados = []
pila = []

def imprimir(Laberinto,Raton):
    print("+",end="")
    for c in range(len(Laberinto[0])):
        print("-",end="")
    print("+")
    for j in range(len(Laberinto)):
        print("|",end="")
        for k in range(len(Laberinto[0])):
            if([j,k]==Raton):
                print("R",end="")
            elif(Laberinto[j][k]==1):
                print(" ",end="")
            elif(Laberinto[j][k]==0):
                print("*",end="")
            elif(Laberinto[j][k]==2):
                print("Q",end="")
        print("|")
    print("+",end="")
    for c in range(len(Laberinto[0])):
        print("-",end="")
    print("+")
    return

def valida(pos,laberinto):
    r,c = pos
    if(r>=0 and r<len(laberinto) and c>=0 and c<len(laberinto[0])):
        if laberinto[r][c] != 0:
            return True
    return False

def getMov(raton,laberinto):
    r,c= raton
    if laberinto[r][c]==0:
        print("Posicion invalida del raton ",raton)
        exit(0)
    if laberinto[r][c]==2:
        return raton
    nuevo = [r-1,c]
    if valida(nuevo,laberinto) and nuevo not in visitados:
        return nuevo
    nuevo = [r,c+1]
    if valida(nuevo,laberinto) and nuevo not in visitados:
        return nuevo
    nuevo = [r+1,c]
    if valida(nuevo,laberinto) and nuevo not in visitados:
        return nuevo
    nuevo = [r,c-1]
    if valida(nuevo,laberinto) and nuevo not in visitados:
        return nuevo
    return []

def com(pos,laberinto):
    r,c = pos
    if pila==[]:
        return 3
    elif laberinto[r][c]==2:
        return 1
    return 0

def BackTrack(pos,laberinto):
    r = getMov(pos,laberinto)
    if r!=[]:
        visitados.append(r)
        pila.append(r)
    if r==[]:
        r = pila[len(pila)-2]
        del pila[len(pila)-1]
    return r

def main():
    laberinto=[[1,1,1,1,1,1],
               [1,0,0,0,0,1],
               [1,0,1,1,1,2],
               [0,1,1,0,0,0],
               [1,0,1,0,0,0]]
    raton=[1,0]
    g=0
    r=[]
    pila.append(raton)
    visitados.append(raton)
    imprimir(laberinto,raton)
    r=BackTrack(raton,laberinto)
    imprimir(laberinto,r)
    while g!=1 and g!=3:
        r=BackTrack(r,laberinto)
        g=com(r,laberinto)
        imprimir(laberinto,r)
    if g==1:
        print("\nFelicidades el Raton llego al Queso")
    elif g==3:
        print("\nEL Laberinto no tiene solucion, Raton muerto")
    return

main()