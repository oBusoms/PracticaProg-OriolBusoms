//
// Created by Oriol on 02/05/2018.
//

#ifndef PRACTICAPROG_CRUPIER_H
#define PRACTICAPROG_CRUPIER_H

#include <stdio.h>
typedef struct{
    int cartes[11];
    int punts;
    int ultimaCarta;
    int ESTcartes[7];
    int partidesJugades;
}Crupier;

Crupier Crupier_crea();

Crupier Crupier_inicialitza(Crupier c);

int Crupier_SumaDeCartes(Crupier c);
void Crupier_DonarCartes(Crupier *c, int carta);
int Crupier_cartes(Crupier c, int i);
void Crupier_Estadistiques(Crupier* c, int i);
void Crupier_EstadistiquesCrupier(Crupier c);

#endif //PRACTICAPROG_CRUPIER_H
