/* ejercicio 51 - turno mañana - octubre 2026
función swap con punteros
 */
#include <stdio.h>
void swap(int*, int*);
int main(void) {
    //dos variables con valores, pueden preguntar al usuario, usar rand o asignar
    int x = 10;
    int y = 22;
    //version 1 punteros explícitos
    int* ptrX = &x;
    int* ptrY = &y;
    swap(ptrX,ptrY);

    // versión 2 - pasando direcciones directamente
    swap(&x, &y);

    //verificar swap
    printf("x = %d, y = %d\n", x, y);

  return 0;
}
void swap(int* a, int* b) {
//intercambiar valores

    return;
}
