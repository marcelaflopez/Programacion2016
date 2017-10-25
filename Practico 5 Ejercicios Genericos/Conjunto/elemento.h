#ifndef ELEMENTO_H
#define ELEMENTO_H

typedef struct{
	int elemento;
}tElemento;

tElemento cargarUno();
void mostrarUno(tElemento reg);
int retornarElemento(tElemento reg);
/*FALTA UNA OPERACIÓN QUE PERMITA LA COMPARACIÓN ENTRE DOS ELEMENTOS*/

#endif
