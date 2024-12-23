#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
double calculaLong(char *ptr, int dato);
void tieneLetra(char *str, char l);
const int MAX = 5;
int main (){
    setlocale(LC_ALL, "");
    int len;
    int res;
    res = 0;
    int a;
    char *UNAM[] = {"Universidad", "Nacional", "Autonoma", "de", "Mexico"};
    for (int i = 0; i < MAX; i++){
        a = calculaLong(UNAM[i], len);
        res = res + a;
    }
    printf("La longitud total del string UNAM es de %d caracteres\n", res);

    for (int i = 0; i < MAX; i++){
        tieneLetra(UNAM[i], 'e');
    }
}
double calculaLong(char *ptr, int dato){
    int len;
    len = strlen(ptr);
    printf("%s ", ptr);
    printf("tiene %d letras\n", len);
    return len;
}
void tieneLetra(char *str, char l){
    char *c;
    c = strchr(str, l);
    if (c == NULL){
        printf("La palabra %s No tiene la letra %c\n", str, l);
    }else{
        printf("La palabra %s SI tiene la letra %c\n", str, l);
    }
}
