#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=50;

typedef char Tcadena[50]; 

typedef struct{
	Tcadena dni;
	Tcadena apellido;
	Tcadena nombre;
	Tcadena fecha;
	int cantidad;
	int numero;
	int tipo; /*(1-Simple, 2- Doble, 3-Triple)*/
}tReserva;

typedef tReserva listaReservas[100];

int menu();
int leeCad(Tcadena, int);
tReserva cargarUna();
void mostrarUna(tReserva reg);
void cargarReservas(listaReservas lista, int *tam);
void mostrarReservas(listaReservas lista, int tam);
int buscarApellido(listaReservas lista, int tam, Tcadena buscado);
void informarPago(tReserva);
int buscarHabitacion(listaReservas lista, int tam, int buscado);


int main(int argc, char *argv[]) {
	int opcion, tam, posi, habBuscada;
	listaReservas lista;
	Tcadena apBuscado;
		
	tam = 0;
	do{
		opcion = menu();
		switch(opcion){
		case 1:			
			cargarReservas(lista, &tam);
			break;
		case 2:
			if(tam > 0){
				mostrarReservas(lista, tam);
			}else{
				printf("No hay reservas.\n");
			}			
			break;
		case 3:
			if(tam > 0){
				printf("\n Ingrese apellido a buscar:");				
				leeCad(apBuscado, tam_max);
				posi = buscarApellido(lista, tam, apBuscado);
				if(posi != -1){
					informarPago(lista[posi]);
				}else{
					printf("\nNo se encontro la reserva.");
				}
			}else{
				printf("No hay reservas.\n");
			}		
			break;
		case 4:
			if(tam > 0){
				printf("\n Ingrese numero de habitacion a buscar:");
				scanf("%d", &habBuscada);
				posi = buscarHabitacion(lista, tam, habBuscada);
				if(posi != -1){
					mostrarUna(lista[posi]);
				}else{
					printf("\nLa habitacion no esta reservada.");
				}	
			}else{
				printf("No hay reservas.\n");
			}
			break;		
		}
	}while(opcion != 0);
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Cargar reserva.\n");
		printf("2 - Mostrar reservas.\n");
		printf("3 - Mostrar cuanto debe abonar.\n");
		printf("4 - Mostrar datos de una reserva.\n");	
		printf("0 - Salir.\n");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 && op > 4);
	
	return op;
}

int leeCad(Tcadena cadena, int tam){
	int j, ret;
	char c;
	j=0;
	fflush(stdin);
	c=getchar();
	ret=0;
	while (c!=EOF && c!='\n' && j<tam-1)
	{
		cadena[j]=c;
		j++;
		c=getchar();
		ret=1;
	}
	cadena[j]='\0';
	
	while(c!=EOF && c!='\n')
		c=getchar();
	return ret;
}

/*
	Carga una reserva.
*/
tReserva cargarUna(){
	tReserva nueva;
	
	printf("\n Ingrese DNI:");
	leeCad(nueva.dni, tam_max);
	printf("\n Ingrese Apellido:");
	leeCad(nueva.apellido, tam_max);
	printf("\n Ingrese Nombre:");
	leeCad(nueva.nombre, tam_max);
	printf("\n Ingrese fecha de ingreso dd/mm/aaaa:");
	leeCad(nueva.fecha, tam_max);
	printf("\n Ingrese cantidad de dias:");
	scanf("%d", &nueva.cantidad);
	printf("\n Ingrese numero de habitacion:");
	scanf("%d", &nueva.numero);
	printf("\n Ingrese tipo de habitacion, 1-Simple, 2- Doble, 3-Triple:");
	scanf("%d", &nueva.tipo);
	
	return nueva;
}

void mostrarUna(tReserva reg){
	
	printf("\n DNI: %s", reg.dni);
	printf("\n Apellido: %s", reg.apellido);
	printf("\n Nombre: %s", reg.nombre);
	printf("\n Fecha de ingreso: %s", reg.fecha);
	printf("\n Cantidad de dias: %d", reg.cantidad);
	printf("\n Numero de habitacion: %d", reg.numero);
	printf("\n Tipo de habitacion: ");
	switch(reg.tipo){
		case 1 : 
			printf("Simple");
			break;
		case 2:
			printf("Doble");
			break;
		case 3:
			printf("Triple");
			break;
	}
}

void cargarReservas(listaReservas lista, int *tam){
	int i;
	tReserva aux;	
	
	aux = cargarUna();
	lista[0] = aux;
	i = *tam;
	while(strcmp(aux.apellido, lista[i].apellido) < 0){
		lista[i + 1] = lista[i];
		i--;
	}
	lista[i + 1] = aux;
	*tam = *tam + 1;	
}

void mostrarReservas(listaReservas lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		printf("\n---------------------");
		mostrarUna(lista[i]);
	}
	printf("\n---------------------");
	printf("\n\n");
}

int buscarApellido(listaReservas lista, int tam, Tcadena buscado){
	int ini, fin, med;
	
	ini = 1;
	fin = tam;
	med = (ini + fin) / 2;
	while(ini <= fin && strcmp(lista[med].apellido, buscado) != 0){
		if(strcmp(lista[med].apellido, buscado) < 0){
			ini = med + 1;
		}else{
			fin = med - 1;
		}
		med = (ini + fin) / 2;
	}
	if(ini <= fin){
		return med;
	}else{
		return -1;
	}
}

void informarPago(tReserva reg){
	
	printf("\n El pago faltante es de: $ ");
	switch(reg.tipo){
	case 1 : 
		printf("%.2f", reg.cantidad * 800.00 * 0.4);
		break;
	case 2:
		printf("%.2f", reg.cantidad * 990.00 * 0.4);
		break;
	case 3:
		printf("%.2f", reg.cantidad * 1500.00 * 0.4);
		break;
	}
}

int buscarHabitacion(listaReservas lista, int tam, int buscado){
	int i;
	
	i = 1;
	while(i <= tam && lista[i].numero != buscado){
		i++;
	}
	if(i <= tam){
		return i;
	}else{
		return -1;
	}
}
