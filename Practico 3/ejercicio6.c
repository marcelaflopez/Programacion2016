#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[110];

int sumaDivisores(int numero);
int esAmigo(int numero1, int numero2);
int tipoNumero(int numero);
void ingresarAB(int *A, int *B);
void generarLista(listaInt lista, int *tam, int A, int B);
void poseeNumeroAmigo(listaInt lista, int tam, int A, int B);
	
int main(int argc, char *argv[]) {
	listaInt lista;
	int A, B, tam;
	
	srand(time(NULL));
	
	ingresarAB(&A, &B);
	generarLista(lista, &tam, A, B);
	poseeNumeroAmigo(lista, tam, A, B);	
	
	return 0;
}

/*
	Retorna la suma de los divisores de un numero, sin tener en cuenta si mismo.
	Ejemplos:
		sumaDivisores(18) -> 19
		sumaDivisores(20) -> 22
*/
int sumaDivisores(int numero){
	int acumulador, i;
	
	acumulador = 0;
	for(i = 1; i <= numero / 2; i++){
		if(numero % i == 0){
			acumulador = acumulador + i;
		}
	}
	
	return acumulador;
}

/*
	Retorna 1 si los numeros son amigos, -1 sino.
	Ejemplos:
		esAmigo(284, 220) -> 1
		esAmigo(285, 220) -> -1
*/
int esAmigo(int numero1, int numero2){
	if(numero1 == sumaDivisores(numero2) && numero2 == sumaDivisores(numero1)){
		return 1;
	}else{
		return -1;
	}
}

/*
	Retorna si un numero es deficiente(0), abundante(2) o perfecto(1).
*/
int tipoNumero(int numero){
	int sumaDiv;
	
	sumaDiv = sumaDivisores(numero);
	if(numero > sumaDiv){
		return 0;
	}else if(numero == sumaDiv){
		return 1;
	}else{
		return 2;
	}
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
	Muestra los numeros que tiene amigos en el rango [A, B] y no son deficientes.
*/
void poseeNumeroAmigo(listaInt lista, int tam, int A, int B){
	int i, j, bandera;
	
	bandera = 0;
	for(i = 1; i <= tam; i++){
		for(j = A; j <= B; j++){
			if(esAmigo(lista[i], j) == 1 && tipoNumero(lista[i]) != 0){
				printf("El numero %d tiene amigos en el rango [%d, %d] y no es deficiente.\n", lista[i], A, B);
				bandera = 1;
			}
		}
	}
	
	if(bandera == 0){
		printf("No hay numeros que posean amigos y no sean deficientes en el rango [%d, %d]\n", A, B);
	}
}

