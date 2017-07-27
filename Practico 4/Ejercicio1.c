#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int tvec[100];

void cargarLista(tvec lista,int *tam);
void mostrarLista(tvec lista, int tam);
void ordenarLista(tvec lista,int tam);
int repiteMas(tvec lista, int tam);
int buscarLista(tvec lista, int tam, int bus);
void eliminarLista(tvec lista, int *tam, int pos);
void mostrarVecino(tvec lista, int tam, int pos);
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
	num = repiteMas(lista,tam);
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
		if ( posi != -1){
			mostrarVecino(lista,tam,posi);
		}
		else{
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
	Ordena la lista usando el metodo de seleccion directa de mayor a menor.
*/
void ordenarLista(tvec lista, int tam){
	int i,j,aux;
	
	for(i=1;i<=tam-1;i++){
		for(j=i+1;j<=tam;j++){
			if(lista[i] < lista[j]){
				aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;
			}
		}
	}
}

/*
	Retorna el valor del numero que mas se repite.
	Considera que la lista esta ordenada.
	Ejemplos.
		repiteMas([1,1,1,2,2], 5) -> 1
		repiteMas([2,2,5,5,5,5,7,7,8], 9) -> 5 
*/
int repiteMas(tvec lista,int tam){
	int cont,i,j,mayor,num;
	
	cont=1;
	i=1;
	j=2;
	mayor = cont;
	num = lista[i];
	while(i<=tam){
		while(j<=tam && lista[i]==lista[j]){
			cont = cont + 1;
			j = j + 1;
		}
		if (cont > mayor){
			mayor = cont;
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
	ordenada de mayor a menor.
*/
int buscarLista(tvec lista, int tam, int bus){
	int ini,fin,m;
	
	ini = 1;
	fin = tam;
	m = (ini+fin)/2;
	while (ini<=fin && lista[m] != bus){
		if(lista[m] > bus){
			ini = m+1;
		}
		else{
			fin = m-1;
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
	Muestra los vecinos de un elemento, dada la posicion.
	Ejemplos:
		mostrarVecino([1, 2 ,3], 3, 2) -> "Vecino a la derecha 3", "Vecino a la izquierda 1"
		mostrarVecino([1,2], 2, 2) -> "No tiene vecino a la derecha", "Vecino a la izquierda 1"
		mostrarVecino([1], 1, 1) -> "No tiene vecinos"
*/
void mostrarVecino(tvec lista, int tam, int pos){
	if(tam != 1){
		if (pos == 1){
			printf("No tiene vecino a la izquierda.\n");
			printf("Vecino a la derecha:%d \n",lista[pos+1]);
		}
		else if (pos == tam){
			printf("Vecino a la izquierda:%d \n",lista[pos-1]);
			printf("No tiene vecino a la derecha.\n");		
		}
		else {
			printf("Vecino a la izquierda:%d \n",lista[pos-1]);
			printf("Vecino a la derecha:%d \n",lista[pos+1]);
		}	
	}else{
		printf("No tiene vecinos.\n");
	}
}

/*
	Inserta un elemento de manera ordenada.
*/
void insertarLista(tvec lista, int *tam, int elem){
	
	int i;
		
	lista[0] = elem;
	i = *tam;
	while( elem > lista[i]){
		lista[i+1] = lista[i];
		i = i - 1;
	}
	lista[i+1] = elem;
	*tam = *tam + 1;
}
