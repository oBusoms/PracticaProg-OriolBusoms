//
// Created by Oriol on 08/05/2018.
//

#include "baralla.h"
#include "pila.h"
#include "stdlib.h""





Baralla BARALLA_crea(int numero){
    Baralla b;
    b->p = PILA_crea();
    b->cartes = numero * 12;
    int barallasimple[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int barallaordenada[b->cartes];
    int j = 0;
    for(int i = 0; i<numero;++i){
        barallaordenada[j] = barallasimple[i];
        ++j;
    }
    bool usat[cartes];
    for(int i = 0; i<b->cartes; ++i){
        usat[i]=false;
    }
    for(int i = 0; i<b->cartes;++i){
        int numrandom = rand() % (b->cartes);
        if(!usat[numrandom]){
            PILA_push(*b->p,barallaordenada(numrandom));
            usat[numrandom] = true;
        }
    }
    return b;

}

int BARALLA_demanaCarta(Baralla *b){
    if(PILA_vacia(b->p)) return PILA_pop(b->p);
    else return 0;
}


