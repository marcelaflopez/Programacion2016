#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int tvec[100];

void cargarLista(tvec lista, int *tam);
void mostrarLista(tvec lista, int tam);
float mediaAritmetica(tvec lista, int tam);
void insertarFrec(tvec lista, int *tam,int frec, int posi);
void eliminarLista(tvec lista, int *tam ,int posi);
void frecuenciaLista(tvec lista, int *tam);
void mayorModa(tvec lista, int tam, int *moda, int *frecuencia);
int modaUnica(tvec lista,int tam, int frecuencia);
void indicarModa(int moda, int med);


int main() {
	
	tvec lista;
	int tam, moda, frecuencia, bmoda;
	float mediaA;	
	
	cargarLista(lista, &tam);
	printf("\n Mostrando la lista:");
	mostrarLista(lista, tam);
	mediaA=mediaAritmetica(lista, tam);
	frecuenciaLista(lista, &tam);
	printf("\n Mostrando la lista compactada:");
	mostrarLista(lista, tam);
	mayorModa(lista, tam, &moda, &frecuencia);
	bmoda = modaUnica(lista, tam, frecuencia);
	if(bmoda == 1){
		indicarModa(moda, mediaA);
	}else
		printf("\n La moda no es unica.");
	
	return 0;
}


void cargarLista(tvec lista, int *tam){
	
	int i;
	
	printf("\n Ingrese el tama%co de la lista:", 164);
	scanf("%d",tam);
	for(i = 1; i <= *tam; i++){
		printf("\n Ingrese el %d %c elemento de la lista:", i, 167);
		scanf("%d", &lista[i]);
	}
}

void mostrarLista(tvec lista, int tam){
	int i;
	
	for(i = 1 ; i <= tam; i++){
		printf(" %d \t", lista[i]);
	}
}

/*
	Calcula la media aritmetica de una lista.
	Ejemplos:
		mediaAritmetica([3, 5, 7], 3) -> 5
		mediaAritmetica([2, 5, 4], 3) -> 3.66
		mediaAritmetica([], 0) -> 0
*/
float mediaAritmetica(tvec lista, int tam){
	int i;
	float sum;
		
	sum = 0;
	for(i = 1; i <= tam; i++){
		sum = sum + lista[i];
	}
	sum = sum / tam;
	return sum;
}

/*
	Inserta a la derecha de un elemento su frecuencia.
	Ejemplos:
		insertarFrec([1, 2, 2], 3, 3, 2) -> ([1, 3, 2, 2], 4)
*/
void insertarFrec(tvec lista, int *tam,int frec ,int posi){
	int i;
	
	for(i = *tam; i >= posi ; i--){
		lista[i+1] = lista[i];
	}
	lista[posi] = frec;
	*tam = *tam + 1;
}

/*
	Elimina un elemento de la lista dada una posicion.
*/
void eliminarLista(tvec lista, int *tam ,int posi){
	int i;
	
	for(i = posi; i <= *tam - 1; i++){
		lista[i]=lista[i+1];
	}
	*tam = *tam - 1;
}

/*
	Calcula la frecuencia de cada elemento de la lista,
	va eliminando cada repeticion y luego inserta
	el valor de la frecuencia a la derecha de cada elemento
*/
void frecuenciaLista(tvec lista, int *tam){
	int i,j,cont;
	
	i = 1;
	j = 2;
	cont = 1;
	while(i <= *tam){
		while(j <= *tam){
			if(lista[i] == lista[j]){
				cont = cont + 1;
				eliminarLista(lista,tam,j);
			}
			else
				j = j + 1;
		}
		insertarFrec(lista, tam, cont, i+1);
		cont = 1;
		i = i + 2;
		j = i + 1;
	}
}

/*
	Retorna el valor con mayor moda y su frecuencia.
	Tiene que recibir la lista con la frecuencua 
	insertada a la derecha.
	Ejemplos:
		mayorModa([1, 3, 2, 1], 4) -> (1, 3)
		mayorModa([3, 2, 5, 3, 1, 1], 6) -> (5, 3)	
*/
void mayorModa(tvec lista, int tam, int *moda, int *frecuencia){
	int i;
	
	*moda = lista[1];
	*frecuencia = lista[2];
	for(i = 4; i <= tam; i = i + 2){
		if(lista[i] > *frecuencia){
			*moda = lista[i - 1];
			*frecuencia = lista[i];
		}
	}
}

/*
	Devuelve 1 si la moda es unica.
	-1 si no lo es.
*/
int modaUnica(tvec lista,int tam, int frecuencia){
	int i,band;
	
	band=0;
	i=2;
	while(i<= tam && band < 2){
		if (lista[i] == frecuencia){
			band = band + 1;
		}
		i = i + 2;
	}
	if (band < 2 ){
		return 1; /*La moda es unica*/
	}else{
		return 0; /*La moda no es unica*/
	}
}

void indicarModa(int moda, int med){
	
	if (moda > med){
		printf("\n La moda (%d) es mayor a la media aritmetica (%d).", moda, med);		
	}else if(moda < med){
		printf("\n La moda (%d) es menor a la media aritmetica (%d).", moda, med);		
	}else{
		printf("\n La moda (%d) es igual a la media aritmetica (%d).", moda, med);
	}
}
