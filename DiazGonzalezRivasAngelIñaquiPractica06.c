#include <stdio.h>
#include <locale.h>
#include <windows.h> // para las funciones srand y rand
#include <time.h> // para las funciones time y sleep
#define max 10 // capacidad de la cola
int queArray[max]; // cola priorizada implementada como arreglo
int front; // inicio de la cola
int rear; //fin de la cola
void insert(int proceso); // insert por prioridad
int removeFirst(); // remove elemento de mayor prioridad
void display(); // despliega el contenido de la cola
int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int n;
    int e;
    int q;
    for (int i = 0; i <= max; i++){
        n = rand();
        insert(n);
    }
    display();
    for (int i = 0; i <= max; i++){
        e = removeFirst();
        q = rand();
        Sleep(q);
        printf("Esperando %d segundo/s\n", q);
        printf("Se removió el proceso %d\n", e);
    }
}
void insert(int proceso){
    if(rear == max-1) { 
        rear = -1;
    }
    queArray[++rear] = proceso;
}
int removeFirst(){
    if(front == -1 & rear == 0) {
        printf("La cola está vacía, no se puede remover\n");
        return -1;
    } else { 
        queArray[front--];
        return queArray[rear++];
    }
}
void display(){
    int i;
    printf("Procesos en cola:");
    for(i = 0; i < max - 1; i++) {
      printf("Proceso: %d\n", queArray[i]);
    }
    printf("Proceso: %d\n", queArray[i]);
}