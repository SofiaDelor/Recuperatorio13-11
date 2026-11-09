#ifndef CASED_BUSCARESPECIAL_H
#define CASED_BUSCARESPECIAL_H

#include "Inicio_Estructura.h"

void buscar_especifica(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("[ERROR] No se pudo abrir el archivo '%s'.\n", nombre_archivo);
        return;
    }

    char buscado[TAM_STRING];
    printf("\n--- BUSQUEDA ESPECIFICA ---\n");
    printf("Ingrese la fecha de la excursion a buscar (DD/MM): ");
    scanf("%49s", buscado);
    limpiar_buffer();

    Excursion reg;
    int disp_int;
    bool encontrado = false;

    while (fscanf(archivo, "%49s %c %f %d %d",
        reg.fecha, &reg.tipo_excursion, &reg.presupuesto, &reg.cant_personas, &disp_int) == 5) {
        if (strcmp(reg.fecha, buscado) == 0) {
            reg.disponible = (bool)disp_int;
            printf("\n[REGISTRO ENCONTRADO]\n");
            printf("  Fecha       : %s\n", reg.fecha);
            printf("  Tipo Excurs.: %c\n", reg.tipo_excursion);
            printf("  Presupuesto : $%.2f USD\n", reg.presupuesto);
            printf("  Personas    : %d\n", reg.cant_personas);
            printf("  Disponible  : %s\n", reg.disponible ? "SI" : "NO");
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("\n[INFO] No se encontro ningun registro para la fecha '%s'.\n", buscado);
    }

    fclose(archivo);
}

#endif // CASED_BUSCARESPECIAL_H
