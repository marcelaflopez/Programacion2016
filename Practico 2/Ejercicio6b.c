#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017 
*/

typedef float listaInt[50];

void cargarLista(listaInt lista, int *tam);
int contarDigitos(int numero);
float promedioLista(listaInt lista, int tam);
int convertirEnEntero(float numero);

int main() {
	int tam;
	listaInt lista;
	float promedio;
	
	cargarLista(lista, &tam);
	promedio = promedioLista(lista, tam);
	if(promedio > 0){
		printf("El promedio es:%.2f", promedio);
	}else{
		printf("La lista no tenia numeros formados 5 digitos");
	}		
	
	return 0;
}


void cargarLista(listaInt lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c numero:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%f", &lista[i]);
	}
}

/*
	Devuele el promedio de los numeros compuestos de 5 digitos.
	Devuelve -1, si no se encuentran numeros compuestos de 5 digitos.
	Ejemplos:
		promedioLista([243.25, 37, 222.22]) -> 232,735
		promedioLista([12.1, 3.8, 11.22]) -> -1
*/
float promedioLista(listaInt lista, int tam){
	float sum;	
	int i, cont, aux;
	
	sum = 0;
	cont = 0;
	for(i = 1; i <= tam; i++){
		aux = convertirEnEntero(lista[i]);
		if(contarDigitos(aux) == 5){
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
/*
Devuelve la cantidad de digitos de un numero.
Ejemplo;
todoPar(2846) -> 4;
todopar(27864) -> 5;
todopar(0) -> 0;
*/
int contarDigitos(int numero){
	int cont;
	
	cont = 0;
	while(numero > 0){
		cont++;
		numero = numero / 10;
	}
	
	return cont;
}

int convertirEnEntero(float numero){
	int parteEntera;
	
	parteEntera = numero;
	while(numero - parteEntera != 0){
		numero = numero * 10;
		parteEntera = numero;
	}
	
	return numero;
}
