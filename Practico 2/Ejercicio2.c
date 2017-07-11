#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
float promedioLista(listaInt lista, int tam);
int menorLista(listaInt lista, int tam);
int mayorLista(listaInt lista, int tam);

int main() {
	listaInt lista;
	int tam;
	
	cargarLista(lista, &tam);
	printf("El promedio de la lista: %.2f\n", promedioLista(lista, tam));
	printf("La mayor edad es: %d\n", mayorLista(lista, tam));
	printf("La menor edad es: %d\n", menorLista(lista, tam));
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

float promedioLista(listaInt lista, int tam){
	float sum;
	int i;
	
	for(i = 1; i <= tam; i++){
		sum = sum + lista[i];
	}
	
	return sum / tam;
}

int menorLista(listaInt lista, int tam){
	int menor;
	int i;
	
	menor = lista[1];
	for(i = 2; i <= tam; i++){
		if(lista[i] < menor){
			menor = lista[i];
		} 
	}
	
	return menor;
}

int mayorLista(listaInt lista, int tam){
	int mayor;
	int i;
	
	mayor = lista[1];
	for(i = 2; i <= tam; i++){
		if(lista[i] > mayor){
			mayor = lista[i];
		} 
	}
	
	return mayor;
}


