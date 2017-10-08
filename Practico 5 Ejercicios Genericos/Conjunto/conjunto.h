#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "elemento.h"

typedef tElemento tLista[100];

typedef struct{	
	tLista conjunto;
	int tam;
}tConjunto;

tConjunto iniciar();
int cardinalidad(tConjunto reg);
void insertarUno(tConjunto *reg);
void eliminarUno(tConjunto *reg);
int pertenece(tConjunto, tElemento);
tConjunto unionConjuntos(tConjunto reg1, tConjunto reg2);
tConjunto interseccionConjuntos(tConjunto reg1, tConjunto reg2);
tConjunto diferenciaConjuntos(tConjunto reg1, tConjunto reg2);
void mostrarConjunto(tConjunto reg);

#endif
