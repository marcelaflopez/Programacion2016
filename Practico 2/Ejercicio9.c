#include <stdio.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int contarLista(listaInt lista, int tam);
int mismoDigito(int numero);


int main(int argc, char *argv[]) {
	listaInt lista;
	int tam;
	
	cargarLista(lista, &tam);
	printf("La cantidad de numeros compuestos por el mismo digito es: %d", contarLista(lista, tam));
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
	Devuelve la cantidad de numeros que estan formados por el mismo digito.
*/
int contarLista(listaInt lista, int tam){
	int cantidad, i;
	
	cantidad = 0;
	for(i = 1; i <= tam; i++){
		if(mismoDigito(lista[i]) == 1){
			cantidad++;			
		}
	}
	
	return cantidad;
}

/*
	Devuelve 1 si el numero esta compuesto por el mismo digito,
	- 1 en caso contrario.
	Ejemplos:
		mismoDigito(777) -> 1
		mismoDigito(745) -> -1
		mismoDigito(5) -> 1
*/
int mismoDigito(int numero){
	int primerDigito, resultado, digito;	
	
	primerDigito = numero % 10;
	numero = numero / 10;
	resultado = 1;
	while(numero > 0){
		digito = numero % 10;
		if(digito != primerDigito){
			numero = 0;
			resultado = -1;
		}else{
			numero = numero / 10;
		}
	}
	
	return resultado;
}



