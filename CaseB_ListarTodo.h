#ifndef CASEB_LISTARTODO_H
#define CASEB_LISTARTODO_H

#include "Inicio_Estructura.h"

static inline void listar_todo(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("[ERROR] No existe o no se pudo abrir el archivo '%s'.\n", nombre_archivo);
        return;
    }

    Excursion reg;
    int disp_int;
    int contador = 0;

    printf("\n-------------------------------------------------------------------------\n");
    printf("%-12s %-6s %-15s %-10s %-12s\n", "FECHA", "TIPO", "PRESUPUESTO", "PERSONAS", "DISPONIBLE");
    printf("-------------------------------------------------------------------------\n");

    while (fscanf(archivo, "%49s %c %f %d %d",
        reg.fecha, &reg.tipo_excursion, &reg.presupuesto, &reg.cant_personas, &disp_int) == 5) {
        reg.disponible = (bool)disp_int;
        printf("%-12s %-6c $%-14.2f %-10d %-12s\n",
            reg.fecha,
            reg.tipo_excursion,
            reg.presupuesto,
            reg.cant_personas,
            reg.disponible ? "SI" : "NO");
        contador++;
    }

    printf("-------------------------------------------------------------------------\n");
    printf("Total de registros encontrados: %d\n", contador);

    fclose(archivo);
}

#endif // CASEB_LISTARTODO_H
