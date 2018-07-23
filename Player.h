//
// Created by Oriol on 02/05/2018.
//

#ifndef PRACTICAPROG_PLAYER_H
#define PRACTICAPROG_PLAYER_H
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int cartes[11];
    char nom[50];
    int punts;
    int ultimaCarta;

}Player;

Player Player_crea();
Player Player_iniciatlitza( Player p);
int PLAYER_SumaDeCartes(Player p);
void Player_DonarCartes(Player *p, int carta);
int Player_cartes(Player p, int i);
#endif //PRACTICAPROG_PLAYER_H
