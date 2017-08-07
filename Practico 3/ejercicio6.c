#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[110];

long cuadradoSuma(int n);
long sumaCuadrados(int n);
void ingresarAB(int *A, int *B);
void generarLista(listaInt lista, int *tam, int A, int B);
void mostrarDiferencias(listaInt lista, int tam);
	
int main(int argc, char *argv[]) {
	listaInt lista;
	int A, B, tam;
	
	srand(time(NULL));
	
	ingresarAB(&A, &B);
	generarLista(lista, &tam, A, B);
	mostrarDiferencias(lista, tam);	
	
	return 0;
}

/*
	Calcula el cuadrado de la suma de los primeros n naturales.
	Ejemplo:
		cuadradoSuma(10) ->  (1 + 2 + ... + 10)² = 55² = 3025
*/
long cuadradoSuma(int n){
	int i;
	long sum;
	
	sum = 0;
	for (i = 1; i <= n; i++){
		sum += i;
	}
	
	return sum * sum;
}

/*
	Calcula la suma de los cuadrados de los primeros n naturales.
	Ejemplo:
		sumaCuadrados(10) -> 1² + 2² + ... + 10² = 385
*/
long sumaCuadrados(int n){
	int i;
	long sum;
	
	sum = 0;
	for (i = 1; i <= n; i++){
		sum = sum  + (i * i);
	}
	
	return sum;
}

void ingresarAB(int *A, int *B){
	do{
		printf("Ingrese valor para A:\n");
		scanf("%d", A);
		printf("Ingrese valor para B:\n");
		scanf("%d", B);
		if(*A <= 0 && *B <= 0 && *A > *B){
			printf("A y B tienen ser naturales con A < B. Revise por favor.\n");
		}
	}while(*A <= 0 && *B <= 0 && *A > *B);
}

/*
	Genera una lista de tamaño n, con numeros aleatorios entre el rango [A, B]
*/
void generarLista(listaInt lista, int *tam, int A, int B){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Generando %d %c numero:", i, 167); /*Estoy agregando el caracter º*/
		lista[i] = (rand() * (B - A) / RAND_MAX) + A;
		printf("%d\n", lista[i]);
	}
}

/*
	Muestra las diferencia del cuadrado de la suma y la suma de los cuadradoSuma
	para cada numero en la lista.
*/
void mostrarDiferencias(listaInt lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		printf("La diferencia es : %ld\n", cuadradoSuma(lista[i]) - sumaCuadrados(lista[i]));
	}
}

