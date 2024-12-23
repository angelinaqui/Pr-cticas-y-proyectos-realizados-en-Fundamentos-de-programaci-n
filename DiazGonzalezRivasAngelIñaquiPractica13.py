from time import process_time

n = int(input("¿Cuál será el tamaño de la secuencia de Fibonacci? "))
def iteracion(n):
    x = 0
    y = 1 
    for i in range(0,n):
        z = x+y
        x = y
        y = z
    return y

def recursividad(n):
    if n < 2:
        return n
    return recursividad(n-1) + recursividad(n-2)

def main():
    print("La sucesión de Fibonacci de forma iterativa")
    start = process_time()
    for j in range(n):
        print(iteracion(j))
    elapsed = process_time() - start
    print("El tiempo que tardo la forma iterativa es de ", elapsed )
    print("La sucesión de Fibonacci de forma recursiva")
    start = process_time()
    for k in range(n):
        print(recursividad(k))
    elapsed = process_time() - start
    print("El tiempo que tardo la forma recursiva es de ", elapsed )
main()