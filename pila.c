//
// Created by Oriol on 08/05/2018.
//

#include "pila.h"

Pila PILA_crea() {
    Pila p;

    p = NULL;

    return p;
}

void PILA_push(Pila *p, int elemento) {
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if (aux == NULL) {
        printf("\nError al hacer push...\n");
    } else {
        aux->elemento = elemento;
        aux->sig = *p;
        *p = aux;
    }
}


void PILA_pop(Pila *p) {
    Nodo *aux;

    if (*p == NULL) {
        printf("\nError al hacer pop, la pila està vacía.\n");
    } else {
        aux = *p;
        *p = (*p)->sig;
        free(aux);
    }

}

int PILA_top(Pila p) {
    int elemento = -1;
    if (p==NULL) {
        printf("\nError al hacer top, la pila está vacía.\n");
    } else {
        elemento = p->elemento;
    }
    return elemento;
}

int PILA_vacia(Pila p) {
    return p == NULL;
}

void PILA_destruye(Pila *p) {
    Nodo *aux;
    while (*p != NULL) {
        aux = *p;
        *p = (*p)->sig;
        free(aux);
    }

}


