#include <stdio.h>
#include <ctype.h>
/*
Autor: Fernando Orquera
Año: 2017 
*/

typedef char listaChar[50];

void cargarLista(listaChar lista, int *tam);
void trimLista(listaChar lista, int *tam);
void eliminarCaracter(listaChar lista, int tam, int posi);
void enMinusculas(listaChar lista, int tam);
int cantidadPalabras(listaChar lista, int tam);
int cantidadVocales(listaChar lista, int tam);
int cantidadConsonantes(listaChar lista, int tam);

int main() {
	int tam;
	listaChar lista;	
	
	cargarLista(lista, &tam);
	trimLista(lista, &tam);
	enMinusculas(lista, tam);
	printf("Cantidad de palabras:%d\n", cantidadPalabras(lista, tam));
	printf("Cantidad de vocales:%d\n", cantidadVocales(lista, tam));
	printf("Cantidad de consonantes:%d\n", cantidadConsonantes(lista, tam));
	
	return 0;
}


void cargarLista(listaChar lista, int *tam){
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
	Borra los espaciones en blanco de adelante y de atras de la lista.
	Ejemplos:
		trimLista([" ", " ", "a", "b", " ","c", " "], 7) -> (["a", "b", " ","c"], 4)
		trimLista(["a", "b",  " ","c"], 4) -> (["a", "b", " ","c"], 4) 
*/
void trimLista(listaChar lista, int *tam){
	int i;
	
	i = 1;
	while(lista[i] == ' ' && i <= *tam){
		eliminarCaracter(lista, *tam, i);
		*tam = *tam - 1;
		i++;
	}
	i = *tam;
	while(lista[i] == ' ' && i >= 1){
		eliminarCaracter(lista, *tam, i);
		*tam = *tam - 1;
		i--;
	}
}

/*
	Elimina un caracter de la lista.
	No reduce el tamaño.
	Ejemplos:
		eliminarCaracter(["a", "b", "c"], 3, 1) -> (["b", "c", "c"])
		eliminarCaracter(["a", "b", "c"], 3, 2) -> (["a", "c", "c"])
*/
void eliminarCaracter(listaChar lista, int tam, int posi){
	int i;
	
	for(i = posi; i <= tam - 1; i++){
		lista[i] = lista[i + 1];
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
	Devuelve la cantidad de palabras, si se ingresaron solo espacios en blanco devuelve 0.
	Espera una cadena sin espacios en blanco adelante o al final.
	Ejemplos:
		cantidadPalabras(["a", "b", " ","c"], 4) -> 2
		cantidadPalabras(["a", "b", "c"], 3) -> 1
*/
int cantidadPalabras(listaChar lista, int tam){
	int i, cantidad;
	
	if(tam > 0){
		cantidad = 1;
		for(i = 1; i <= tam; i++){
			if(lista[i] == ' '){
				cantidad++;
			}
		}
	}else{
		cantidad = 0;
	}
	
	return cantidad;
}

int cantidadVocales(listaChar lista, int tam){
	int i,cantidad;
	
	cantidad = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] == 'a' || lista[i] == 'e' || lista[i] == 'i' || lista[i] == 'o' || lista[i] == 'u'){
			cantidad++;
		}
	}
	
	return cantidad;
}

int cantidadConsonantes(listaChar lista, int tam){
	int i,cantidad;
	
	cantidad = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] != 'a' && lista[i] != 'e' && lista[i] != 'i' && lista[i] != 'o' && lista[i] != 'u' && lista[i] != ' '){
			cantidad++;
		}
	}
	
	return cantidad;
}

