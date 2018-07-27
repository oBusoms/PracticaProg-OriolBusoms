//
// Created by Oriol on 02/05/2018.
//

#ifndef PRACTICAPROG_PLAYER_H
#define PRACTICAPROG_PLAYER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int cartes[11];
    char nom[50];
    int fitxes;
    int ultimaCarta;
    int guanyades;
    int empatades;
    int perdudes;

}Player;

Player Player_crea(char nomFitxer[50]);
Player Player_iniciatlitza( Player p);
int PLAYER_SumaDeCartes(Player p);
void Player_DonarCartes(Player *p, int carta);
int Player_cartes(Player p, int i);
void Player_imprimir_cartes(Player p,int aposta);
char Player_getNom(Player* p);
int Player_nFitxes(Player p);
int Player_Aposta(Player *p);
int Player_SumaFitxes(Player *p, int fitxes);
int Player_guanya(Player p, int sumaCrupier);
void Player_guanyafitxes(Player p, int fitxes);
void Player_imprimir_cartes_final(Player p, int aposta, int guanya);
void Player_EstadistiquesActualitza(Player* p, int guanya, int perd, int empata);
void Player_ImprimirEstadistiques(Player p);
#endif //PRACTICAPROG_PLAYER_H
