#include <stdio.h>
#include <math.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

int esPrimo(int numero);
int nPrimo(int n);

int main(int argc, char *argv[]) {
	int  n;		
	
	printf("Ingrese N para encontrar el N-esimo primo:\n");
	scanf("%d", &n);	
	printf("El n-esimo primo es: %d\n", nPrimo(n));
	
	return 0;
}


/*
	Devuelve 1 si el numero es primo, -1 en caso contrario.
*/
int esPrimo(int numero){
	int pd;
	
	pd = 2;
	while(pd <= sqrt(numero) && numero % pd != 0){
		pd++;
	}
	if(pd > sqrt(numero)){
		return 1;	
	}else{
		return -1;	
	}
}

int nPrimo(int n){
	int contador, posible_primo;
	
	contador = 1;
	posible_primo = 2;
	while(contador != n){
		posible_primo++;
		if(esPrimo(posible_primo) == 1){
			contador++;
		}
	}
	
	return posible_primo;
}
