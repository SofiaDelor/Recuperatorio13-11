#ifndef CASEC_LISTARCONDICION_H
#define CASEC_LISTARCONDICION_H

#include "Inicio_Estructura.h"

void listar_por_condicion(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("[ERROR] No se pudo abrir el archivo '%s'.\n", nombre_archivo);
        return;
    }

    float min_presupuesto;
    printf("\n--- FILTRADO POR CONDICION ---\n");
    printf("Mostrar excursiones con presupuesto mayor o igual a (USD): ");
    if (scanf("%f", &min_presupuesto) != 1) {
        printf("[ERROR] Ingrese un valor numerico valido.\n");
        limpiar_buffer();
        fclose(archivo);
        return;
    }
    limpiar_buffer();

    Excursion reg;
    int disp_int;
    int coincidentes = 0;

    printf("\n--- REGISTROS CON PRESUPUESTO >= $%.2f ---\n", min_presupuesto);
    printf("%-20s %-6s %-10s %-15s %-12s\n", "CLIENTE", "TIPO", "PERSONAS", "PRESUPUESTO", "DISPONIBLE");
    printf("-------------------------------------------------------------------------\n");

    while (fscanf(archivo, "%49s %c %d %f %d",
        reg.cliente, &reg.tipo_excursion, &reg.cant_personas, &reg.presupuesto, &disp_int) == 5) {
        if (reg.presupuesto >= min_presupuesto) {
            reg.disponible = (bool)disp_int;
            printf("%-20s %-6c %-10d $%-14.2f %-12s\n",
                reg.cliente,
                reg.tipo_excursion,
                reg.cant_personas,
                reg.presupuesto,
                reg.disponible ? "SI" : "NO");
            coincidentes++;
        }
    }

    printf("-------------------------------------------------------------------------\n");
    printf("Registros que cumplen la condicion: %d\n", coincidentes);

    fclose(archivo);
}

#endif // CASEC_LISTARCONDICION_H
