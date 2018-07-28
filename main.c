#include <stdio.h>
#include "Partida.h"



int main(int agv, char** argc) {
    if (argc < 3) {
        printf("Error en fitxers\n");
    } else {

        // REVISAR etiquetes RR
        /*MENU
         *
         * Blackjack
            1. Generar pila de cartas
            2. Jugar
            3. Mostrar estadísticas
            4. Salir
        Opción: _
         */

        int numero = 0;
        int opcio = 0;
        int numbots = 0;
        int baralla_creada = 0;
        Partida partida = Partida_crea(argc);
        while (opcio != 4) {

            mostrarMenu();
            printf("\nOpcion: ");
            scanf("%d", &opcio);
            printf("\n");

            switch (opcio) {
                case 1:
                    if (baralla_creada == 1) {

                        Partida_borraBaralla(&partida);
                    }
                    printf("numero de baralles:\n");
                    scanf("%d", &numero);
                    baralla_creada = Partida_generarBaralla(&partida, numero);
                    //printf("%d", Partida_demanaCarta(&partida));
                    break;
                case 2:
                    if (baralla_creada == 1) {
                        if(Player_nFitxes(partida.player)>=20) {
                            int i = Partida_jugar(&partida);
                        }
                        else printf("El Jugador no te proutes fitxes");
                    } else {
                        printf("Baralla no creada, no es pot jugar");
                    }


                    break;
                case 3:
                    Partida_Imprimir_estadistiques(partida);



                    break;
                case 4:
                    break;
                default:
                    printf("\nOpcio no valida!\n");
                    break;
            }
        }
        return 0;
    }
}
void mostrarMenu() {
    printf("\nBlackjack\n");
    printf("\n 1. Generar pila de cartas");
    printf("\n 2. Jugar");
    printf("\n 3. Mostrar estadisticas");
    printf("\n 4. Salir\n");
}
