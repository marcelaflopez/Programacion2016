#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef char tCadena[100];
typedef int tFrecuencia[100];

void cargarLista(tCadena lista, int *tam);
void mostrarLista(tCadena lista, int tam);
void eliminarLista(tCadena lista, int *tam ,int posi);
void frecuenciaLista(tCadena lista, int *tam, tFrecuencia frec);
void mayorModa(tFrecuencia lista, int tam, int *frecuencia, int *posicion);
int modaUnica(tFrecuencia lista,int tam, int frecuencia);

int main() {
	
	tCadena lista;
	tFrecuencia lfrecuencia;
	int tam, posicion, frecuencia, bmoda;;	
	
	cargarLista(lista, &tam);
	printf("\n Mostrando la lista:");
	mostrarLista(lista, tam);
	frecuenciaLista(lista, &tam, lfrecuencia);
	printf("\n Mostrando la lista compactada:");
	mostrarLista(lista, tam);
	mayorModa(lfrecuencia, tam, &frecuencia, &posicion);
	bmoda = modaUnica(lfrecuencia, tam, frecuencia);
	if(bmoda == 1){
		printf("\n La letra moda es: %c", lista[posicion]);
		printf("\n Su frecuencia es : %d", frecuencia);
	}else
		printf("\n La moda no es unica.");
	
	return 0;
}


void cargarLista(tCadena lista, int *tam){
	
	int i;
	
	printf("\n Ingrese el tama%co de la lista:", 164);
	scanf("%d",tam);
	for(i = 1; i <= *tam; i++){
		printf("\n Ingrese la %d %c letra de la lista:", i, 167);
		fflush(stdin);
		scanf("%c", &lista[i]);
	}
}

void mostrarLista(tCadena lista, int tam){
	int i;
	
	for(i = 1 ; i <= tam; i++){
		printf(" %c \t", lista[i]);
	}
}

/*
Elimina un elemento de la lista dada una posicion.
*/
void eliminarLista(tCadena lista, int *tam ,int posi){
	int i;
	
	for(i = posi; i <= *tam - 1; i++){
		lista[i]=lista[i+1];
	}
	*tam = *tam - 1;
}

/*
Calcula la frecuencia de cada elemento de la lista,
va eliminando cada repeticion y luego inserta
la frecuencia en una lista nueva,
*/
void frecuenciaLista(tCadena lista, int *tam, tFrecuencia frec){
	int i,j,cont;
	
	i = 1;
	j = 2;
	cont = 1;
	while(i <= *tam){
		while(j <= *tam){
			if(lista[i] == lista[j]){
				cont = cont + 1;
				eliminarLista(lista, tam, j);
			}
			else
				j = j + 1;
		}
		frec[i] = cont;
		cont = 1;
		i++;
		j = i + 1;
	}
}

/*
Retorna la mayor frecuencia y su posicion.
Tiene que recibir la lista de frecuencias.
Ejemplos:
mayorModa([1, 3, 2, 1], 4) -> (3, 2)
mayorModa([3, 2, 5, 3, 1, 1], 6) -> (5, 3)	
*/
void mayorModa(tFrecuencia lista, int tam, int *frecuencia, int *posicion){
	int i;
	
	*frecuencia = lista[1];
	*posicion = 1;
	for(i = 2; i <= tam; i++){
		if(lista[i] > *frecuencia){
			*frecuencia = lista[i];
			*posicion = i;
		}
	}
}

/*
Devuelve 1 si la moda es unica.
-1 si no lo es.
*/
int modaUnica(tFrecuencia lista,int tam, int frecuencia){
	int i,band;
	
	band=0;
	i=1;
	while(i <= tam && band < 2){
		if (lista[i] == frecuencia){
			band = band + 1;
		}
		i++;
	}
	if (band < 2 ){
		return 1; /*La moda es unica*/
	}else{
		return 0; /*La moda no es unica*/
	}
}


