#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
// Definición de variables globales
struct node {
   int data;
   struct node *next;
   struct node *previo;
};
struct node *start = NULL;	
struct node *found = NULL;	
int count = 0;				
// Definición de funciones
void insertFirst(int);		
void insertLast(int);		
void insertAfter(int, int);	
int find(int);				
void traverse();			
void traverseInv();
void deleteFirst();			
void deleteLast();			
void create();				

int main () {
   	int dato, opcion;
    setlocale(LC_ALL, "");		// para caracteres del Español
    printf(" 1 - Insertar al inicio de la linked list.\n");
    printf(" 2 - Insertar al final de la linked list.\n");
    printf(" 3 - Insertar después de otro.\n");
    printf(" 4 - Buscar un nodo en la lista.\n");
    printf(" 5 - Desplegar la linked list (traverse).\n");
    printf(" 6 - Desplegar la linked list (traverse Reverse).\n");
    printf(" 7 - Borrar elemento al inicio\n");
    printf(" 8 - Borrar elemento al final.\n");
    printf(" 9 - Terminar\n");
    create();			
    while (true) {
        printf("Teclee la opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
        case 1:			// insertar al inicio
            printf("Teclee valor del elemento a insertar al inicio\n");
         	scanf("%d", &dato);
         	insertFirst(dato);
            break;
        case 2:			// insertar al final
            printf("Teclee valor del elemento a insertar al final\n");
         	scanf("%d", &dato);
         	insertLast(dato);
            break;
        case 3:			// insertar después
            printf("Teclee valor de la llave.\n");
         	scanf("%d", &dato);
         	int llave = find(dato);
         	if (llave == -2) {			// find regresa -2 si la lista está vacía
         		break;
			}
         	if(llave == -1) {			// find regresa -1 si no se encuentra
         		printf("No se encontró %d en la lista.\n", dato);
         		break;
			}
         	printf("Teclee valor de nodo a insertar después de llave.\n");
         	scanf("%d", &dato);
			insertAfter(llave, dato);
            break;
        case 4:			// buscar
            printf("Teclee valor del elemento a buscar.\n");
         	scanf("%d", &dato);
         	int encontrado = find(dato);
         	if (encontrado == -2) {			// find regresa -2 si la lista está vacía
         		break;
			}
         	if(encontrado == -1) {			// find regresa -1 si no se encuentra
         		printf("No se encontró %d en la lista.\n", dato);
			} else {
				printf("Se encontró %d en la lista.\n", dato);
			}
            break;
        case 5:			// recorrer
        	traverse();
            break;
        case 6:			// recorrerinversa
        	traverseInv();
            break;
        case 7:			// borrar el primero
            deleteFirst();
            break;
        case 8:			// borrar el último
            deleteLast();
            break;
        case 9:
            printf("Gracias por participar");
            exit(0);
        default:
            printf("Opción inválida, intente de nuevo\n");
  		}
    }
   return 0;
}

void insertFirst(int dato) {
   struct node *t;
   t = malloc(sizeof(struct node));  
   count++;
   if (start == NULL) {				
      start = t;
      start->data = dato;
      start->next = NULL;
      start->previo = NULL;
      return;
   }
   t->data = dato;
   t->previo=NULL;
   t->next = start;
   start->previo=t;
   start = t;
}

void insertLast(int dato) {
   struct node *t, *temp;
   t = malloc(sizeof(struct node));
   count++;
   if (start == NULL) {				
      start = t;
      start->data = dato;
      start->next = NULL;
      start->previo = NULL;
      return;
   }
   temp = start;
   while (temp->next != NULL) {  	
      temp = temp->next;         
   }
   temp->next = t;
   t->data    = dato;
   t->previo = temp;
   t->next    = NULL;
}

int find(int datoBuscado) {
	struct node *t;
   	t = start;
   	if (t == NULL) {
      printf("Linked list vacía.\n");
      return -2;
   }
   	while (t->next != NULL) {  			
      if(t->data == datoBuscado) {
      		found = t;
		  return t->data;
	  } else {
	  	t = t->next;
	  }
   	}
   	if(t->data == datoBuscado) {		
   		found = t;
      	return t->data;
	}
	return -1;
}
void insertAfter(int llave, int dato) {
    struct node *nuevo, *actual;
   	if (start == NULL) {
      printf("Linked list vacía.\n");
      return;
   	}
    int temp = find(llave);     
    actual = found;		          
    nuevo = malloc(sizeof(struct node));
    nuevo->data = dato;
    nuevo->next = actual->next;
    actual->next = nuevo;
    count++;
    printf("Se insertó %d después de %d.\n", dato, llave);
}

void traverse() {
   struct node *t;
   t = start;
   if (t == NULL) {
      printf("Linked list vacía.\n");
      return;
   }
   printf("Hay %d elemento(s) en la linked list.\n", count);
   while (t->next != NULL) {
      printf("%d -> ", t->data);
      t = t->next;
   }
   printf("%d\n", t->data);
}
void traverseInv() {
   struct node *t, *temp;
   temp = start;
   if (temp == NULL) {
      printf("Linked list vacía.\n");
      return;
   }
   while (temp->next != NULL) {  	
      temp = temp->next;         
   }
   t = temp;
   printf("Hay %d elemento(s) en la linked list.\n", count);
   while (t->previo != NULL) {
      printf("%d -> ", t->data);
      t = t->previo;
   }
   printf("%d\n", t->data);
}

void deleteFirst() {
   struct node *t;
   int n;
   if (start == NULL) {
      printf("Linked list vacía.\n");
      return;
   }
   n = start->data;
   t = start->next;
   t -> previo = NULL;
   free(start);
   start = t;
   count--;
   printf("%d eliminado del inicio de la linked list.\n", n);
}

void deleteLast() {
   struct node *t, *u;
   int n;
   if (start == NULL) {
      printf("Linked list vacía.\n");
      return;
   }

   count--;

   if (start->next == NULL) {		
      n = start->data;
      free(start);
      start = NULL;
      printf("%d eliminado del final de la linked list.\n", n);
      return;
   }

   t = start;

   while (t->next != NULL) {
      u = t;
      t = t->next;
   }

   n = t->data;
   u->previo -> next = NULL;
   free(t);

   printf("%d eliminado del final de la linked list.\n", n);
}
void create() {
	insertFirst(444);
	insertFirst(333);
	insertFirst(222);
	insertFirst(111);
}