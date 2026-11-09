#ifndef CASEA_AGREGAR_H
#define CASEA_AGREGAR_H

#include "Inicio_Estructura.h"

void agregar_registro(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL) {
        printf("[ERROR] No se pudo abrir el archivo para escritura.\n");
        return;
    }

    Excursion reg;
    char respuesta_bool;

    printf("\n--- ALTA DE NUEVA EXCURSION ---\n");

    printf("Ingrese fecha de la excursion (DD/MM): ");
    scanf("%49s", reg.fecha);
    limpiar_buffer();

    printf("Ingrese tipo de excursion (A = Safari, B = Tiburones, C = Ballenas): ");
    scanf("%c", &reg.tipo_excursion);
    reg.tipo_excursion = (char)toupper((unsigned char)reg.tipo_excursion);
    limpiar_buffer();

    printf("Ingrese cantidad de personas: ");
    while (scanf("%d", &reg.cant_personas) != 1 || reg.cant_personas <= 0) {
        printf("[ERROR] Ingrese un numero entero positivo: ");
        limpiar_buffer();
    }
    limpiar_buffer();

    printf("Ingrese presupuesto por persona (USD): ");
    while (scanf("%f", &reg.presupuesto) != 1 || reg.presupuesto < 0) {
        printf("[ERROR] Ingrese un presupuesto valido: ");
        limpiar_buffer();
    }
    limpiar_buffer();

    printf("¿Esta disponible / confirmada? (S/N): ");
    scanf("%c", &respuesta_bool);
    respuesta_bool = (char)toupper((unsigned char)respuesta_bool);
    reg.disponible = (respuesta_bool == 'S');
    limpiar_buffer();

    // Guardado formateado en el archivo de texto
    fprintf(archivo, "%s %c %.2f %d %d\n",
        reg.fecha,
        reg.tipo_excursion,
        reg.presupuesto,
        reg.cant_personas,
        reg.disponible ? 1 : 0);

    fclose(archivo);
    printf("\n[EXITO] Registro guardado correctamente en '%s'.\n", nombre_archivo);
}

#endif // CASEA_AGREGAR_H
