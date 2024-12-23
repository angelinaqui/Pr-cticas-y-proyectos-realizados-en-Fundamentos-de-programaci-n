#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//Queue
int peekqueue(); 			        
void insert(int data);	        
int removeElem();	
//stack	      
int  peekstack();		
void pop();				
void push(int data);	
#define MAX 5
#define MAXSIZE 5
//queue
int myQueue[MAX];			   
int front = 0;                  
int rear = -1;				    
int itemCount = 0;
//stack
int stack[MAXSIZE]; 	
int top = -1;
int main(){
    int ent;
    printf("Teclee 5 enteros:\n");
    for (int i = 0; i < MAX; i++){
        scanf("%d", &ent);
        insert(ent);
        push(ent);
    }
    printf("Contenido del stack: [");
            while(top > 0) {			
				printf("%d, ",stack[top--]);
   			}
   			printf("%d]\n", stack[top--]);
     printf("Contenido del Queue: [");
            while(front < rear) {			
				printf("%d, ",myQueue[front++]);
   			}
   			printf("%d]\n", myQueue[front++]);
   			front = 0;
   			rear = -1;
			itemCount = 0;
}
    int peekqueue(){
        return myQueue[front];
    }
    void insert(int data){
        if(rear == MAX-1) {           
            rear = -1;
    }
        myQueue[++rear] = data;
        itemCount++;
    }
    int removeElem(){
        int data = myQueue[front++];
        itemCount--;
        return data;
    }
    int  peekstack(){
        return stack[top];
    }
    void push(int data){
        stack[++top] = data;
    }
    void pop(){
        top--;
    }