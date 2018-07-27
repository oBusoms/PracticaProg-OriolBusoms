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
    for(int i = 0; i<7; ++i){
        p.ESTcartes[i] = 0;
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

void Crupier_Estadistiques(Crupier* c, int i){
    if(i == 7) c->partidesJugades += 1;
    else c->ESTcartes[i] += 1;
}

void Crupier_EstadistiquesCrupier(Crupier c){

    printf("BlackJack - Estadisticas del crupier\n\n");
    printf("Valor        Porcentaje\n");
    printf("-----------------------------------------------------------------\n");
        printf("17        ");
        float porcen = 0;
        if(c.partidesJugades != 0 && c.ESTcartes[0]!=0){
             porcen = c.ESTcartes[0]*100 / c.partidesJugades ;
        }
        printf("%f", porcen);
        printf("\n");

    porcen = 0;
        printf("18        ");
        porcen = 0;
        if(c.partidesJugades != 0 && c.ESTcartes[1]!=0){
            porcen = c.ESTcartes[1]*100 / c.partidesJugades ;
        }
        printf("%f", porcen);
        printf("\n");
    porcen = 0;
    printf("19        ");
    porcen = 0;
    if(c.partidesJugades != 0 && c.ESTcartes[2]!=0){
        porcen = c.ESTcartes[2]*100 / c.partidesJugades ;
    }
    printf("%f", porcen);
    printf("\n");
    porcen = 0;
    printf("20        ");
    porcen = 0;
    if(c.partidesJugades != 0 && c.ESTcartes[3]!=0){
        porcen = c.ESTcartes[3]*100 / c.partidesJugades ;
    }
    printf("%f", porcen);
    printf("\n");
    porcen = 0;
    printf("21        ");
    porcen = 0;
    if(c.partidesJugades != 0 && c.ESTcartes[4]!=0){
        porcen = c.ESTcartes[4]*100 / c.partidesJugades ;
    }
    printf("%f", porcen);
    printf("\n");
    porcen = 0;
    printf("21B       ");
    porcen = 0;
    if(c.partidesJugades != 0 && c.ESTcartes[5]!=0){
        porcen = c.ESTcartes[5]*100 / c.partidesJugades ;
    }
    printf("%f", porcen);
    printf("\n");
    porcen = 0;
    printf(">21       ");
    porcen = 0;
    if(c.partidesJugades != 0 && c.ESTcartes[6]!=0){
        porcen = c.ESTcartes[6]*100 / c.partidesJugades ;
    }
    printf("%f", porcen);
    printf("\n");

}