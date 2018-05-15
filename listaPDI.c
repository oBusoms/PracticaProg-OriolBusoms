#include "listaPDI.h"

ListaPDI LISTAPDI_crea() {
	ListaPDI l;

	l.pri = (Nodo*)malloc(sizeof(Nodo));
	if (l.pri == NULL) {
		printf("\nError al crear la lista...\n");
	} else {
		l.ant = l.pri;
		l.pri->sig = NULL;
		l.pri->elemento = -1; // FANTASMA, ELEMENTO_indefinido();
	}

	return l;
}

ListaPDI LISTAPDI_inserta(ListaPDI l, int elemento) {
	Nodo *aux;

	aux = (Nodo*)malloc(sizeof(Nodo));
	if (aux == NULL) {
		printf("\nError al insertar en la lista...\n");
	} else {
		aux->elemento = elemento;
		aux->sig = l.ant->sig;
		l.ant->sig = aux;
		 l.ant = aux; // para mantener el PDI
	}
	return l;
}

ListaPDI LISTAPDI_elimina(ListaPDI l) {
	Nodo *aux;

	if (l.ant->sig == NULL) {
		printf("\nError al eliminar, el PDI está al final...\n");
	} else {
		aux = l.ant->sig;
		l.ant->sig = aux->sig; // l.ant->sig->sig;
		free(aux);
	}
	return l;
}



int LISTAPDI_consulta(ListaPDI l) {
	int elemento;
	if (l.ant->sig == NULL) {
		printf("\nError al consultar, el PDI está al final...\n");
	} else {
		elemento = l.ant->sig->elemento;
	}
	return elemento;
}

ListaPDI LISTAPDI_avanza(ListaPDI l) {
	if (l.ant->sig == NULL) {
		printf("\nError al avanzar, el PDI está al final...\n");
	} else {
		l.ant = l.ant->sig;
	}
	return l;
}

ListaPDI LISTAPDI_vesInicio(ListaPDI l) {
	l.ant = l.pri;
	return l;
}

int LISTAPDI_final(ListaPDI l) {
	return l.ant->sig==NULL;
}

int LISTAPDI_vacia(ListaPDI l) {
	return l.pri->sig == NULL;
}

ListaPDI LISTAPDI_destruye(ListaPDI l) {
	Nodo *aux;

	while (l.pri!=NULL) {
		aux = l.pri;
		l.pri = l.pri->sig;
		free(aux);
	}

/*

	l = LISTAPDI_vesInicio(l);
	
	while (!LISTAPDI_vacia(l)) {
		l = LISTAPDI_elimina(l);
	}
	
	free(l.pri); // borramos el fantasma
	l.pri = l.ant = NULL;
*/	
	return l;
}


