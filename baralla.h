//
// Created by Oriol on 08/05/2018.
//

#ifndef PRACTICAPROG_BARALLA_H
#define PRACTICAPROG_BARALLA_H
#include "Pila.h"
#include "stdlib.h"
#include "time.h"

typedef struct{
    Pila p;
    int cartes;
}Baralla;


Baralla BARALLA_crea(int numero);

int BARALLA_demanaCarta(Baralla *b);

void Baralla_borra(Baralla *b);
#endif //PRACTICAPROG_BARALLA_H


