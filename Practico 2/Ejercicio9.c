#include <stdio.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int numeroInvertido(int numero);
int esCapicua(int numero);
int soloImpares(int numero);


int main(int argc, char *argv[]) {
	listaInt lista;
	int tam,i,cantidad,bandera;
	
	bandera = 0;
	cantidad = 0;
	cargarLista(lista, &tam);
	for(i = 1; i <= tam; i++){
		if(esCapicua(lista[i]) == 1){
			cantidad++;
			if(soloImpares(lista[i]) == 1){
				bandera = 1;
				printf("Numero formado solo con digitos impares:%d\n", lista[i]);
			}
		}
	}
	printf("Cantidad de capicuas:%d\n", cantidad);
	if(bandera == 0){
		printf("La lista no contiene capicuas formados solo por digitos impares\n");
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
	Devuelve el numero invertido.
	Ejemplos;
		numeroInvertido(14789) -> 98741
		numeroInvertido(426) -> 624
*/
int numeroInvertido(int numero){
	int aux,numeroInv;
	
	aux = numero;
	numeroInv = 0;
	while(aux > 0){
		numeroInv = numeroInv * 10 + (aux % 10);
		aux = aux / 10;
	}
	
	return numeroInv;
}

/*
	Devuelve 1 si el numero es capicua, -1 en caso contrario.
	Ejemplos:
		esCapicua(757) -> 1
		esCapicua(745) -> -1
		esCapicua(5) -> 1
*/
int esCapicua(int numero){
	if(numeroInvertido(numero) == numero){
		return 1;
	}else{
		return -1;
	}
}

/*
	Devuelve 1 si un numero esta compuesto solo de impares, 0 lo contrario
	Ejemplos:
		soloImpares(759) -> 1
		soloImpares(781) -> 0
*/
int soloImpares(int numero){
	int resultado,digito;
	
	resultado = 1;
	while(numero > 0 && resultado == 1){
		digito = numero % 10;
		if(digito % 2 != 1){
			resultado = 0;
		}
		numero = numero / 10;
	}
	
	return resultado;
}

