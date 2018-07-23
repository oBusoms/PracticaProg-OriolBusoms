//
// Created by Oriol on 02/05/2018.
//

#include "Crupier.h"

Crupier Crupier_crea(){
    Crupier crupier;
    return crupier;
}

Crupier Crupier_inicialitza(Crupier p){
    for(int i = 0; i<11; ++i){
        p.cartes[i] = 0;
    }
    return p;
}

int Crupier_cartes(Crupier c, int i){

    return c.cartes[i];
}

int Crupier_SumaDeCartes(Crupier c){



    int carta = Crupier_cartes(c, 0);
    int i = 1;
    int SumaCarta = 0;
    while (i < 11 && carta!= 0) {
        if(carta == 11 || carta == 12 || carta == 13) carta = 10;
        if(carta == 1){
            if((SumaCarta + 11) < 21) carta = 11;
        }
        SumaCarta = SumaCarta + carta;
        carta = Crupier_cartes(c, i);
        ++i;
    }
    return SumaCarta;
}

void Crupier_DonarCartes(Crupier *c, int carta){

    c->cartes[c->ultimaCarta] = carta;
    ++c->ultimaCarta;
}

