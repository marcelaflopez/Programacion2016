#include <stdio.h>
#include <math.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

int cantidadDivisores(int numero);
int toBase10(int numero, int base);
int esPrimo(int numero);
	
int main(int argc, char *argv[]) {
	int numero, base;
	
	printf("Ingrese numero:\n");
	scanf("%d", &numero);
	printf("Ingrese base:\n");
	scanf("%d", &base);
	numero = toBase10(numero, base);
	if(esPrimo(numero) == 1){
		printf("El numero en base 10 -> %d es primo.\n", numero);
	}else{
		printf("La cantidad de divisores del numero en base 10 -> %d es: %d\n", numero, cantidadDivisores(numero) + 2);
	}
	
	return 0;
}

/*
	Retorna la cantidad de divisores de un numero.
	Ejemplos:
		cantidadDivisores(9) -> 1
		cantidadDivisores(8) -> 2
		cantidadDivisores(7) -> 0
*/
int cantidadDivisores(int numero){
	int cantidad,i;
	
	cantidad = 0;
	for(i = 2; i <= numero / 2; i++){
		if(numero % i == 0){
			cantidad = cantidad + 1;
		}
	}
	
	return cantidad;	
}

/*
	Retorna el numero convertido en la base dada
	Ejemplos:
		toBase(111,2) -> 7
		toBase(20, 8) -> 16
*/
int toBase10(int numero, int base){
	int aux, digito, exponente;
	
	aux = 0;
	exponente = 0;
	while(numero > 0){
		digito = numero % 10;
		aux = aux + digito * pow(base, exponente);
		exponente++;
		numero = numero / 10;
	}
	
	return aux;
}

/*
	Retorna 1 si el numero es primo. -1 si no.
	Ejemplos:
		esPrimo(7) -> 1
		esPrimo(8) -> -1
		esPrimo(1) -> -1
*/
int esPrimo(int numero){
	if(cantidadDivisores(numero) == 0 && numero != 1){
		return 1;
	}else{
		return -1;
	}
}
