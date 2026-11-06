
#ifndef CASEB_LISTARTODO_H
#define CASEB_LISTARTODO_H

#include "Inicio_Estructura.h"

void listar_todo(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("[ERROR] No existe o no se pudo abrir el archivo '%s'.\n", nombre_archivo);
        return;
    }

    Excursion reg;
    int disp_int;
    int contador = 0;

    printf("\n-------------------------------------------------------------------------\n");
    printf("%-20s %-6s %-10s %-15s %-12s\n", "CLIENTE", "TIPO", "PERSONAS", "PRESUPUESTO", "DISPONIBLE");
    printf("-------------------------------------------------------------------------\n");

    while (fscanf(archivo, "%49s %c %d %f %d",
        reg.cliente, &reg.tipo_excursion, &reg.cant_personas, &reg.presupuesto, &disp_int) == 5) {
        reg.disponible = (bool)disp_int;
        printf("%-20s %-6c %-10d $%-14.2f %-12s\n",
            reg.cliente,
            reg.tipo_excursion,
            reg.cant_personas,
            reg.presupuesto,
            reg.disponible ? "SI" : "NO");
        contador++;
    }

    printf("-------------------------------------------------------------------------\n");
    printf("Total de registros encontrados: %d\n", contador);

    fclose(archivo);
}

#endif // CASEB_LISTARTODO_H
