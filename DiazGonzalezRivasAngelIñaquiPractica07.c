#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
void imprimeReporte();
struct Empleado{
    int numEmpleado;
    char nombre[30];
    char apellido[30];
    char departamento[20];
    float sueldo;
};
    char archivo[] = "./datos/Empleados.txt";
    struct Empleado emp;

int main(){
    char buff[255];
    int result;
    result = 4;
    FILE *fp;
    fp = fopen("./datos/Empleados.txt", "r");
    fgets(buff, 255, fp);
    printf("Listado de Clientes\n");
    while (result != EOF){
        fscanf(fp, "%s", buff);
        emp.numEmpleado = atoi(buff);
        fscanf(fp, "%s", buff);
        strcpy(emp.nombre, buff);
        fscanf(fp, "%s", buff);
        strcpy(emp.apellido, buff);
        fscanf(fp, "%s", buff);
        strcpy(emp.departamento, buff);
        fscanf(fp, "%s", buff);
        emp.sueldo = atof(buff);
        if (result != EOF){
            imprimeReporte();
        }
        result--;
    }
    fclose(fp);
}
void imprimeReporte(){
    printf("Numero : %d\n", emp.numEmpleado);
    printf("Nombre : %s\n", emp.nombre);
    printf("Apellido : %s\n", emp.apellido);
    printf("Depto. : %s\n", emp.departamento);
    printf("Sueldo : %f\n", emp.sueldo);
}