#ifndef ELEMENTO_H
#define ELEMENTO_H

typedef struct{
	int elemento;
}tElemento;

tElemento cargarUno();
void mostrarUno(tElemento reg);
int retornarElemento(tElemento reg);

#endif
