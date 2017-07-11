#include <stdio.h>
#include <ctype.h>
/*
Autor: Fernando Orquera
Año: 2017 
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int cantidadSubListas(listaInt lista, int tam);

int main() {
	int tam;
	listaInt lista;	
	
	cargarLista(lista, &tam);
	printf("Cantidad de sublistas:%d\n", cantidadSubListas(lista, tam));
	
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
	Devuelve la cantidad de sublistas ascendentes que no se solapan
	y tienen mas de un elemento.
	Ejemplos:
		cantidadSubListas([7, 5, 6, 7, 4, 5, 6, 7], 8) -> 2	
*/
int cantidadSubListas(listaInt lista, int tam){
	int cantidad, contador, i;
	
	cantidad = 0;
	contador = 1;
	for(i = 1; i <= tam - 1; i++){
		if(lista[i + 1] <= lista[i] && contador > 1){
			cantidad++;
			contador = 1;
		}else{
			contador++;
		}
	}
	
	if(contador > 1){ /*Verifico si hay una sublista al final de la lista*/
		cantidad++;
	}
	
	return cantidad;
}



