#include <stdio.h>

const short int FALSE = 0;
const short int TRUE = 1;

short int verificaMovimientos(int tablero[][8], int fila, int columna);

void movimientosCaballo(int tablero[][8], int fila, int columna, int movimiento) {
    const int desplazamientoFila[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int desplazamientoColumna[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    if (movimiento == 0) {
        printf("Movimientos del caballo:\n");
    }

    if (movimiento >= 8) {
        return;
    }

    int nuevaFila = fila + desplazamientoFila[movimiento];
    int nuevaColumna = columna + desplazamientoColumna[movimiento];

    if (verificaMovimientos(tablero, nuevaFila, nuevaColumna)) {
        tablero[nuevaFila][nuevaColumna] = 1;
        printf("(%d, %d)\n", nuevaFila, nuevaColumna);
    }

    movimientosCaballo(tablero, fila, columna, movimiento + 1);
}

short int verificaMovimientos(int tablero[][8], int fila, int columna) {
    if (fila < 0 || fila >= 8 || columna < 0 || columna >= 8) {
        return FALSE;
    }
    // Verifico si la casilla ya ha sido ocupada previamente.
    if (tablero[fila][columna] == 1) {
        return FALSE;
    }

    return TRUE;
}

int main(void) {
    int tablero[8][8] = {0};
    int fila = 0;
    int columna = 0;

    movimientosCaballo(tablero, fila, columna, 0);
    printf("Hola, caballo!\n");
    return 0;
}