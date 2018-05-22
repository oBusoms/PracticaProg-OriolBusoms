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
    for(int i = 0; i<11; ++i){ //revisar per l'encapsulament
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



void Partida_imprimir_cartesJ(Partida *p) {

    int cartes_jugador[11];
    int i = 0;

    printf("\nCartes jugador\n");
    while (i < 11 && cartes_jugador[i] != 0) {
        int carta = Partida_cartesJugador(p, i);
        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
    }
}

void Partida_imprimir_cartesC(Partida *p) {

    int cartes_jugador[11];
    int i = 0;

    printf("\nCartes Crupier:\n");
    while (i < 11 && cartes_jugador[i] != 0) {
        int carta = Partida_cartesCrupier(p, i);
        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
    }
}

int Partida_sumadecartesC(Partida *p){

    int carta = Partida_cartesCrupier(p, 0);
    int i = 1;
    int SumaCarta = 0;
    while (i < 11 && carta!= 0) {
        if(carta == 11 || carta == 12 || carta == 13) carta = 10;
        if(carta == 1){
            if((SumaCarta + 11) < 21) carta = 11;
        }
        SumaCarta = SumaCarta + carta;
        carta = Partida_cartesCrupier(p, i);
        ++i;
    }
    return SumaCarta;
}

int Partida_sumadecartesJ(Partida *p){

    int carta = Partida_cartesJugador(p, 0);
    int i = 1;
    int SumaCarta = 0;
    while (i < 11 && carta!= 0) {
        if(carta == 11 || carta == 12 || carta == 13) carta = 10;
        if(carta == 1){
            if((SumaCarta + 11) < 21) carta = 11;
        }
        SumaCarta = SumaCarta + carta;
        carta = Partida_cartesJugador(p, i);
        ++i;
    }
    return SumaCarta;
}

int Partida_jugar(Partida *p){
    ///Juga Jugador///
    printf("\n\n\n\n\n\n\n"); //neteja la consola
    printf("BlackJarck - Jugar\n\n");
    Partida_DonarCartasJ(p);
    Partida_DonarCartasJ(p);
    Partida_imprimir_cartesJ(p);
    printf("\nVols carta?");
    int vc;
    scanf("%d",&vc);
    printf("\n");
    int suma = Partida_sumadecartesJ(p);
    while(vc == 1 && suma<21){
        Partida_DonarCartasJ(p);
        Partida_imprimir_cartesJ(p);
        suma = Partida_sumadecartesJ(p);
        if(suma<21) {
            printf("\nVols carta?");
            scanf("%d", &vc);
            printf("\n");
        }

    }

    ///Juga crupier///
    Partida_DonarCartasC(p);
    Partida_DonarCartasC(p);
    int sumaC = Partida_sumadecartesC(p);
    if(sumaC<17){
        while(sumaC<21) {

            Partida_imprimir_cartesC(p);

            if (sumaC < 17) {
                Partida_DonarCartasC(p);
            }
            sumaC = Partida_sumadecartesC(p) ;
        }

    }
    Partida_imprimir_cartesC(p);
    return 0;
}