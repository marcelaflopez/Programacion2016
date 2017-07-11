#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int cantMultiplos(listaInt lista, int tam, int A, int B);

int main() {
	listaInt lista;
	int tam, A, B;
	
	cargarLista(lista, &tam);
	printf("Ingrese el valor para A:\n");
	scanf("%d", &A);
	printf("Ingrese el valor para B:\n");
	scanf("%d", &B);	
	printf("La cantidad de elementos que son solo multpilos de A: %d\n", cantMultiplos(lista, tam, A, B));
	printf("La cantidad de elementos que son solo multpilos de B: %d\n", cantMultiplos(lista, tam, B, A));
	return 0;
}

void cargarLista(listaInt lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c edad:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%d", &lista[i]);
	}
}

/*
Retorna la cantidad elementos de la lista que son multiplos de A
pero no de B.
Ejemplo:
 cantMultiplos([1,10,15,12,6,9,20], 5, 3) -> 2
 cantMultiplos([1,10,15,12,6,9,20], 3, 5) -> 3
 cantMultiplos([1,10,15,12,6,9,20], 7, 5) -> 0
*/
int cantMultiplos(listaInt lista, int tam, int A, int B){
	int cantidad;
	int i;
	
	cantidad = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] % A == 0 && lista[i] % B != 0){
			cantidad = cantidad + 1;
		}
	}
	
	return cantidad;
}

