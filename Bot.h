//
// Created by Oriol on 02/05/2018.
//

#ifndef PRACTICAPROG_BOT_H
#define PRACTICAPROG_BOT_H


typedef struct{
    char nom[50];
    int fitxes ;
    int cartaMax;
    int victories;
    int derrotes;
    int empates;
    char estrategia[50];
    int cartes[11];

}Bot;


int BOT_crea(Bot *b, char nomFitxer[50]);
int BOT_CartaMax(Bot b);
int BOT_apostar(Bot* b);
int BOT_demanacartes(int carta, Bot *b);
int BOT_consultaFitxes(Bot b);
void BOT_ImpNom(Bot b);
int BOT_caracter(Bot b);
int BOT_sumadecartesB(Bot b);
void BOT_imprimir_cartes(Bot b, int aposta);
int BOT_guanya(Bot b, int sumaCrupier);
void BOT_guanyaAposta(Bot* b, int fitxes);
int BOT_cartes(Bot b, int i);
void BOT_imprimir_cartes_final(Bot b, int aposta, int guanya);
int BOT_Cartes(Bot b, int i);
#endif //PRACTICAPROG_BOT_H
