#include <stdio.h>
#include <ctype.h>
/*
Autor: Fernando Orquera
Año: 2017 
*/

typedef char listaChar[50];

void cargarTexto(listaChar lista, int *tam);
void enMinusculas(listaChar lista, int tam);
int esIsograma(listaChar lista, int tam);


int main() {
	int tam, rpta;
	listaChar lista;	
	
	cargarTexto(lista, &tam);	
	enMinusculas(lista, tam);
	rpta = esIsograma(lista, tam);
	if(rpta == 1){
		printf("El texto es un isograma.\n");
	}else{
		printf("El texto no es un isograma.\n");
	}
	
	return 0;
}


void cargarTexto(listaChar lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c caracter:", i, 167); /*Estoy agregando el caracter º*/
		fflush(stdin);
		scanf("%c", &lista[i]);
	}
}

/*
	Convierte la lista en minusculas.
	Ejemplo:
		enMinusculas(["A", "B", "c"], 3) -> (["a", "b", "c"])
		enMinusculas(["a", "b", "c"], 3) -> (["a", "b", "c"])
*/
void enMinusculas(listaChar lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		lista[i] = tolower(lista[i]);
	}
}

/*
	Devuelve 1 si el texto  es un isograma, -1 en caso contrario.
	No controla si solo se ingresaron espacios.
	Ejemplos:
		cantidadPalabras(["b", "a", " ","c", "k", "g", "r","o", "u", "n", "d"], 11) -> 1
	    cantidadPalabras(["i", "s", "o", " ","g", "r", "a", "m", "a"], 9) -> -1
		cantidadPalabras([" ", " ", " "], 3) -> 1
*/
int esIsograma(listaChar lista, int tam){
	int i, j, respuesta;
	
	respuesta = 1;
	i = 1;
	while(i < tam && respuesta == 1){
		j = i + 1;
		while(j <= tam && respuesta == 1){
			if(lista[i] == lista[j] && lista[i] != ' '){
				respuesta = -1;
			}
			j++;
		}
		i++;
	}	
	
	return respuesta;
}


