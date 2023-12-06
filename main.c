#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALUMNOS 23
#define PROGRESOS 3

float generarCalificaciones() {
    return (float)(rand() % 11);  // Genera un número entre 0 y 10
}