//
// Created by Oriol on 02/05/2018.
//

#ifndef PRACTICAPROG_PARTIDA_H
#define PRACTICAPROG_PARTIDA_H

#include "baralla.h"
#include "Bot.h"
#include "Crupier.h"
#include "Player.h"

/*
 * En aquest modul es guardara l'estat de la partida, les fitxes de cada jugador, es jugara
 * una raonda i es guardara els resultats d'aquesta
 *
 *
 */

typedef struct{
    Bot bots[10];
    Player player;
    Crupier crupier;
    Baralla baralla;
    int numero_Cartes;
}Partida;

int Partida_generarBaralla(Partida *p, int numBaralla); // genera una baralla i retorna un int/bolea que val 1 si esta creada i 0 si no
Partida Partida_crea(int numBots);
void Partida_borraBaralla(Partida *p);
int Partida_demanaCarta(Partida *p);
#endif //PRACTICAPROG_PARTIDA_H
