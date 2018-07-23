//
// Created by Oriol on 02/05/2018.
//
#include "Partida.h"



Partida Partida_crea(){

    Partida p;
    p.numeroBots = BOT_crea(&p.bots);
    Player_iniciatlitza(p.player);
    Crupier_inicialitza(p.crupier);
    p.manoMax = 0;

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

int Partida_cartesCrupier(Partida *p, int i){
    return p->crupier.cartes[i];
}

int Partida_DonarCartasJ(Partida *p){
            Player_DonarCartes(&p->player,  Partida_demanaCarta(p));
            actualitzaMaMax( Partida_sumadecartesJ(p), p);
    return 1;
}
int Partida_DonarCartasC(Partida *p){

    Crupier_DonarCartes(&p->crupier, Partida_demanaCarta(p));
    actualitzaMaMax( Partida_sumadecartesC(p), p);
    return 1;
}

int Partida_DonarCartasB(Partida *p, int i){

    BOT_demanacartes(Partida_demanaCarta(p), &p->bots[i]);
    actualitzaMaMax(BOT_sumadecartesB(p->bots[i]),p);

}





void Partida_imprimir_cartesJ(Partida *p) {

    int cartes_jugador[11];
    int i = 0;
    int carta = Player_cartes(p->player, i);
    printf("\nCartes jugador\n");
    while (i < 11 && carta != 0) {

        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
         carta = Player_cartes(p->player, i);
    }
}

void Partida_imprimir_cartesC(Partida *p) {

    int cartes_jugador[11];
    int i = 0;

    printf("\nCartes Crupier:\n");
    int carta = Crupier_cartes(p->crupier, i);
    while (i < 11 && carta != 0) {

        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
        carta = Crupier_cartes(p->crupier, i);
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

    int carta = Player_cartes(p->player, 0);
    int i = 1;
    int SumaCarta = 0;
    while (i < 11 && carta!= 0) {
        if(carta == 11 || carta == 12 || carta == 13) carta = 10;
        if(carta == 1){
            if((SumaCarta + 11) < 21) carta = 11;
        }
        SumaCarta = SumaCarta + carta;
        carta = Player_cartes(p->player, i);
        ++i;
    }
    return SumaCarta;
}

void Partida_borra_cartes(Partida *p){

    for(int i = 0; i<11; ++i){ //revisar per l'encapsulament
        p->crupier.cartes[i]=0;
        p->player.cartes[i]=0;
    }
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
    if(sumaC<=17){
        int fitorn = 0;
        while(sumaC<21 && fitorn == 0) {

            Partida_imprimir_cartesC(p);

            if (sumaC <= 17) {
                Partida_DonarCartasC(p);
            }
            else fitorn = 1;
            sumaC = Partida_sumadecartesC(p) ;
        }

    }
    Partida_imprimir_cartesC(p);


    /////JUGA bots/////
        printf("\nBOTS:\n");
        for(int i = 0; i<p->numeroBots;++i){

            int aposta = BOT_apostar(&p->bots[i]);

            if(aposta != -1 ){
                printf("\n");
                BOT_ImpNom(p->bots[i]);
                Partida_DonarCartasB(p,i);
                Partida_DonarCartasB(p,i);
                ////SI el caracter es debil //////////
                if(BOT_caracter(p->bots[i]) == 0){
                    while(BOT_sumadecartesB(p->bots[i]) <=  BOT_CartaMax(p->bots[i])){
                        Partida_DonarCartasB(p,i);
                    }

                   ////Si el caracter es NORMAL /////

                }else if (BOT_caracter(p->bots[i]) == 1) {
                    int passaturn = 0;
                    while (BOT_sumadecartesB(p->bots[i]) <= BOT_CartaMax(p->bots[i]) && passaturn == 0) {
                        if (BOT_sumadecartesB(p->bots[i]) % 2)Partida_DonarCartasB(p, i);
                        else passaturn = 1;
                    }

                }
                ////Si el caracter es FUERTE /////
                }else if (BOT_caracter(p->bots[i]) == 2) {
                int passaturn = 0;
                    while (BOT_sumadecartesB(p->bots[i]) <= BOT_CartaMax(p->bots[i]) && passaturn == 0) {
                        if (BOT_sumadecartesB(p->bots[i]) <= p->manoMax )Partida_DonarCartasB(p, i);
                        else passaturn = 1;
                }
            }

            BOT_imprimir_cartes(p->bots[i]);




        }


    Partida_borra_cartes(p);
    return 0;
}

void actualitzaMaMax( int ma, Partida *p){
    if(p->manoMax < ma && ma < 22)  p->manoMax = ma;
}