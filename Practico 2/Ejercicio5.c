/*
Autor: Fernando Orquera
Año: 2017 
*/

#include <stdio.h>

/*
	Usando la Criba de Eratóstenes
	https://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes
*/
int main() {
	int k,i,j;
	int lista[100];
	
	printf("Ingrese el numero natural de dos cifras:\n");
	scanf("%d", &k);
	
	for(i = 2; i < k; i++){
		lista[i] = 0;
	}
	
	i = 2;
	while(i < k){
		for(j = i + i; j < k; j = j + i){
			lista[j] = 1;
		}
		i++;
		while(lista[i] == 1 && i < k){
			i++;
		}
	}
	
	for(i = 2; i < k; i++){
		if(lista[i] == 0){
			printf("%d\n", i);
		}
	}
	
	return 0;
}

