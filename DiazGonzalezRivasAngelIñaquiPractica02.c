//Arreglos ordenados
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#define LONG_ARR 1000
// delcaración de funciones
int insertar(int dato);
int busquedaBinaria(int dato);
void desplegarArreglo();
int getUnRandom();
//variables globales
int arreglo[LONG_ARR];
int numElems = 0;
// inicio
int main(){
    setlocale(LC_ALL, "");
    srand((unsigned)time(0));
    int numero, encontrado, generado;
    int repetidos = 0;
    printf("Teclee el número de elementos en el arreglo (menor a 1000)\n");
    scanf("%d", &numero);
    numElems = numero;
    for (int i=0; i< numElems; i++){
        arreglo[i] = getUnRandom();
        encontrado = arreglo[i];
        busquedaBinaria(encontrado);
        if(encontrado  == -1) {			
            printf("No se inserta %d porque ya existe.\n", encontrado);
        repetidos++; 
        }  else  {
            insertar(encontrado);
        }
    
    }
    generado = numero-repetidos;
    printf("Números de elementos en el arreglo generado: %d\n", generado);
    printf("Números de elementos que no se insertaron: %d\n", repetidos);
    desplegarArreglo();
return 0;
}//fin de main
//Funciones
int insertar(int dato) {                     
    int j;
    for(j=0;  j<numElems;  j++)   {      
        if(arreglo[j] > dato)   {             
            break;
        }
    }
    for(int k=numElems; k > j; k--)  {    
        arreglo[k] = arreglo[k-1];
    }
    arreglo[j] = dato;                             
                                                                  
}
int busquedaBinaria(int encontrado) {              
    int limInferior = 0;
    int limSuperior = numElems - 1;
    int valorCentral;
    while(true)    {
        valorCentral = (limInferior + limSuperior ) / 2;
        if(arreglo[valorCentral] == encontrado) {
            return -1;                                    
        } else if(limInferior > limSuperior) {
            return valorCentral;                                                        
        }
        if(arreglo[valorCentral] < encontrado) {
            limInferior = valorCentral + 1;               
        } else {
            limSuperior = valorCentral - 1;            
        }
    }
}
void desplegarArreglo() {
    int i;
    printf("[");
    for(i = 0; i < numElems - 1; i++) {
        printf("%d, ", arreglo[i]);
    }
    printf("%d]\n", arreglo[i]);
    return;
}
int getUnRandom() {	
    int r;
		r = rand();         
}