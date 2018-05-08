//
// Created by Oriol on 08/05/2018.
//

#ifndef _PILA_H_
#define _PILA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int elemento;
    struct N *sig;
}Nodo;

typedef Nodo *Pila;



Pila PILA_crea();
void PILA_push(Pila *p, int elemento);
void PILA_pop(Pila *p);
int PILA_top(Pila p);
int PILA_vacia(Pila p);
void PILA_destruye(Pila *p);

#endif
