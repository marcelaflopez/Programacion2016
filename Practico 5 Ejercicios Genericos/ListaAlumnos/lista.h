#ifndef LISTA_H
#define LISTA_H
#include "alumno.h"

typedef tAlumno tVector[50];

typedef struct{
	tVector lista;
	int tam;
}tLista;

tLista iniciar();
int listaVacia(tLista reg);
int listaLlena(tLista reg);
void insertarOrdenado(tLista *reg);
void modificarAlumno(tLista *reg, int buscado);
void eliminarAlumno(tLista *reg, int buscado);
void mostrarLista(tLista reg);

#endif
