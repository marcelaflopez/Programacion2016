#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
float promedioPares(listaInt lista, int tam);
float promedioImpares(listaInt lista, int tam);

int main() {
	listaInt lista;
	int tam; 
	float promPares, promImpares;
	
	cargarLista(lista, &tam);	
	promPares = promedioPares(lista, tam);
	promImpares = promedioImpares(lista, tam);	
	if(promPares != -1){
		printf("El promedio de los numeros pares es:%.2f\n", promPares);
	} else {
		printf("No hay numeros pares.\n");
	}
	if(promImpares != -1){
		printf("El promedio de los numeros impares es:%.2f\n", promImpares);
	} else {
		printf("No hay numeros pares.\n");
	}
		
	return 0;
}

void cargarLista(listaInt lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c numero:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%d", &lista[i]);
	}
}

float promedioPares(listaInt lista, int tam){
	int cont, i;
	float suma;
	
	cont = 0;
	suma = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] % 2 == 0){
			cont++;
			suma = suma + lista[i];
		}
	}
	if(cont > 0){
		return suma / cont;
	}else{
		return -1;
	}
}

float promedioImpares(listaInt lista, int tam){
	int cont, i;
	float suma;
	
	cont = 0;
	suma = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] % 2 != 0){
			cont++;
			suma = suma + lista[i];
		}
	}
	if(cont > 0){
		return suma / cont;
	}else{
		return -1;
	}
}

