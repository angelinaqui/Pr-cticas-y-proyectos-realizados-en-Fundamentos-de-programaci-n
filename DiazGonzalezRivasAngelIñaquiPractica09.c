#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 20

// Definición de variables globales
struct DataItem {
    int data;
    int key;
};
struct DataItem* hashArray[SIZE];                  // Tabla Hash
struct DataItem* dummyItem;                         
struct DataItem* item;                                      

// Definición de funciones
int hashCode(int key);                                              // Función Hash
void insert(int key,int data);                                     
struct DataItem *search(int key);                            
struct DataItem* delete(struct DataItem* item);     
void display();                                                         

int main() {
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;
    printf("Creando una Tabla Hash\n");
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);         // produce colisión
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    insert(24,11);          // produce colisión
    insert(64,11);          // produce colisión
    insert(84,11);          // produce colisión

    printf("Tabla creada.\n");
    display();

    printf("Busca el elemento 14 en la tabla.\n");
    item = search(14);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->key);
    } else {
        printf("Elemento no encontrado.\n");
    }
    printf("Borra el elemento 14 en la tabla.\n");
    delete(item);

    printf("Elemento 14 borrado.\n");

    printf("Busca el elemento 14 en la tabla.\n");
    item = search(14);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->data);
    } else {
        printf("Elemento no encontrado\n");
    }
    display();
    printf("Busca el elemento 70 en la tabla.\n");
    item = search(70);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->key);
    } else {
        printf("Elemento no encontrado.\n");
    }
    printf("Busca el elemento 2 en la tabla.\n");
    item = search(2);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->key);
    } else {
        printf("Elemento no encontrado.\n");
    }
    printf("Borra el elemento 2 en la tabla.\n");
    delete(item);

    printf("Elemento 2 borrado.\n");

    printf("Busca el elemento 2 en la tabla.\n");
    item = search(2);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->data);
    } else {
        printf("Elemento no encontrado\n");
    }
    display();
}
// Función Hash
int hashCode(int key) {
    return key % SIZE;
}
// search
struct DataItem *search(int key) {
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        //go to next cell (quadratic probing)
        int n = 1;
        n++;
        hashIndex = hashIndex + pow(n, 2);
        hashIndex %= SIZE;
    }
    return NULL;
}

// insert
void insert(int key,int data) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        //go to next cell (quadratic probing)
        int n = 1;
        n++;
        hashIndex = hashIndex + pow(n, 2);
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

// delete
struct DataItem* delete(struct DataItem* item) {
    int key = item->key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem;
            return temp;
        }
        //go to next cell (quadratic probing)
        int n = 1;
        n++;
        hashIndex = hashIndex + pow(n, 2);
        hashIndex %= SIZE;
    }
    return NULL;
}
// display.
void display() {
    int i = 0;
    for(i = 0; i<SIZE; i++) {
        if(hashArray[i] != NULL)
            printf("%2d: (%d,%d)\n",i,hashArray[i]->key,hashArray[i]->data);
        else
            printf("%2d: (~,~)\n",i);
    }
    printf("\n");
}