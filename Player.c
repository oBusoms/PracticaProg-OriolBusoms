//
// Created by Oriol on 02/05/2018.
//

#include "Player.h"

Player Player_crea(char nomFitxer[50]){
    Player player;
    FILE *fitxer;
    //fitxer = fopen(nomFitxer, "r");
    fitxer = fopen("C:\\Users\\Oriol\\CLionProjects\\PracticaProg\\jugador.txt", "r");
    if (fitxer != NULL) {
        fgets(player.nom, 50, fitxer);
        int n = strlen(player.nom);
        player.nom[n-1] = '\0';
        fscanf(fitxer, "%i", &player.fitxes);
        fscanf(fitxer, "%i", &player.guanyades);
        fscanf(fitxer, "%i", &player.empatades);
        fscanf(fitxer, "%i", &player.perdudes);
        return player;
    }
    else{
        printf("**Error en la lectura del Jugador**\n");
        return player;
    }


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

void Player_imprimir_cartes(Player p, int aposta){


    int i = 0;
    int carta = Player_cartes(p, i);
    printf("\n");
    printf(p.nom);
    printf("                       %dfch\n", aposta);
    while (i < 11 && carta != 0) {

        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
        carta = Player_cartes(p, i);
    }

    printf("\n----------------------------------------");
}

char Player_getNom(Player* p){
    return p->nom;
}


int Player_nFitxes(Player p){
    return p.fitxes;
}


int Player_Aposta(Player *p){

    printf("Introdueix la teva aposta: (20 - 1000 ftx)\n");
    int aposta ;
    scanf("%d", &aposta);
    while(aposta < 20 || aposta > 1000){
        printf("Aposta incorrecte, torna a apostar: \n");
        scanf("%d", &aposta);
    }
    p->fitxes -= aposta;
    return aposta;
}

int Player_SumaFitxes(Player *p, int fitxes){
    p->fitxes += fitxes;
}



int Player_guanya(Player p, int sumaCrupier) {

    int sumap = PLAYER_SumaDeCartes(p);
    if (sumaCrupier > 21 && sumap < 21) return 1;
    else if (sumap > 21) return 0;
    else if (sumap > sumaCrupier) return 1;
}

void Player_guanyafitxes(Player p, int fitxes){
   if(p.cartes[2]==0) p.fitxes += 3*fitxes;
    else p.fitxes += 3*fitxes;
}