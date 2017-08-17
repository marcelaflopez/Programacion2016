#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int tvec[100];

void cargarLista(tvec lista,int *tam);
void mostrarLista(tvec lista, int tam);
void ordenarLista(tvec lista,int tam);
int repiteMenos(tvec lista,int tam);
int buscarLista(tvec lista, int tam, int bus);
void eliminarLista(tvec lista, int *tam, int pos);
void mostrarMultiplos(int k);
void insertarLista(tvec lista, int *tam, int elem);

	
	
int main() {
	
	tvec lista;
	int tam;
	int k,num,posi;
	
	cargarLista(lista,&tam);
	printf("\n Lista :");
	mostrarLista(lista,tam);
	ordenarLista(lista,tam);
	printf("\n Lista ordenada:");
	mostrarLista(lista,tam);
	num = repiteMenos(lista,tam);
	posi = buscarLista(lista,tam,num);	
	while( posi != -1){
		eliminarLista(lista,&tam,posi);
		posi = buscarLista(lista,tam,num);
	}
	printf("\n Lista depurada:");
	if(tam != 0){
		mostrarLista(lista,tam);
		printf("\n Ingrese numero k a buscar:");
		scanf("%d",&k);
		posi = buscarLista(lista,tam,k);
		if(posi != -1){
			printf("\nSi se encuentra en la lista.");
			mostrarMultiplos(k);
		}else{
			insertarLista(lista,&tam,k);
			printf("\n Elemento insertado con exito:");
			mostrarLista(lista,tam);
		}
	}else{
		printf("La lista quedo vacia!\n");
	}	
	
	return 0;
}

void cargarLista(tvec lista, int *tam){
	int i;
	
	printf("Ingrese tama%co de la lista:\n", 164);
	scanf("%d",tam);
	for(i=1;i<=*tam;i++){
		printf("\nIngrese el %d %c de la lista: ", i, 167);
		scanf("%d",&lista[i]);
	}
}

void mostrarLista(tvec lista, int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		printf(" %d\t",lista[i]);
	}
}

/*
	Ordena la lista usando el metodo de seleccion directa de menor a mayor.
*/
void ordenarLista(tvec lista, int tam){
	int i,j,aux;
	
	for(i=1;i<=tam-1;i++){
		for(j=i+1;j<=tam;j++){
			if(lista[j] < lista[i]){
				aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;
			}
		}
	}
}

/*
	Retorna el valor del numero que menos se repite.
	Considera que la lista esta ordenada.
	Ejemplos.
		repiteMenos([1,1,1,2,2], 5) -> 2
		repiteMenos([2,2,5,5,5,5,7,7,8], 9) -> 8 
*/
int repiteMenos(tvec lista,int tam){
	int cont, i, j, menor, num, band;
	
	cont=1;
	i=1;
	j=2;
	band = 0;
	num = lista[i];
	while(i<=tam){
		while(j<=tam && lista[i]==lista[j]){
			cont = cont + 1;
			j = j + 1;
		}
		if(band != 0){
			if (cont < menor){
				menor = cont;
				num = lista[i];
			}
		}else{
			menor = cont;
			num = lista[i];
		}		
		i = j;
		j = i +1;
		cont = 1;
	}
	return num;
}

/*
	Busqueda binaria. Teniendo en cuenta que la lista esta
	ordenada de menor a mayor.
*/
int buscarLista(tvec lista, int tam, int bus){
	int ini,fin,m;
	
	ini = 1;
	fin = tam;
	m = (ini+fin)/2;
	while (ini <= fin && lista[m] != bus){
		if(lista[m] > bus){
			fin = m - 1;
		}
		else{
			ini = m + 1;
		}
		m = (ini+fin)/2;
	}
	if (ini <= fin)
		return m;
	else
		return -1;
}

/*
	Elimina un elemento de la lista, dada una posicion.
*/
void eliminarLista(tvec lista, int *tam, int pos){
	int i;
	
	for(i=pos;i<=*tam-1;i++){
		lista[i]=lista[i+1];
	}
	*tam = *tam - 1;
}

/*
	Muestra los 10 primeros multiplos de un numero natural.
	Ejemplos:
		mostrarMultiplos(2) -> [2, 4, 6 , 8, 10, 12, 14, 16, 18, 20]
*/
void mostrarMultiplos(int k){
	int i;
	
	for(i = 1; i <= 10; i++){
		printf("\nEl %d %c multiplo: %d", i, 167, i * k);
	}
}

/*
	Inserta un elemento de manera ordenada.
*/
void insertarLista(tvec lista, int *tam, int elem){
	
	int i;
		
	lista[0] = elem;
	i = *tam;
	while( elem < lista[i]){
		lista[i+1] = lista[i];
		i = i - 1;
	}
	lista[i+1] = elem;
	*tam = *tam + 1;
}
