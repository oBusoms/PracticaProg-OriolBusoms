//
// Created by Oriol on 08/05/2018.
//

#include "baralla.h"






Baralla BARALLA_crea(int numero){
    Baralla b;
    b.p = PILA_crea(); //crea la pila buida
    b.cartes = numero * 12 ;
    int barallasimple[12] = {1,2,3,4,5,6,7,8,9,10,11,12};//definim una baralla simple
    int barallaordenada[b.cartes];
    int j = 0;
    while(j<b.cartes) {
        for (int i = 0;i < 12; ++i) { // creem una array de la mida de les baralles i l'omplim de les cartes ordenades
            barallaordenada[j] = barallasimple[i];
            j = j +1;
        }
    }
    printf("\n");
    int usat[b.cartes];
    for(int i = 0; i<b.cartes; ++i){
        usat[i]=0;
    }

    int queden  = 1;

    while(queden == 1){
        int numrandom = rand() % (b.cartes);

        if(usat[numrandom] == 0){
            PILA_push(&b.p,barallaordenada[numrandom]);
            printf("%d - ",barallaordenada[numrandom]);
            usat[numrandom] = 1;
        }
        int trobat = 0; //busquem numeros no usats
        int q = 0;
        while(trobat == 0 && q < b.cartes){ //si trobem un que no esta usat, seguim colocantlos
            if(usat[q] == 0){
                trobat = 1; //si quan acabem el bucle, trobat == 1, es pq encara queden
            }

            ++q;
        }

        if(trobat == 0) queden = 0;

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

void hola(){
    printf("Hola");
}
