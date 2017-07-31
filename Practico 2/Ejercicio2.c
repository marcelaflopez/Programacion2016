#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
float promedioLista(listaInt lista, int tam);
int mayorLista(listaInt lista, int tam, float promedio);

int main() {
	listaInt lista;
	int tam;
	float promedio;
	
	cargarLista(lista, &tam);
	promedio = promedioLista(lista, tam);
	printf("El promedio de la lista: %.2f\n", promedio);
	printf("La mayor edad que es menor al promedio es: %d\n", mayorLista(lista, tam, promedio));
	
	return 0;
}

void cargarLista(listaInt lista, int *tam){
	int i, op;
	
	i = 1;
	do{
		printf("Ingrese %d %c edad:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%d", &lista[i]);
		i++;
		printf("Desea ingresar otro? 1-SI 0-NO:\n");
		scanf("%d", &op);
	}while(op != 0);
	*tam = i - 1;
}

float promedioLista(listaInt lista, int tam){
	float sum;
	int i;
	
	for(i = 1; i <= tam; i++){
		sum = sum + lista[i];
	}
	
	return sum / tam;
}


int mayorLista(listaInt lista, int tam, float promedio){
	int mayor, band;
	int i;	
	
	band = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i] < promedio){
			if(band != 0){
				if(lista[i] > mayor){
					mayor = lista[i];
				}
			}else{
				mayor = lista[i];
				band = 1;
			}		
		} 
	}
	
	return mayor;
}


