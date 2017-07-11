#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int listaInt[50];

void cargarLista(listaInt lista, int *tam);
int ultimoDigito(int numero);

int main() {
	listaInt lista;
	int tam, cont1, cont2, cont3, cont4 , cont5, i, ultimoDig;
	float prom1, prom2, prom3, prom4, prom5; /*prom1 = {0, 1}; prom2 = {2, 3}, prom3 = {4, 5}; prom4 = {6, 7}, prom5 = {8, 9}*/
	
	prom1 = 0;
	prom2 = 0;
	prom3 = 0;
	prom4 = 0;
	prom5 = 0;
	cont1 = 0;
	cont2 = 0;
	cont3 = 0;
	cont4 = 0;
	cont5 = 0;
	
	cargarLista(lista, &tam);	
	for(i = 1; i <= tam; i++){
		ultimoDig = lista[i] % 10;
		switch(ultimoDig){
			case 0: case 1: prom1 = prom1 + lista[i];
							cont1 = cont1 + 1;
							break;
			case 2: case 3: prom2 = prom2 + lista[i];
							cont2 = cont2 + 1;
							break;		
			case 4: case 5: prom3 = prom3 + lista[i];
							cont3 = cont3 + 1;
							break;	
			case 6: case 7: prom4 = prom4 + lista[i];
							cont4 = cont4 + 1;
							break;	
			case 8: case 9: prom5 = prom5 + lista[i];
							cont5 = cont5 + 1;
							break;				
		}
	}
	
	if(cont1 != 0){
		printf("El promedio de los numeros que terminan en 0 o 1 es:%.2f\n", prom1 / cont1);
	} else {
		printf("No hay numeros que terminen en 0 o 1\n");
	}
	if(cont2 != 0){
		printf("El promedio de los numeros que terminan en 2 o 3 es:%.2f\n", prom2 / cont2);
	} else {
		printf("No hay numeros que terminen en 2 o 3\n");
	}
	if(cont3 != 0){
		printf("El promedio de los numeros que terminan en 4 o 5 es:%.2f\n", prom3 / cont3);
	} else {
		printf("No hay numeros que terminen en 4 o 5\n");
	}
	if(cont4 != 0){
		printf("El promedio de los numeros que terminan en 6 o 7 es:%.2f\n", prom4 / cont4);
	} else {
		printf("No hay numeros que terminen en 6 o 7\n");
	}
	if(cont5 != 0){
		printf("El promedio de los numeros que terminan en 8 o 9 es:%.2f\n", prom5 / cont5);
	} else {
		printf("No hay numeros que terminen en 8 o 9\n");
	}
	
	return 0;
}

void cargarLista(listaInt lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c edad:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%d", &lista[i]);
	}
}


