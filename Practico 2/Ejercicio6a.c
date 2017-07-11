#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017 
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int todoPar(int numero);
float promedioLista(listaInt lista, int tam);

int main() {
	int tam;
	listaInt lista;
	float promedio;
	
	cargarLista(lista, &tam);
	promedio = promedioLista(lista, tam);
	if(promedio > 0){
		printf("El promedio es:%.2f", promedio);
	}else{
		printf("La lista no tenia numeros formados solo por pares");
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

/*
	Devuele el promedio de los numeros compuestos de pares.
	Devuelve -1, si no se encuentran numeros compuestos de pares.
	Ejemplos:
		promedioLista([24, 37, 22]) -> 23
		promedioLista([12, 38, 11]) -> -1
*/
float promedioLista(listaInt lista, int tam){
	float sum;
	int i,cont;
	
	sum = 0;
	cont = 0;
	for(i = 1; i <= tam; i++){
		if(todoPar(lista[i]) == 1){
			sum = sum + lista[i];
			cont++;
		}
	}
	
	if(cont > 0){
		return sum / cont;
	}else{
		return -1;
	}
}
/*
	Devuelve 1 si todos los digitos son pares.
	Ejemplo;
		todoPar(2846) -> 1;
		todopar(2786) -> 0;
*/
int todoPar(int numero){
	int respuesta,digito;
	
	respuesta = 1;
	while(numero > 0 && respuesta == 1){
		digito = numero % 10;
		if(digito % 2 != 0){
			respuesta = 0;			
		}
		numero = numero / 10;
	}
	
	return respuesta;
}
