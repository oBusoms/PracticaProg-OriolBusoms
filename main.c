#include <stdio.h>
#include "misc.h"
#include "baralla.h"


int main() {
    printf("numero de baralles:\n");
    int numero = 0;
    scanf("%i",numero);


    Baralla b = BARALLA_crea(numero);
    int carta = BARALLA_demanaCarta(&b);
    printf("%i", carta);
    /*MENUU
     *
     * Blackjack
        1. Generar pila de cartas
        2. Jugar
        3. Mostrar estadísticas
        4. Salir
    Opción: _
     */


    return 0;
}