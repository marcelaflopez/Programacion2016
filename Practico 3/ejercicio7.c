#include <stdio.h>
#include <math.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[110];

int factorial(int numero);
float sucesion(int n);
int sucesionError(float error);

int main(int argc, char *argv[]) {
	int n;
	float error;	
	
	printf("Ingrese el valor para N:\n");
	scanf("%d", &n);
	printf("El valor de la sucesion para x e i es:%f\n", sucesion(n));
	printf("Ingrese el error:\n");
	scanf("%f", &error);
	printf("El valor para i es:%d\n", sucesionError(error));
	
	return 0;
}



/*
	Calcula la sucesion Sn = S(i=0 .. n) (-1)^i / 2i + 1 
*/
float sucesion(int n){
	int i;
	float acumulador;
	
	acumulador = 0;
	for(i = 0; i <= n; i++){
		acumulador = acumulador + pow(-1, i)/ (2*i + 1);
	}
	
	return acumulador;
}

/*
	Devuelve el primero valor de i, para el cual se cumple
	una aproximacion de pi/4, dentro del error dado.
*/
int sucesionError(float error){
	int i;
	float acumulador;
	
	i = 0;
	acumulador = 0;
	while(fabs(0.7853 - acumulador) > error){
		acumulador = acumulador + pow(-1, i)/ (2*i + 1);;
		i++;	
	}
	
	return i;
}



