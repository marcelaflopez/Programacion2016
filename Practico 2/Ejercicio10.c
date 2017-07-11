#include <stdio.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
void cargarAB(int *A, int *B);
int esPrimo(int numero);
int menorPrimo(listaInt lista, int tam, int A, int B);
int mayorPrimo(listaInt lista, int tam, int A, int B);
int todoPrimo(int numero);
float porcentajeSoloPrimos(listaInt lista, int tam);


int main(int argc, char *argv[]) {
	listaInt lista;
	int tam, A, B, menor, mayor;	
	
	cargarLista(lista, &tam);
	cargarAB(&A, &B);
	
	menor = menorPrimo(lista, tam, A, B); 
	mayor = mayorPrimo(lista, tam, A, B);
	if(menor != -1 && mayor != -1){
		printf("El menor primo es:%d\n", menor);
		printf("El mayor primo es:%d\n", mayor);
	}else{
		printf("No hay numeros primos en el rango [%d, %d]\n", A, B);
	}
	
	printf("El porcentaje de numeros compuestos de digitos primos es: %.2f%%\n", porcentajeSoloPrimos(lista, tam));
	
	
	return 0;
}

void cargarLista(listaInt lista, int *tam){
	int i;
	float aux;
	
	i = 1;
	printf("Ingrese %d %c numero:", i, 167); /*Estoy agregando el caracter º*/
	scanf("%f", &aux);	
	while(aux > 0 && aux == (int)aux){
		lista[i] = aux;
		i++;
		printf("Ingrese %d %c numero:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%f", &aux);
	}
	*tam = i - 1;
}

void cargarAB(int *A, int *B){
	do{
		printf("Ingrese valor para A:\n");
		scanf("%d", A);
		printf("Ingrese valor para B:\n");
		scanf("%d", B);
	}while(*A < 0 && *B < 0 && *A >= *B);
}

/*
	Devuelve 1 si el numero es primo, -1 si no es primo.
	Ejemplos:
		esPrimo(7) -> 1
		esPrimo(6) -> -1
		esPrimo(1) -> -1
*/
int esPrimo(int numero){
	int pd;
	
	pd = 2;
	while(pd <= numero / 2 && numero % pd != 0){
		pd++;
	}
	if(pd > numero / 2 && numero != 1){
		return 1;
	}else{
		return -1;
	}
}

/*
	Devuelve el menor primo que se encuentre en el rango [A,B].
	En caso de que la lista no contenga primos, o primos dentro del rango
	devuelve -1.
	Ejemplos:
		menorPrimo([7,10,11,12], 4, 6, 13) -> 7
		menorPrimo([7,10,11,12], 4, 3, 6) -> -1
*/
int menorPrimo(listaInt lista, int tam, int A, int B){
	int i, menor, bandera;
	
	bandera = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] >= A && lista[i] <= B){
			if(esPrimo(lista[i]) == 1){
				if(bandera != 0){
					if(lista[i] < menor){
						menor = lista[i];						
					}
				}else{
					menor = lista[i];
					bandera = 1;
				}
			}
		}		
	}
	
	if(bandera != 0){
		return menor;
	}else{
		return -1;
	}
}


/*
	Devuelve el mayor primo que se encuentre en el rango [A,B].
	En caso de que la lista no contenga primos, o primos dentro del rango
	devuelve -1.
	Ejemplos:
		mayorPrimo([7,10,11,12], 4, 6, 13) -> 11
		mayorPrimo([7,10,11,12], 4, 3, 6) -> -1
*/
int mayorPrimo(listaInt lista, int tam, int A, int B){
	int i, mayor, bandera;
	
	bandera = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] >= A && lista[i] <= B){
			if(esPrimo(lista[i]) == 1){
				if(bandera != 0){
					if(lista[i] > mayor){
						mayor = lista[i];						
					}
				}else{
					mayor = lista[i];
					bandera = 1;
				}
			}
		}		
	}
	
	if(bandera != 0){
		return mayor;
	}else{
		return -1;
	}
}

/*
	Devuelve 1 si el numero esta compuesto de digitos primos,
	-1 de lo contrario.
	Ejemplos:
		todoPrimo(357) -> 1
		todoPrimo(3215) -> -1
*/
int todoPrimo(int numero){
	int resultado, digito;
	
	resultado = 1;
	while(numero > 0 && resultado == 1){
		digito = numero % 10;
		if(digito != 2 && digito != 3 && digito != 5 && digito != 7){
			resultado = 0;
		}
		numero = numero / 10;
	}
	
	return resultado;
}

/*
	Devuelve el porcentaje de los numeros que estan compuestos de
	solo numeros primos.
	Ejemplos:
		porcentajeSoloPrimos([7, 10, 11, 12], 4) -> 25.00
		porcentajeSoloPrimos([5, 7, 11, 12], 4) -> 50.00
*/
float porcentajeSoloPrimos(listaInt lista, int tam){
	float contador;
	int i;
	
	contador = 0;
	for(i = 1; i <= tam; i++){
		if(todoPrimo(lista[i]) == 1){
			contador++;
		}
	}
	
	return (contador / tam) * 100;
}
