#include <stdio.h>
#include "conjunto.h"

int privbuscarUno(tLista conjunto, int tam, tElemento elemento);
void privEliminarUno(tLista conjunto, int *tam, int posicion);

tConjunto iniciar(){
	tConjunto nuevo;
	
	nuevo.tam = 0;
	
	return nuevo;
}

int cardinalidad(tConjunto reg){
	
	return reg.tam;
}

void insertarUno(tConjunto *reg){
	tElemento nuevo;
	
	nuevo = cargarUno();
	if(pertenece(*reg, nuevo) == -1){
		reg->tam = reg->tam + 1;
		reg->conjunto[reg->tam] = nuevo;
	}else
		printf("\nEl elemento ya pertenece al conjunto");		
}

void eliminarUno(tConjunto *reg){
	tElemento elemento;
	int posicion;
	
	printf("\nIngrese el elemento a eliminar: ");
	elemento = cargarUno();
	posicion = privbuscarUno(reg->conjunto, reg->tam, elemento);
	if(posicion != -1){
		privEliminarUno(reg->conjunto, &reg->tam, posicion);
		printf("\nElemento eliminado");
	}else
		printf("\nElemento no encontrado");
}

int privbuscarUno(tLista conjunto, int tam, tElemento elemento){
	int i, respuesta;
	
	i = 1;
	while(i <= tam && retornarElemento(conjunto[i]) != retornarElemento(elemento))
		i++;
	if(i <= tam)
		respuesta = i;
	else
		respuesta = -1;
	
	return respuesta;
}

void privEliminarUno(tLista conjunto, int *tam, int posicion){
	int i;
	
	for(i = posicion; i <= *tam - 1; i++)
		conjunto[i] = conjunto[i + 1];
	*tam = *tam - 1;
}

int pertenece(tConjunto reg, tElemento elemento){
	int i, respuesta;
	
	i = 1;
	while(i <= reg.tam && retornarElemento(reg.conjunto[i]) != retornarElemento(elemento))
		i++;
	if(i <= reg.tam)
		respuesta = 1;
	else
		respuesta = -1;
	
	return respuesta;
}

tConjunto unionConjuntos(tConjunto reg1, tConjunto reg2){
	tConjunto nuevoConjunto;	
	int i;
	
	nuevoConjunto = reg1;
	for(i = 1; i <= reg2.tam; i++)
		if(pertenece(nuevoConjunto, reg2.conjunto[i]) == -1){
			nuevoConjunto.tam++;
			nuevoConjunto.conjunto[nuevoConjunto.tam] = reg2.conjunto[i];
		}
	
	return nuevoConjunto;
}

tConjunto interseccionConjuntos(tConjunto reg1, tConjunto reg2){
	tConjunto nuevoConjunto;
	int i;
	
	nuevoConjunto.tam = 0;
	for(i = 1; i <= reg1.tam; i++){
		if(pertenece(reg2, reg1.conjunto[i]) == 1){
			nuevoConjunto.tam++;
			nuevoConjunto.conjunto[nuevoConjunto.tam] = reg1.conjunto[i];
		}
	}
	
	return nuevoConjunto;
}

tConjunto diferenciaConjuntos(tConjunto reg1, tConjunto reg2){
	tConjunto nuevoConjunto;
	int i;
	
	nuevoConjunto.tam = 0;
	for(i = 1; i <= reg1.tam; i++){
		if(pertenece(reg2, reg1.conjunto[i]) == -1){
			nuevoConjunto.tam++;
			nuevoConjunto.conjunto[nuevoConjunto.tam] = reg1.conjunto[i];
		}
	}
	
	return nuevoConjunto;
}

void mostrarConjunto(tConjunto reg){
	int i;
	
	for(i = 1; i <= reg.tam; i++)
		mostrarUno(reg.conjunto[i]);
}
