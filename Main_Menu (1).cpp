#include "Inicio_Estructura.h"
#include "CaseA_Agregar.h"
#include "CaseB_ListarTodo.h"
#include "CaseC_ListarCondicion.h"
#include "CaseD_BuscarEspecial.h"
#include "CaseE_DividirBooleano.h"

void mostrar_menu(void) {
    printf("\n======================================================\n");
    printf("        SISTEMA DE GESTION DE EXCURSIONES            \n");
    printf("======================================================\n");
    printf("1. Agregar un registro al archivo\n");
    printf("2. Listar todo el archivo por pantalla\n");
    printf("3. Listar registros por condicion\n");
    printf("4. Busqueda especifica \n");
    printf("5. Dividir archivo segun disponibilidad\n");
    printf("6. Salir del sistema\n");
    printf("======================================================\n");
}

int main(void) {
    int opcion = 0;

    do {
        mostrar_menu();
        printf("Seleccione una opcion (1-6): ");
        if (scanf("%d", &opcion) != 1) {
            printf("[ERROR] Entrada invalida. Por favor ingrese un numero.\n");
            limpiar_buffer();
            continue;
        }
        limpiar_buffer();

        switch (opcion) {
        case 1:
            agregar_registro(ARCHIVO_ORIGEN);
            break;
        case 2:
            listar_todo(ARCHIVO_ORIGEN);
            break;
        case 3:
            listar_por_condicion(ARCHIVO_ORIGEN);
            break;
        case 4:
            buscar_especifica(ARCHIVO_ORIGEN);
            break;
        case 5:
            dividir_archivo_por_booleano(ARCHIVO_ORIGEN, ARCHIVO_DISPONIBLES, ARCHIVO_NO_DISPONIBLES);
            break;
        case 6:
            printf("\nSaliendo del sistema de gestion...\n");
            break;
        default:
            printf("\n[ERROR] Opcion fuera de rango (1-6).\n");
            break;
        }
    } while (opcion != 6);

    return 0;
}
