#include <stdio.h> 
#include <locale.h>
#define LONG_ARR 25

void printArray(int, int);

int main (){
    setlocale(LC_ALL, "");
    int array1[LONG_ARR] = {2,3,5,7,11,13,17,19};
    int numElems = 8;
    int matrix[5][5] = { {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
    int numELems2 = 5;
    printf("array1 es:");
    void printArray(); {
    for (int i = 0; i < numElems-1; i++ )   {
       printf("%d,", *(array1 + i));
	}
    printf("%d", *(array1 + 7));
    printf("\n");
    }
    int i,j;
    for ( i = 0; i < numELems2; i++ )   {
		for ( j = 0; j < numELems2; j++ ) {
            matrix[i][j] = i*j;
            printf("matrix [%d] es: ", i);
			printf("%d\n",matrix[i][j]);
		}
	}
}