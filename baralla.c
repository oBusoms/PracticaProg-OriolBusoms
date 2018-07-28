//
// Created by Oriol on 08/05/2018.
//

#include "baralla.h"

void swap(float *p, float *q)
{
    float d;

    d = *p;
    *p = *q;
    *q = d;
}

Baralla BARALLA_crea(int numero){
    Baralla b;
    b.p = PILA_crea(); //crea la pila buida
    b.cartes = numero * 13 * 4 ;
    int barallasimple[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};//definim una baralla simple
    int barallaordenada[b.cartes];
    int j = 0;
    while(j<b.cartes) {
        for (int i = 0;i < 13; ++i) { // creem una array de la mida de les baralles i l'omplim de les cartes ordenades
            barallaordenada[j] = barallasimple[i];
            j = j +1;
        }
    }
    srand(time(NULL));
    for(int i = 0; i<b.cartes;++i){

        int numrandom = rand() % (b.cartes);
        swap(&barallaordenada[i],&barallaordenada[numrandom]);
    }
   for(int i = 0; i<b.cartes;++i){
        //printf("%d ",barallaordenada[i]);
        PILA_push(&b.p,barallaordenada[i]);
    }
    return b;
}


int BARALLA_demanaCarta(Baralla *b){
    if((PILA_vacia(b->p))){
        return 0;
    }
    else {
        int num = PILA_top(b->p);
        PILA_pop(&b->p);
        return num;
    }
}


void Baralla_borra(Baralla *b){

    PILA_destruye(&b->p);

}
