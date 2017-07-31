#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int cantDivisores(listaInt lista, int tam, int A, int B);

int main() {
	listaInt lista;
	int tam, A, B;
	
	cargarLista(lista, &tam);
	printf("Ingrese el valor para A:\n");
	scanf("%d", &A);
	printf("Ingrese el valor para B:\n");
	scanf("%d", &B);	
	printf("La cantidad de elementos que son solo divisores de A: %d\n", cantDivisores(lista, tam, A, B));
	printf("La cantidad de elementos que son solo divisores de B: %d\n", cantDivisores(lista, tam, B, A));
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
Retorna la cantidad elementos de la lista que son divisores de A
pero no de B.
Ejemplo:
 cantDivisores([1,10,15,12,6,9,3], 7, 15, 10) -> 2
 cantDivisores([1,10,15,12,6,9,3], 7, 10, 15) -> 1
*/
int cantDivisores(listaInt lista, int tam, int A, int B){
	int cantidad;
	int i;
	
	cantidad = 0;
	for(i = 1; i <= tam; i++){
		if(A % lista[i] == 0 && B % lista[i] != 0){
			cantidad = cantidad + 1;
		}
	}
	
	return cantidad;
}

