#ifndef CASEE_DIVIDIRBOOLEANO_H
#define CASEE_DIVIDIRBOOLEANO_H

#include "Inicio_Estructura (4).h"

static inline void dividir_archivo_por_booleano(const char* origen, const char* dest_true, const char* dest_false) {
    FILE* f_origen = fopen(origen, "r");
    if (f_origen == NULL) {
        printf("[ERROR] No se pudo abrir el archivo de origen '%s'.\n", origen);
        return;
    }

    FILE* f_true = fopen(dest_true, "w");
    FILE* f_false = fopen(dest_false, "w");

    if (f_true == NULL || f_false == NULL) {
        printf("[ERROR] No se pudieron crear los archivos de destino.\n");
        if (f_origen) fclose(f_origen);
        if (f_true) fclose(f_true);
        if (f_false) fclose(f_false);
        return;
    }

    Excursion reg;
    int disp_int;
    int cant_true = 0, cant_false = 0;

    while (fscanf_s(f_origen, "%49s %c %f %d %d",
        reg.fecha, (unsigned)sizeof reg.fecha, &reg.tipo_excursion, (unsigned)sizeof reg.tipo_excursion, &reg.presupuesto, &reg.cant_personas, &disp_int) == 5) {
        reg.disponible = (bool)disp_int;

        if (reg.disponible) {
            fprintf(f_true, "%s %c %.2f %d %d\n",
                reg.fecha, reg.tipo_excursion, reg.presupuesto, reg.cant_personas, 1);
            cant_true++;
        }
        else {
            fprintf(f_false, "%s %c %.2f %d %d\n",
                reg.fecha, reg.tipo_excursion, reg.presupuesto, reg.cant_personas, 0);
            cant_false++;
        }
    }

    fclose(f_origen);
    fclose(f_true);
    fclose(f_false);

    printf("\n--- PROCESO DE DIVISION COMPLETADO ---\n");
    printf("1. Archivo '%s' (Disponibles = SI): %d registros guardados.\n", dest_true, cant_true);
    printf("2. Archivo '%s' (Disponibles = NO): %d registros guardados.\n", dest_false, cant_false);
}

#endif // CASEE_DIVIDIRBOOLEANO_H

