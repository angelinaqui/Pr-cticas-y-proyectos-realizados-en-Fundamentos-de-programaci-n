#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main(){
    setlocale(LC_CTYPE,"");
    char termino[] = "00";
    char StaticBuffer[100];
    int a, newsize;
    char *texto;
    texto = malloc(1);
    strcpy(texto, " ");
    
    printf("Teclee lineas de texto (para terminar teclee 00):\n");
    while (StaticBuffer != termino){
        gets(StaticBuffer);
        a = strcmp(StaticBuffer, termino);
        if (a == 0){
            break;
        }else{
        newsize = strlen(StaticBuffer);
        texto = realloc(texto, newsize);
        strcat(texto, StaticBuffer);
        strcat(texto, " ");
        free(StaticBuffer);
        }
    }
    printf("Resultado:%s", texto);
    free(texto);
}
