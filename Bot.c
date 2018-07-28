//
// Created by Oriol on 02/05/2018.
//
#include "Bot.h"
#include <stdio.h>
#include <string.h>

int BOT_crea(Bot *b) { //b es el punter de l'array de bots

    char nom[50];
    int fitxes = 0;
    int victories = 0;
    int derrotes = 0;
    int empates = 0;
    int numeroBots = 0;

    char aux[5];
    int n;
    FILE * fi=fopen("C:\\Users\\Oriol\\CLionProjects\\PracticaProg\\botsq.txt","r");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fscanf(fi, "%i", &numeroBots);
        fscanf(fi, "%c", &aux[0]);
 
        for (int i =0; i<numeroBots; i++){

            int cartaMax = 0;
            int fitxesBot = 0;
            char estrategia[50];
            char nom[50];
                fgets(nom, 50, fi);
                n = strlen(nom);
                nom[n-1] = '\0';
                fscanf(fi, "%d", &fitxesBot);
                fscanf(fi, "%c", &aux[0]);
                fgets(estrategia, 50, fi);
                n = strlen(estrategia);
                estrategia[n-1] = '\0';
                fscanf(fi, "%d", &cartaMax);
                   fscanf(fi, "%c", &aux[0]);

                //revisar per l'encapsulament///////////////////////////////////////////////////////////////////////////
                strcpy(b[i].nom, nom);
                strcpy(b[i].estrategia, estrategia);
                b[i].fitxes=fitxesBot;
                b[i].cartaMax=cartaMax;
                b[i].victories=0;
                b[i].empates=0;
                b[i].derrotes=0;
                for(int j = 0; j<11; ++j){
                    b[i].cartes[j] = 0;
                }
            }


 
 
        fclose(fi);
       // ordenarBots(b,numeroBots);
    }
    return numeroBots;


    
}


void ordenarBots(Bot *b, int numeroBots){

        int i,j;
    i = j = 0;
    for (i = 0; i < numeroBots - 1; i++){
        for (j = i + 1; j < numeroBots; j++){
            if (strcmp(b[i].nom, (b[j].nom))){
                /* Intercambiar el valor de alumno[i] y alumno[j] */
                 Bot aux = b[i];
                b[i] = b[j];
                b[j] = aux;
            }
        }
    }
}

int BOT_apostar(Bot * b) {

    int opcio;
    int aposta = 0;
    if(strcmp(b->estrategia,"Fuerte")) opcio = 0;
    else if(strcmp(b->estrategia,"Normal")) opcio = 1;
    else if(strcmp(b->estrategia,"Debil")) opcio = 2;

    switch (opcio) {
        case 0:
            if(b->fitxes < 100){
                aposta = -1;
            } else {
                aposta = 100;
                b->fitxes -= 100;
            }
            break;

        case 1:
            if(b->fitxes < 500){
                aposta = -1;
            } else {
                aposta = 500;
                b->fitxes -= 500;
            }
            break;

        case 2:
            if(b->fitxes < 900){
                aposta = -1;
            } else {
                aposta = 900;
                b->fitxes -= 900;
            }
            break;
        default:
            break;
    }
    return aposta;
}


int BOT_consultaCartas(Bot b) {
  return b.cartes;
}

int BOT_demanacartes(int carta, Bot *b){
    int ultima = 0;
    int i = 0;
    int Notrobat = 1;
    while(i < 11 && Notrobat == 1){
        if(b->cartes[i] == 0){
            ultima = i;
            Notrobat = 0;
        }
        ++i;
    }
    b->cartes[ultima] = carta;

}

void BOT_ImpNom(Bot b){

    printf(b.nom);
}

int BOT_caracter(Bot b){
    if(strcmp(b.estrategia,"Fuerte")) return 2;
    else if(strcmp(b.estrategia,"Normal")) return 1;
    else if(strcmp(b.estrategia,"Debil")) return 0;
}

int BOT_sumadecartesB(Bot b){
    int i = 0;
    int suma = 0;
    while(b.cartes[i] != 0){
        suma += b.cartes[i];
        ++i;
    }
    return suma;
}

int BOT_CartaMax(Bot b){
    return b.cartaMax;
}

void BOT_imprimir_cartes(Bot b, int aposta) {

    int i = 0;
    printf("\n");
    int carta = b.cartes[0];
    printf(b.nom);
    printf("                         %d",aposta);
    printf("fch\n");
    //printf("\n");
    while (i < 11 && carta != 0) {

        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
        carta = b.cartes[i];
    }
    printf("\n----------------------------------------");
}

void BOT_imprimir_cartes_final(Bot b, int aposta, int guanya) {

    int i = 0;
    printf("\n");
    int carta = b.cartes[0];
    printf(b.nom);
    printf("                      %d",aposta);
    printf(" fch\n");
    //printf("\n");
    while (i < 11 && carta != 0) {

        if (carta != 1 && carta != 11 && carta != 12 && carta != 13 && carta != 0) {
            printf("[%d]", carta);
        } else if (carta == 1) printf("[A]");
        else if (carta == 11)printf("[J]");
        else if (carta == 12)printf("[Q]");
        else if (carta == 13)printf("[K]");
        ++i;
        carta = b.cartes[i];
    }

    printf("                            (");
    int sumadcartes = BOT_sumadecartesB(b);
    printf("%d",sumadcartes);
    if(BOT_cartes(b,2) == 0 && (BOT_cartes(b,0)+ BOT_cartes(b,1) == 21)){
        printf("B)");
    }
    else printf(")\n");
    if(guanya){
        printf("** Gana (+");
        if(sumadcartes == 21 && BOT_cartes(b,2) == 0){
            printf("%d",3*aposta);
            printf(" fch) **");
        }
        else{
            printf("%d",2*aposta);
            printf(" fch) **");
        }
    }else {
        printf("** Pierde (-");
        printf("%d",aposta);
        printf(" fch) **");
    }
    printf("\n----------------------------------------");
}
int BOT_cartes(Bot b, int i){
    return b.cartes[i];
}

int BOT_consultaFitxes(Bot b){
    return b.fitxes;
}

int BOT_guanya(Bot b, int sumaCrupier){

    int sumaBot = BOT_sumadecartesB(b);
    if(sumaCrupier > 21 && sumaBot<21) return 1;
    else if(sumaBot > 21) return 0;
    else if( sumaBot>sumaCrupier) return 1;
}


void BOT_guanyaAposta(Bot* b, int fitxes){

    if(b->cartes[2] == 0 && BOT_sumadecartesB(*b) == 21)  b->fitxes += 3*fitxes;
   else b->fitxes += 2*fitxes;
}