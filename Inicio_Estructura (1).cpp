#ifndef INICIO_ESTRUCTURA_H
#define INICIO_ESTRUCTURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ARCHIVO_ORIGEN "excursiones.txt"
#define ARCHIVO_DISPONIBLES "disponibles.txt"
#define ARCHIVO_NO_DISPONIBLES "no_disponibles.txt"
#define TAM_STRING 50

// Estructura de datos requerida (5 campos de distintos tipos)
typedef struct {
    char cliente[TAM_STRING];   // String
    char tipo_excursion;        // Char ('A', 'B', 'C')
    int cant_personas;          // Entero
    float presupuesto;          // Float / Double
    bool disponible;            // Booleano
} Excursion;
// Función auxiliar para limpiar el búfer de entrada
void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif // INICIO_ESTRUCTURA_H
