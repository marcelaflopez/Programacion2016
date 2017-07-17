#include <stdio.h>
#include <math.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

int cantidadDivisores(int numero);
int toBase(int numero, int base);
int esPrimo(int numero);
	
int main(int argc, char *argv[]) {
	int numero;
	
	printf("Ingrese numero:\n");
	scanf("%d", &numero);	
	if(esPrimo(cantidadDivisores(numero)) == 1){
		printf("Equivalente en base 2:%d\n", toBase(numero, 2));
	}else{
		printf("Equivalente en base 9:%d\n", toBase(numero, 9));
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
		toBase(7,2) -> 111
		toBase(16, 8) -> 20
*/
int toBase(int numero, int base){
	int aux, digito, exponente;
	
	aux = 0;
	exponente = 0;
	while(numero > 0){
		digito = numero % base;
		aux = aux + digito * pow(10, exponente);
		exponente++;
		numero = numero / base;
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
