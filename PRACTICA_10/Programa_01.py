def menu(opciones):
    while(True):
        for opcion in (opciones):
            print(opcion)
        op = int(input("Ingrese una opcion: "))
        if op in [1,2,3,4]:
            break
    return op

def agregar(x):
    y=int(input("Cuantos numeros quiere guardar ?: "))
    k=0
    while k<y:
        z=int(input("Numero a guardar: "))
        x.append(z)
        k=k+1

def listar(x):
    y=len(x)
    k=0
    while k<y:
        print("\t",x[k])
        k=k+1

def suma(x):
    y=len(x)
    k=0
    suma=0
    while k<y:
        suma=suma + x[k]
        k=k+1
    return suma

def main():
    x=[]
    while(True):
        opciones = ["1->Agregar numero","2->Listar","3->Sumar","4->Salir"]
        op = menu(opciones)
        print("Tu opcion es: "+str(op))
        if op == 1:
            agregar(x)
        elif op == 2:
            print("La lista es: ",end="\n")
            listar(x)
        elif op == 3:
            a=suma(x)
            print("La suma es: ",a)
        elif op == 4:
            print("Gracias por entrar al sistema, vuelva pronto")
            break

main ()
