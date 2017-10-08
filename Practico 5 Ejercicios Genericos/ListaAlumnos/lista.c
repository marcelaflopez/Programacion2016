#include "lista.h"
#include <stdio.h>

int privBuscarDNI(tVector lista, int tam, int buscado);
void privEliminar(tVector lista, int *tam, int posi);

tLista iniciar(){
	tLista nueva;
	
	nueva.tam = 0;
	
	return nueva;	
}

int listaVacia(tLista reg){
	if(reg.tam == 0){
		return 1;
	}else{
		return -1;
	}
}

int listaLlena(tLista reg){
	if(reg.tam == 50){
		return 1;
	} else {
		return -1;
	}
}


void insertarOrdenado(tLista *reg){
	int j;
	tAlumno nuevo;
	
	nuevo = cargarUno();
	j = reg->tam;
	while (j > 0 && retornarDNI(nuevo) < retornarDNI(reg->lista[j])){
		reg->lista[j + 1] = reg->lista[j];
		j--;
	}
	reg->lista[j+1] = nuevo;
	reg->tam = reg->tam + 1;
}

void modificarAlumno(tLista *reg, int buscado){
	int posi;
	
	posi = privBuscarDNI(reg->lista, reg->tam, buscado);
	if(posi != -1){
		modificarCarreraLU(&reg->lista[posi]);
		mostrarUno(reg->lista[posi]);
	}else{
		printf("\nAlumno no encontrado.");
	}
}

int privBuscarDNI(tVector lista, int tam, int buscado){
	int ini, fin, med;
	
	ini = 1;
	fin = tam;
	med = (ini + fin)/ 2;	
	while(ini <= fin && retornarDNI(lista[med]) != buscado){
		if(buscado < retornarDNI(lista[med]))
			fin = med - 1;
		else
			ini = med + 1;
	}
	if(ini <= fin){
		return med;
	} else {
		return -1;
	}	
}


void privEliminar(tVector lista, int *tam, int posi){
	int i;
	
	for(i = posi; i <= *tam - 1; i++){
		lista[i] = lista[i+1];
	}
	*tam = *tam - 1;
}

void eliminarAlumno(tLista *reg, int buscado){
	int posi;
	
	posi = privBuscarDNI(reg->lista, reg->tam, buscado);
	if(posi != -1){
		privEliminar(reg->lista, &reg->tam, posi);
		printf("\nAlumno elminado.");
	}else{
		printf("\nAlumno no encontrado.");
	}
}

void mostrarLista(tLista reg){
	int i;
	
	printf("\n Mostrando la lista:");
	for(i = 1; i<= reg.tam ; i++){
		printf("\n---------------");
		mostrarUno(reg.lista[i]);
		printf("\n---------------");
	}
}



