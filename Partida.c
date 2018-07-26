//
// Created by Oriol on 02/05/2018.
//
#include "Partida.h"
#include "Player.h"
#include "Bot.h"


Partida Partida_crea(char* array[3]){

    Partida p;
    p.numeroBots = BOT_crea(&p.bots);
    p.player = Player_crea(array[1]);
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


    int i = 0;
    int carta = Player_cartes(p->player, i);
    printf("\nJugador\n");
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

    printf("\n----------------------------------------");
}

void Partida_imprimir_cartesC(Partida *p) {

    int cartes_jugador[11];
    int i = 0;

    printf("\nCrupier:\n");
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
    printf("\n----------------------------------------");
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
    for(int j = 0; j<Partida_numeroBots(p); ++j){
        for(int q = 0; q<11;++q){
            p->bots[j].cartes[q] = 0;
        }
    }
}



int Partida_jugar(Partida *p){

    ///////Apuestas //////////
    int apuestaJ = Player_Aposta(&p->player);
    int apostaBot[Partida_numeroBots(p)];
    int numeroBots = Partida_numeroBots(p);
    for(int i = 0; i<numeroBots;++i){

       apostaBot[i] = BOT_apostar(&p->bots[i]);
    }
    /////PRimera ronda de cartes/////
    Partida_DonarCartasC(p);
    Partida_DonarCartasC(p);

    for(int i = 0; i<numeroBots;++i){
        if(BOT_consultaFitxes(p->bots[i])>=20){
            Partida_DonarCartasB(p,i);
            Partida_DonarCartasB(p,i);
        }

    }

    Partida_DonarCartasJ(p);
    Partida_DonarCartasJ(p);

/////IMPRESIO DE CARTES//////////
    Partida_imprimir_cartesC(p);
    for(int i = 0; i<numeroBots;++i) {

        BOT_imprimir_cartes(p->bots[i],apostaBot[i]);

    }
    Player_imprimir_cartes(p->player,apuestaJ);

    /////////JOC////////
    int plantat = 0;
    int passar = 0;
    int passat = 0;
    int Crupierpassat = 0;
    int botsPassats[numeroBots];
    int botsPlantats[numeroBots];
    for(int i = 0; i<numeroBots;++i)botsPlantats[i]= 0;
    for(int i = 0; i<numeroBots; ++i) botsPassats[i] = 0;
    while(passat == 0 && Crupierpassat == 0 && plantat ==0) {
        if(PLAYER_SumaDeCartes(p->player)<21) {
            int opcio = imprimirMenu(&p->player);

            if (opcio == 1)Partida_DonarCartasJ(p);
            else if (opcio == 2) plantat = 1;
            else if (opcio == 3) passar = 1;
            else if (opcio == 4) return 0;

        }else {
            passat = 1;
            printf("\n T'has passat\n");
        }
        //JUGUEN BOTS///
        for (int i = 0; i <numeroBots; ++i) {
            if (BOT_consultaFitxes(p->bots[i]) >= 20 && botsPassats[i] == 0 && botsPlantats[i] == 0) {
                if (BOT_caracter(p->bots[i]) == 0) {
                    while (BOT_sumadecartesB(p->bots[i]) <= BOT_CartaMax(p->bots[i])) {
                        Partida_DonarCartasB(p, i);
                    }
                    if(BOT_sumadecartesB(p->bots[i]) > BOT_CartaMax(p->bots[i])) botsPlantats[i] = 1;



                    ////Si el caracter es NORMAL /////

                } else if (BOT_caracter(p->bots[i]) == 1) {
                    int passaturn = 0;
                    while (BOT_sumadecartesB(p->bots[i]) <= BOT_CartaMax(p->bots[i]) && passaturn == 0) {
                        if (BOT_sumadecartesB(p->bots[i]) % 2)Partida_DonarCartasB(p, i);
                        else{
                            passaturn = 1;
                            botsPlantats[i] = 1;
                        }
                    }

                }
                    ////Si el caracter es FUERTE /////
                else if (BOT_caracter(p->bots[i]) == 2) {
                    int passaturn = 0;
                    while (BOT_sumadecartesB(p->bots[i]) <= BOT_CartaMax(p->bots[i]) && passaturn == 0) {
                        if (BOT_sumadecartesB(p->bots[i]) <= p->manoMax)Partida_DonarCartasB(p, i);
                        else {
                             passaturn = 1;
                            botsPlantats[i] = 1;
                     }
                    }
                }
            }
            if(BOT_sumadecartesB(p->bots[i])>21) botsPassats[i] = 1;
        }

        /////////JUGA CRUPIER ////////////////
        int crupierPlantat = 0;
        int sumaC = Partida_sumadecartesC(p);
        if(sumaC<=17){

            Partida_DonarCartasC(p);

        }
        else crupierPlantat = 1;


        int totsPlantats = 1;

        for(int i = 0; i<numeroBots; ++i){
            if(botsPlantats[i]==0) totsPlantats=0;
        }
        if(crupierPlantat == 0) totsPlantats=0;
        if(plantat == 0) totsPlantats =0;






        Partida_imprimir_cartesC(p);
        for (int i = 0; i <numeroBots; ++i) {

            BOT_imprimir_cartes(p->bots[i],apostaBot[i]);

        }
        Player_imprimir_cartes(p->player, apuestaJ);
    }
    /////Fi de partida//////

    ///Bots///

    for(int i = 0; i<numeroBots; ++i){
       if( BOT_guanya(p->bots[i], Crupier_SumaDeCartes(p->crupier))){
           BOT_guanyaAposta(&p->bots[i],apostaBot[i]);
           printf("\n El bot ");
           printf(p->bots[i].nom);
           printf(" guanya\n");
       }
    }

    if(Player_guanya(p->player, Crupier_SumaDeCartes(p->crupier))){
        Player_guanyafitxes(p->player, apuestaJ);
        printf("Jugador guanya");
    }
    Partida_borra_cartes(p);
    return 0;
}

void actualitzaMaMax( int ma, Partida *p){
    if(p->manoMax < ma && ma < 22)  p->manoMax = ma;
}

int imprimirMenu(Player* p){

    printf("\n");
    ///Encapsulacio
    //printf(Player_getNom(&p));
    printf((p->nom));

    printf(", elije:\n");
    printf("    1. Perdir carta\n");
    printf("    2. Plantarse\n");
    printf("    3. Rendirse\n");
    printf("    4. Abandonar partida\n");
    printf("Opcion: ");
    int opcio;
    scanf("%d", &opcio);
    return opcio;
}


int Partida_numeroBots(Partida *p){
    return p->numeroBots;
}

