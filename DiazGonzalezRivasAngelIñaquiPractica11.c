#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#define  LONG_ARR 100000
// declaración de las funciones
int insertar(int dato);
void bubbleSort(int array[], int num);
void desplegarArreglo1();
void swap(int *a, int *b); 
void selectionSort(int array[], int num); 
void desplegarArreglo2();
void insertionSort(int array[], int num); 
void desplegarArreglo3();
int  getUnRandom( );
// variables globales
int arreglo[LONG_ARR];               // tamaño máximo del arreglo
int arreglo1[LONG_ARR];
int arreglo2[LONG_ARR];
int arreglo3[LONG_ARR];
int numElems = 0;                         // número de elementos en el arreglo
// inicio
int main() {
    setlocale(LC_ALL, "");		    // para caracteres del Español
    srand((unsigned)time(0));		/* Inicializa la semilla, debe ser una sola vez.  */
    int numero, encontrado, num;
    printf("Teclee el  número de elementos en el arreglo (<10000)\n");
    scanf("%d", &numero);
    for(int i = 0; i <  numero; i++) {
         num = getUnRandom();
        insertar(num);
    }
    for (int i = 0; i < numero; i++) {     
        arreglo1[i] = arreglo[i];     
    }     
    for (int i = 0; i < numero; i++) {     
        arreglo2[i] = arreglo[i];     
    }  
    for (int i = 0; i < numero; i++) {     
        arreglo3[i] = arreglo[i];     
    }  
    bubbleSort(arreglo1, numero);
    printf("El arreglo ordenado por bubble sort es:\n");
    desplegarArreglo1();

    selectionSort(arreglo2, numero);
    printf("El arreglo ordenado por selection sort es:\n");
    desplegarArreglo2();

    insertionSort(arreglo3, numero);
    printf("El arreglo ordenado por insertion sort es:\n");
    desplegarArreglo3();
    return 0;
}  // fin de main
// Funciones.
// función para generar números pseudoaleatorios
int  getUnRandom( ) {
	int num;
	num = rand();          // genera el número pseudoaleatorio
	return num;
}
// inserta un elemento en el arreglo ordenado
int insertar(int dato) {                     //  insertar en el arreglo
    if(numElems == LONG_ARR)  {
        return -2;                                // arreglo lleno
    }
    int j;
    for(j=0;  j<numElems;  j++)   {      // encuentra punto de inserción (en forma lineal)
        if(arreglo[j] > dato)   {              // se encontró
            break;
        }
    }
    for(int k=numElems; k > j; k--)  {     // recorre hacia el final del arreglo
        arreglo[k] = arreglo[k-1];
    }
    arreglo[j] = dato;                               // inserción
    numElems++;                                     // incrementa número de elementos
}
void bubbleSort(int array[], int num){
    struct timeval inicio;
    gettimeofday(&inicio, NULL);
    int i, j, temp;   
    for(i = 0; i < num - 1; i++){
        for(j = 0; j < num - i - 1; j++){    
            if(array[j] > array[j + 1]){ 
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("inicio: %ld\n", (long)(inicio.tv_sec*1000000 + inicio.tv_usec));
    struct timeval fin;
    gettimeofday(&fin, NULL);
    printf("fin: %d\n", fin.tv_sec*1000000 + fin.tv_usec);
    long microseconds =(long)((fin.tv_sec - inicio.tv_sec) * 1000000 + ((int)fin.tv_usec - (int)inicio.tv_usec));
    long milliseconds = microseconds/1000;
    printf("Con bubble sort se tardo %ld milisegundos \n", milliseconds);
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
// Selection Sort
void selectionSort(int array[], int num) {
  struct timeval inicio;
  gettimeofday(&inicio, NULL);
  for (int step = 0; step < num - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < num; i++) {
      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
   printf("inicio: %ld\n", (long)(inicio.tv_sec*1000000 + inicio.tv_usec));
   struct timeval fin;
   gettimeofday(&fin, NULL);
   printf("fin: %d\n", fin.tv_sec*1000000 + fin.tv_usec);
   long microseconds =(long)((fin.tv_sec - inicio.tv_sec) * 1000000 + ((int)fin.tv_usec - (int)inicio.tv_usec));
   long milliseconds = microseconds/1000;
   printf("Con selection sort se tardo %ld milisegundos \n", milliseconds);
}
void insertionSort(int array[], int num) {
  struct timeval inicio;
  gettimeofday(&inicio, NULL);
  for (int step = 1; step < num; step++) {
    int key = array[step];
    int j = step - 1;
    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
  printf("inicio: %ld\n", (long)(inicio.tv_sec*1000000 + inicio.tv_usec));
  struct timeval fin;
  gettimeofday(&fin, NULL);
  printf("fin: %d\n", fin.tv_sec*1000000 + fin.tv_usec);
  long microseconds =(long)((fin.tv_sec - inicio.tv_sec) * 1000000 + ((int)fin.tv_usec - (int)inicio.tv_usec));
  long milliseconds = microseconds/1000;
  printf("Con insertion sort se tardo %ld milisegundos \n", milliseconds);
}
void desplegarArreglo1() {
    int i;
    printf("[");
    for(i = 0; i < numElems - 1; i++) {
        printf("%d, ", arreglo1[i]);
    }
    printf("%d]\n", arreglo1[i]);
    return;
}
void desplegarArreglo2() {
    int i;
    printf("[");
    for(i = 0; i < numElems - 1; i++) {
        printf("%d, ", arreglo2[i]);
    }
    printf("%d]\n", arreglo2[i]);
    return;
}
void desplegarArreglo3() {
    int i;
    printf("[");
    for(i = 0; i < numElems - 1; i++) {
        printf("%d, ", arreglo3[i]);
    }
    printf("%d]\n", arreglo3[i]);
    return;
}