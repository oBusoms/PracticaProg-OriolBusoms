#include <stdio.h>
#include "Partida.h"
#include "misc.h"



int main() {

    /*MENUU
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
    Partida partida = Partida_crea(numbots);
    while (opcio != 4) {

        mostrarMenu();
        printf("\nOpcion: ");
        scanf("%d", &opcio);
        printf("\n");

        switch (opcio) {
            case 1:
                if(baralla_creada == 1) {

                    Partida_borraBaralla(&partida);
                }
                printf("numero de baralles:\n");
                scanf("%d",&numero);
                baralla_creada = Partida_generarBaralla(&partida, numero);
                printf("%d",Partida_demanaCarta(&partida));
                break;
            case 2:
                if(baralla_creada == 1){
                    donar_cartes(&partida);
                    imprimir_cartes(&partida);
                }
                else{
                    printf("Baralla no creada, no es pot jugar");
                }


                break;
            case 3:
                if(baralla_creada == 1){
                    printf("%d",Partida_demanaCarta(&partida) );

                }
                else{
                    printf("Baralla no creada, no es pot jugar");
                }

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

void mostrarMenu() {
    printf("\nBlackjack\n");
    printf("\n 1. Generar pila de cartas");
    printf("\n 2. Jugar");
    printf("\n 3. Mostrar estadisticas");
    printf("\n 4. Salir\n");
}
void donar_cartes(Partida* p){

   int a =  Partida_DonarCartasC(p);
    a = Partida_DonarCartasC(p);
    a = Partida_DonarCartasJ(p);
    a = Partida_DonarCartasJ(p);
}
void imprimir_cartes(Partida *p){

    int cartes_crupier[11];
    int cartes_jugador[11];
    int i = 0;

    printf("Cartes jugador\n");
    while(i<11 && cartes_jugador[i] != 0){
        int carta = Partida_cartesJugador(p,i);
        if(carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        }
        else if(carta == 1) printf("[A]");
        else if(carta == 11)printf("[J]");
        else if(carta == 12)printf("[Q]");
        else if(carta == 13)printf("[K]");
        ++i;
    }

    i = 0;
    printf("\nCartes Crupier\n");
    while(i<11 && cartes_jugador[i] != 0){
        int carta = Partida_cartesCrupier(p,i);
        if(carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        }
        else if(carta == 1) printf("[A]");
        else if(carta == 11)printf("[J]");
        else if(carta == 12)printf("[Q]");
        else if(carta == 13)printf("[K]");

      ++i;
    }



}

