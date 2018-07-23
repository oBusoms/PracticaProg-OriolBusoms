//
// Created by Oriol on 02/05/2018.
//

#include "Player.h"

Player Player_crea(){
    Player player;
    return player;
}


Player Player_iniciatlitza( Player p){
    for(int i = 0; i<11; ++i){
        p.cartes[i] = 0;
    }
    p.ultimaCarta = 0;
}


int PLAYER_SumaDeCartes(Player p){
    int carta = Player_cartes(p, 0);
    int i = 1;
    int SumaCarta = 0;
    while (i < 11 && carta!= 0) {
        if(carta == 11 || carta == 12 || carta == 13) carta = 10;
        if(carta == 1){
            if((SumaCarta + 11) < 21) carta = 11;
        }
        SumaCarta = SumaCarta + carta;
        carta = Player_cartes(p, i);
        ++i;
    }
    return SumaCarta;
}


int Player_cartes(Player p, int i){
    return p.cartes[i];
}

void Player_DonarCartes(Player *p, int carta){

    p->cartes[p->ultimaCarta] = carta;
    ++p->ultimaCarta;
}
