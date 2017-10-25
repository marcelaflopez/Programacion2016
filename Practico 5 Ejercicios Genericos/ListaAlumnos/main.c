#include "lista.h"
#include <stdio.h>

int menu();

int main(){
	tLista reg;
	int buscado, op;
	
	reg = iniciar();
	do{
		op = menu();
		switch(op){
		case 1:
			if(listaLlena(reg) != 1)
				insertarOrdenado(&reg);
			else
				printf("\nLa lista esta llena.");
			break;
		case 2:
			printf("\nIngrese DNI a buscar:");/*SE PUEDE TENER UN MÓDULO EN ALUMNO QUE BUSQUE DNI*/
			scanf("%d", &buscado);
			modificarAlumno(&reg, buscado);
			break;
		case 3:
			printf("\nIngrese DNI a buscar:");
			scanf("%d", &buscado);
			eliminarAlumno(&reg, buscado);
			break;
		case 4:
			if(listaVacia(reg) != 1)
				mostrarLista(reg);
			else
				printf("\nLa lista se encuentra vacia");
			break;		
		}
	}while(op != 0);	
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n");
		printf("\n1 - Agregar un alumno.");
		printf("\n2 - Modificar un alumno.");
		printf("\n3 - Eliminar un alumno.");
		printf("\n4 - Mostrar alumnos.");		
		printf("\n0 - Salir.");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 || op > 4);
	
	return op;
}
