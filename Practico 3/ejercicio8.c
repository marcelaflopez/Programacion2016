#include <stdio.h>
#include <math.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

void cambiarDigito(int *num1, int *num2);
int invertirNumero(int numero);

int main(int argc, char *argv[]) {
	int  numero;		
	
	printf("Ingrese el primer numero:\n");
	scanf("%d", &numero);	
	printf("Numero invertido:%d\n", invertirNumero(numero));
	
	return 0;
}

/*
	Suprime la última cifra del primer numero y
	la añade al final del segundo numero
	Ejemplos:
		cambiarDigito(789, 14) -> (78, 149)
		cambiarDigito(6, 541) -> (0, 541)
*/
void cambiarDigito(int *num1, int *num2){
	int digito;
	
	digito = *num1 % 10;
	*num1 = *num1 / 10;
	*num2 = *num2 * 10 + digito;
}

/*
	Retorna el numero invertido.
	Ejemplos:
		invertirNumero(123456) -> 654321
		invertirNumero(14785) -> 58741
*/
int invertirNumero(int numero){
	int resultado;
	
	resultado = 0;
	while(numero > 0){
		cambiarDigito(&numero, &resultado);
	}
	
	return resultado;
}
