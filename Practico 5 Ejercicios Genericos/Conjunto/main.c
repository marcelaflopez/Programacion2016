#include <stdio.h>
#include "conjunto.h"

int menu();

int main(){
	tConjunto conjunto1, conjunto2, conjunto3;
	int op;
	
	conjunto1 = iniciar();
	conjunto2 = iniciar();
	conjunto3 = iniciar();
	do{
		op = menu();
		switch(op){
		case 1:
			insertarUno(&conjunto1);
			break;
		case 2:
			insertarUno(&conjunto2);
			break;
		case 3:
			eliminarUno(&conjunto1);
			break;
		case 4:
			eliminarUno(&conjunto2);
			break;
		case 5:
			conjunto3 = unionConjuntos(conjunto1, conjunto2);
			mostrarConjunto(conjunto3);
			break;
		case 6:
			conjunto3 = interseccionConjuntos(conjunto1, conjunto2);
			mostrarConjunto(conjunto3);
			break;
		case 7:
			conjunto3 = diferenciaConjuntos(conjunto1, conjunto2);
			mostrarConjunto(conjunto3);
			break;
		case 8:
			mostrarConjunto(conjunto1);
			break;
		case 9:
			mostrarConjunto(conjunto2);
			break;
		}
	}while(op != 0);
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Agregar un elemento al primer conjunto.");
		printf("\n2 - Agregar un elemento al segundo conjunto.");
		printf("\n3 - Eliminar un elemento del primer conjunto.");
		printf("\n4 - Eliminar un elemento del segundo conjunto.");
		printf("\n5 - Union entre el primer conjunto y segundo.");
		printf("\n6 - Interseccion entre el primer conjunto y segundo.");
		printf("\n7 - Diferencia entre el primer conjunto y segundo.");
		printf("\n8 - Mostrar el primer conjunto.");
		printf("\n9 - Mostrar el segundo conjunto.");
		printf("\n0 - Salir.");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 || op > 9);
	
	return op;
}
