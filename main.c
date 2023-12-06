#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Se definen las constantes del codigo que son alumnos y progresos, ya que estas nunca cambian 
#define ALUMNOS 23
#define PROGRESOS 3

float generarCalificaciones() { //Funcion para asignar un valor a las calificaciones
    return (float)(rand() % 11);  // Genera un número entre 0 y 10
}

float Promedio(float calificaciones[], int total) { //Funcion de tipo flotante para calcular el promedio 
    float suma = 0.0;
    for (int i = 0; i < total; i++) { //Estos promedios son por estudiantes entonces por eso solo va en i
        suma += calificaciones[i]; //Se suma cada calificacion para en la linea 17 dividir junto al total de progresos
    }
    return suma / total; 
}

int main() {
    //De la linea 22 - 26 se declaran las variables y se inicializan en 0 los valores del arreglo de los promedios de alumnos y progresos
    float calificaciones[ALUMNOS][PROGRESOS];
    float promediosA[ALUMNOS] = {0.0};
    float promediosP[PROGRESOS] = {0.0};
    int mayorAlumno = 0;
    float mayorPromedio = 0.0;

    srand(time(NULL));  

    for (int i = 0; i < ALUMNOS; i++) {
        for (int j = 0; j < PROGRESOS; j++) {
            calificaciones[i][j] = generarCalificaciones(); //Aqui se asignan las calificaciones a cada alumno de la matriz de [23][3]
            promediosP[j] += calificaciones[i][j];
        }
        promediosA[i] = Promedio(calificaciones[i], PROGRESOS); //Aqui calculamos los promedios de cada estudiante, llamando a la funcion Promedio con las variables de calificaciones y progresos en i
        if (promediosA[i] > mayorPromedio) { //Esta estructura condicional if va comprobando estudiante por estudiante y se le asigna a otra variable para comprobar el mayor promedio
            mayorPromedio = promediosA[i];
            mayorAlumno = i; //Finalmente el mayor promedio sera el que se almecene en estas variables despues de verificar la condicion
        } //Se hace despues del for en j, ya que queremos comprobar que estudiante es decir que fila es mayor que las demas
    }
    
    for (int j = 0; j < PROGRESOS; j++) { //for para recorrer las columnas que serian los progresos 
        promediosP[j] = promediosP[j] / ALUMNOS; //Aqui se divide el promedio del progreso con la cantidad de alumnos que es 23
    }

    for (int i = 0; i < ALUMNOS; i++) { //Este bucle solo es para mostrar en pantalla cada estudiante y su respectivo promedio
    printf("Promedio del Alumno %d: %.2f\n", i + 1, promediosA[i]);
    }
    for (int j = 0; j < PROGRESOS; j++) { //Este bucle solo es para mostrar en pantalla cada progreso y su respectivo promedio
        printf("Promedio del Progreso %d: %.2f\n", j + 1, promediosP[j]);
    }
    printf("Alumno con el mayor promedio: Alumno %d con un promedio de %.2f\n", mayorAlumno + 1, mayorPromedio); //Aqui mostramos en pantalla el alumno con mayor promedio 

return 0;

} 