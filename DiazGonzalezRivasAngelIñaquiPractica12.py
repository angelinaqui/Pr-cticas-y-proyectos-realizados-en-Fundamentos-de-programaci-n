from re import L
from random import choice
from time import process_time
from string import ascii_lowercase
n = int(input("¿Cuál será el tamaño de la lista? "))
def aleatorio():
    Lista = []
    for l in range(1,n):
        palabra = ""
        for i in range(0,4):
            letras = ["a","b", "c", "d", "e","d","f","g","h","i","j","k","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"]
            letra = choice(letras)
            palabra = palabra + letra
        Lista.append(palabra)
    return Lista
def main():
    Lista = aleatorio()
    buscar = input("Por favor, escriba una palabra de cuatro letras ")
    for l in range(1,n):
        start = process_time()
        if buscar in Lista:
            elapsed = process_time() - start
            print("Se encontro ", buscar, " en la lista", sep= '')
            print("El tiempo que tardo en encontralo es de ", elapsed )
            break
        else:
            print("No se encontro ", buscar, " en la lista", sep = '')
            break
main()