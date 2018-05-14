//
// Created by Oriol on 08/05/2018.
//

#ifndef PRACTICAPROG_BARALLA_H
#define PRACTICAPROG_BARALLA_H
#include "Pila.h"
#include "stdlib.h"

typedef struct{
    Pila p;
    int cartes;
}Baralla;


void hola();
Baralla BARALLA_crea(int numero);

int BARALLA_demanaCarta(Baralla *b);


#endif //PRACTICAPROG_BARALLA_H


