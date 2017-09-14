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
	int codigo;
	Tcadena localidad;
	Tcadena cliente;
	Tcadena fecha;
	float valor;
}tAlquiler;

typedef tAlquiler listaAlquileres[100];

int menu();
int leeCad(Tcadena, int);
tAlquiler cargarUna();
void mostrarUna(tAlquiler reg);
void cargarAlquileresA(listaAlquileres lista, int *tam);
void cargarAlquileresB(listaAlquileres lista, int *tam);
void mostrarAlquileres(listaAlquileres lista, int tam);
void ordenar(listaAlquileres lista, int tam);


int main(int argc, char *argv[]) {
	int opcion, tam, tam2;
	listaAlquileres lista;	
	
	tam2 = 0;
	do{
		opcion = menu();
		switch(opcion){
		case 1:			
			cargarAlquileresA(lista, &tam);
			break;
		case 2:
			if(tam > 0){
				mostrarAlquileres(lista, tam);
			}else{
				printf("No hay alquileres.\n");
			}			
			break;
		case 3:
			if(tam > 0){
				ordenar(lista, tam);
				mostrarAlquileres(lista, tam);
			}else{
				printf("No hay alquileres.\n");
			}		
			break;
		case 4:
			cargarAlquileresB(lista, &tam2);
			mostrarAlquileres(lista, tam2);
			break;		
		}
	}while(opcion != 0);
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Cargar alquileres.\n");
		printf("2 - Mostrar alquileres.\n");
		printf("3 - Ordenar lista completa.\n");
		printf("4 - Cargar un solo alquiler de manera ordenada.\n");	
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
tAlquiler cargarUna(int i){
	tAlquiler nueva;
	
	nueva.codigo = i;
	printf("\n Ingrese Localidad:");
	leeCad(nueva.localidad, tam_max);
	printf("\n Ingrese cliente:");
	leeCad(nueva.cliente, tam_max);
	printf("\n Ingrese tiempo de alquiler en dias :");
	leeCad(nueva.fecha, tam_max);	
	printf("\n Ingrese valor del contrato:");
	scanf("%f", &nueva.valor);
	
	return nueva;
}

void mostrarUna(tAlquiler reg){
	
	printf("\n Codigo: %d", reg.codigo);
	printf("\n Localidad: %s", reg.localidad);
	printf("\n Cliente: %s", reg.cliente);
	printf("\n Tiempo de alquiler: %s dias", reg.fecha);
	printf("\n Valor del contrato: %.2f", reg.valor);
}

void cargarAlquileresA(listaAlquileres lista, int *tam){
	int i;
	
	printf("\nIngrese cantidad de alquileres:");
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		lista[i] = cargarUna(i);
	}
}

void cargarAlquileresB(listaAlquileres lista, int *tam){
	int i;
	tAlquiler aux;	
	
	aux = cargarUna(*tam + 1);
	lista[0] = aux;
	i = *tam;
	while((strcmp(aux.localidad, lista[i].localidad) < 0) || (strcmp(aux.localidad, lista[i].localidad) == 0 && aux.valor < lista[i].valor)){
		lista[i + 1] = lista[i];
		i--;
	}
	lista[i + 1] = aux;
	*tam = *tam + 1;	
}

void mostrarAlquileres(listaAlquileres lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		printf("\n---------------------");
		mostrarUna(lista[i]);
	}
	printf("\n---------------------");
	printf("\n\n");
}


void ordenar(listaAlquileres lista, int tam){
	int i, j;
	tAlquiler aux;
	
	for(i = 1; i <= tam - 1; i++){
		for(j = i + 1; j <= tam; j++){
			if((strcmp(lista[j].localidad,lista[i].localidad) == 0 && lista[j].valor < lista[i].valor) || (strcmp(lista[j].localidad,lista[i].localidad) < 0)){
				aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;							
			}
		}
	}
}



