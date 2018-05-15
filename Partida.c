//
// Created by Oriol on 02/05/2018.
//
#include "Partida.h"


Partida Partida_crea(int numBots){

    Partida p;

    for(int i = 0; i < numBots; ++i){
        p.bots[i] = Bot_crea();
    }
    p.crupier = Crupier_crea();
   p.player = Player_crea();
    return p;
}


int Partida_generarBaralla(Partida *p, int numBaralla){
   p->baralla = BARALLA_crea(numBaralla);
    p->numero_Cartes = numBaralla;
    return 1;
}

void Partida_borraBaralla(Partida *p){
    Baralla_borra(&p->baralla);
}

int Partida_demanaCarta(Partida *p){

    int carta = BARALLA_demanaCarta(&p->baralla);
    if(carta == 0){
        Partida_borraBaralla(p);
       int aa = Partida_generarBaralla(p, p->numero_Cartes);
        carta = BARALLA_demanaCarta(&p->baralla);
    }

    return carta;
}