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
    printf("Ingrese el nombre del cliente a buscar: ");
    scanf("%49s", buscado);
    limpiar_buffer();

    Excursion reg;
    int disp_int;
    bool encontrado = false;

    while (fscanf(archivo, "%49s %c %d %f %d",
        reg.cliente, &reg.tipo_excursion, &reg.cant_personas, &reg.presupuesto, &disp_int) == 5) {
        if (strcmp(reg.cliente, buscado) == 0) {
            reg.disponible = (bool)disp_int;
            printf("\n[REGISTRO ENCONTRADO]\n");
            printf("  Cliente     : %s\n", reg.cliente);
            printf("  Tipo Excurs.: %c\n", reg.tipo_excursion);
            printf("  Personas    : %d\n", reg.cant_personas);
            printf("  Presupuesto : $%.2f USD\n", reg.presupuesto);
            printf("  Disponible  : %s\n", reg.disponible ? "SI" : "NO");
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("\n[INFO] No se encontro ningún registro para el cliente '%s'.\n", buscado);
    }

    fclose(archivo);
}

#endif // CASED_BUSCARESPECIAL_H