#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALUMNOS 23
#define PROGRESOS 3

float generarCalificaciones() {
    return (float)(rand() % 11);  // Genera un número entre 0 y 10
}

float Promedio(float calificaciones[], int total) {
    float suma = 0.0;
    for (int i = 0; i < total; i++) {
        suma += calificaciones[i];
    }
    return suma / total;
}

int main() {
    float calificaciones[ALUMNOS][PROGRESOS];
    float promediosA[ALUMNOS] = {0.0};
    float promediosP[PROGRESOS] = {0.0};
    int mayorAlumno = 0;
    float mayorPromedio = 0.0;

    srand(time(NULL));  

    for (int i = 0; i < ALUMNOS; i++) {
        for (int j = 0; j < PROGRESOS; j++) {
            calificaciones[i][j] = generarCalificaciones();
            promediosP[j] += calificaciones[i][j];
            promediosA[i] = calcularPromedio(calificaciones[i], PROGRESOS);
        if (promediosA[i] > mayorPromedio) {
            mayorAlumno = promediosA[i];
            mayorPromedio = i;
        }
        }
        
    }
return 0;
} 