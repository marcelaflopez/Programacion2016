#include <stdio.h>
#include <math.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[110];

int factorial(int numero);
float sucesion(int x, int i);
int sucesionError(float error);

int main(int argc, char *argv[]) {
	int i, x;
	float error;	
	
	printf("Ingrese el valor para i:\n");
	scanf("%d", &i);
	printf("Ingrese el valor para x:\n");
	scanf("%d", &x);
	printf("El valor de la sucesion para x e i es:%f\n", sucesion(x, i));
	printf("Ingrese el error:\n");
	scanf("%f", &error);
	printf("El valor para i es:%d\n", sucesionError(error));
	
	return 0;
}

/*
	Devuelve el factorial de un numero.
	Ejemplos:
		factorial(3) -> 6
		factorial(6) -> 720
*/
int factorial(int numero){
	int acumulador, i;
	
	acumulador = 1;
	for(i = 1; i <= numero; i++){
		acumulador = acumulador * i;
	}
	
	return acumulador;
}

/*
	Calcula la sucesion Si = 1 + X + X2/2! + X3/3! +...+ Xi/i!
*/
float sucesion(int x, int i){
	int j;
	float acumulador;
	
	acumulador = 0;
	for(j = 0; j <= i; j++){
		acumulador = acumulador + (pow(x, j)/factorial(j));
	}
	
	return acumulador;
}

/*
	Devuelve el primero valor de i, para el cual se cumple
	una aproximacion de e^x, dentro del error dado.
*/
int sucesionError(float error){
	int i;
	float acumulador;
	
	i = 0;
	acumulador = 0;
	while(fabs(2.7182 - acumulador) > error){
		acumulador = acumulador + (1 / factorial(i));
		i++;	
	}
	
	return i;
}



