//
// Created by Oriol on 02/05/2018.
//
#include "Bot.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int BOT_crea(Bot *b) { //b es el punter de l'array de bots

    char nom[50];
    int fitxes = 0;
    int cartaMax = 0;
    int victories = 0;
    int derrotes = 0;
    int empates = 0;
    int numeroBots = 0;
    int fitxesBot = 0;
    char estrategia[50];
    char aux[5];
    int n;
    FILE * fi=fopen("bots.txt","r");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fscanf(fi, "%i", &numeroBots);
        fscanf(fi, "%c", &aux[0]);
 
        for (int i =0; i<=numeroBots; i++){
            while (!feof(fi)) {
 
                fgets(nom, 50, fi);
                n = strlen(nom);
                nom[n-1] = '\0';
                fscanf(fi, "%d", &fitxesBot);
                fscanf(fi, "%c", &aux[0]);
                fgets(estrategia, 50, fi);
                n = strlen(estrategia);
                estrategia[n-1] = '\0';
                fscanf(fi, "%c", &estrategia);
                fscanf(fi, "%c", &aux[0]);
                //revisar per l'encapsulament///////////////////////////////////////////////////////////////////////////
                strcpy(b[i].nom, nom);
                strcpy(b[i].estrategia, estrategia);
                b[i].fitxes=fitxesBot;
                b[i].cartaMax=cartaMax;
                b[i].victories=0;
                b[i].empates=0;
                b[i].derrotes=0;
            }
        }
 
 
        fclose(fi);
    }
    return numeroBots;


    
}