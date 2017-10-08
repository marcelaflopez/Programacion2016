#include <stdio.h>
#include "elemento.h"

tElemento cargarUno(){
	tElemento nuevo;
	
	printf("\nIngrese elemento: ");
	scanf("%d", &nuevo.elemento);
	
	return nuevo;
}

void mostrarUno(tElemento reg){
	
	printf("\n Elemento: %d", reg.elemento);
}

int retornarElemento(tElemento reg){
	
	return reg.elemento;
} 

