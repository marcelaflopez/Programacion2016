#include <stdio.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
void cargarAB(int *A, int *B);
int mayorMultiplo(listaInt lista, int tam, int A, int B);
int menorDivisor(listaInt lista, int tam, int A, int B);



int main(int argc, char *argv[]) {
	listaInt lista;
	int tam, A, B, menor, mayor;	
	
	cargarLista(lista, &tam);
	cargarAB(&A, &B);	
	menor = menorDivisor(lista, tam, A, B); 
	mayor = mayorMultiplo(lista, tam, A, B);
	if(menor != -1){
		printf("El menor divisor de B en el rango [%d, %d] es: %d\n", A, B, menor);		
	}else{
		printf("No hay divisor de B en el rango [%d, %d].\n", A, B);
	}
	if(mayor != -1){
		printf("El mayor multiplo de A en el rango [%d, %d] es: %d\n", A, B, mayor);
	}else{
		printf("No hay multipo de A en el rango [%d, %d].\n", A, B);
	}
	
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
	Devuelve el mayor multiplo de A que se encuentre en el rango [A,B].
	En caso de que la lista no contenga multiplos, o multiplos dentro del rango
	devuelve -1.
	Ejemplos:
		mayorMultiplo([7,10,11,12], 4, 6, 13) -> 12
		mayorMultiplo([7,10,11,15], 4, 6, 13) -> -1
*/
int mayorMultiplo(listaInt lista, int tam, int A, int B){
	int i, mayor, bandera;
	
	bandera = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] >= A && lista[i] <= B){
			if(lista[i] % A == 0){
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
	Devuelve el menor divisor de B que se encuentre en el rango [A,B].
	En caso de que la lista no contenga divisoress, o divisores dentro del rango
	devuelve -1.
	Ejemplos:
			menorDivisor([7,10,2,12], 4, 6, 14) -> 2
			menorDivisor([5,10,11,15], 4, 6, 14) -> -1
*/
int menorDivisor(listaInt lista, int tam, int A, int B){
	int i, menor, bandera;
	
	bandera = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] >= A && lista[i] <= B){
			if(B % lista[i] == 0){
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
