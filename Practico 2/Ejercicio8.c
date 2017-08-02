#include <stdio.h>
#include <ctype.h>
/*
Autor: Fernando Orquera
Año: 2017 
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int verificar(listaInt lista, int tam);

int main() {
	int tam;
	listaInt lista;		
	
	cargarLista(lista, &tam);
	if(verificar(lista, tam) == 1){
		printf("\nNo tiene sublistas ascendentes o descendentes");
	}else{
		printf("\nTiene sublistas ascendentes o descendentes");
	}
	
	return 0;
}


void cargarLista(listaInt lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c entero:", i, 167); /*Estoy agregando el caracter º*/		
		scanf("%d", &lista[i]);
	}
}

/*
	Devuelve 1 si no tiene sublistas ascendentes o descentes,
	-1 en caso contrario. Funciona para listas de al menos 
	tamaño 2.
	Ejemplos:
		cantidadSubListas([7, 5, 6, 1, 4, 3, 6, 2], 8) -> 1	
		cantidadSubListas([7, 8, 6, 1, 4, 3, 6, 2], 8) -> -1
*/
int verificar(listaInt lista, int tam){
	int i, band, valor;
	
	
	band = 1;
	if(lista[2] <= lista[1]){
		valor = 0;
	}else{
		valor = 1;
	}
	i = 2;
	while(i < tam && band == 1){
		if(valor == 0){
			if(lista[i + 1] >= lista[i]){
				valor = 1;
			}else{
				band = -1;
			}
		}else{
			if(lista[i + 1] <= lista[i]){
				valor = 0;
			}else{
				band = -1;
			}
		}		
		i++;
	}
	
	return band;
}



