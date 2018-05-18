//
// Created by Oriol on 02/05/2018.
//
#include "Partida.h"


Partida Partida_crea(int numBots){

    Partida p;

    //for(int i = 0; i < numBots; ++i){
     /*   while(LISTAPDI_final(p.bots) == 0){
        Bot_crea(LISTAPDI_consulta(p.bots));
        LISTAPDI_avanza(p.bots);
    }*/
    for(int i = 0; i<11; ++i){
        p.crupier.fitxes[i]=0;
        p.player.fitxes[i]=0;
    }

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

int Partida_cartesJugador(Partida *p, int i){
    return p->player.fitxes[i];
}

int Partida_cartesCrupier(Partida *p, int i){
    return p->crupier.fitxes[i];
}

int Partida_DonarCartasJ(Partida *p){
    int i = 0;
    while(p->player.fitxes[i] != 0){
        ++i;
    }
    p->player.fitxes[i] = Partida_demanaCarta(p);
    return 1;
}
int Partida_DonarCartasC(Partida *p){
    int i = 0;
    while(p->crupier.fitxes[i] != 0){
        ++i;
    }
    p->crupier.fitxes[i] = Partida_demanaCarta(p);
    return 1;

}