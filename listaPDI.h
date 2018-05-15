#ifndef _LISTAPDI_H_
#define _LISTAPDI_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
	int elemento;
	struct N *sig;
}Nodo;

typedef struct {
	Nodo *pri;
	Nodo *ant;
}ListaPDI;


ListaPDI LISTAPDI_crea();
ListaPDI LISTAPDI_inserta(ListaPDI l, int elemento);
ListaPDI LISTAPDI_elimina(ListaPDI l);
int LISTAPDI_consulta(ListaPDI l);
ListaPDI LISTAPDI_avanza(ListaPDI l);
ListaPDI LISTAPDI_vesInicio(ListaPDI l);
int LISTAPDI_final(ListaPDI l);
int LISTAPDI_vacia(ListaPDI l);
ListaPDI LISTAPDI_destruye(ListaPDI l);

#endif
