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
	Tcadena patente;
	Tcadena modelo;
	Tcadena falla;
	int dni;
	Tcadena apellido;
	Tcadena nombre;
	Tcadena telefono;
	Tcadena estado;
}tVehiculo;

typedef tVehiculo tLista[100];
typedef int tIndice[100];

int menu();
int leeCad(Tcadena, int);
tVehiculo cargarUno(int i);
void insertarUno(tLista lista, tIndice indice, int posicion);
void insertarUnoPatente(tLista lista, tIndice indice, int posicion);
void cargarIndice(tLista lista, tIndice indiceCodigo, tIndice indicePatente, int tam);
void cargarListaUno(tLista lista, tIndice indiceCodigo, tIndice indicePatente, int *tam);
int buscarCodigo(tLista lista, tIndice indice, int tam, int buscado);
void eliminarUno(tLista lista, int *tam, int posicion);
void modificarRegistro(tVehiculo *reg);
void mostrarUno(tVehiculo reg);
void mostrarListaPatente(tLista lista, tIndice indice, int tam);
void mostrar(tLista lista, int tam);

int main(int argc, char *argv[]) {
	int tam, codigo, posicion, opcion;
	tLista lista;
	tIndice indiceCodigo;
	tIndice indicePatente;
	
	tam = 0;
	do{
		opcion = menu();
		switch(opcion){
		case 1:			
			cargarListaUno(lista, indiceCodigo, indicePatente, &tam);
			break;
		case 2:
			if(tam > 0){
				printf("Ingrese codigo:");
				scanf("%d", &codigo);
				posicion = buscarCodigo(lista, indiceCodigo, tam, codigo);
				if(posicion != -1){
					eliminarUno(lista, &tam, posicion);
					cargarIndice(lista, indiceCodigo, indicePatente, tam);
					mostrar(lista, tam);
				}else{
					printf("\nVehiculo no encontado.");
				}
			}else{
				printf("No hay vehiculos.\n");
			}			
			break;
		case 3:
			if(tam > 0){
				printf("Ingrese codigo:");
				scanf("%d", &codigo);
				posicion = buscarCodigo(lista, indiceCodigo, tam, codigo);
				if(posicion != -1){
					modificarRegistro(&lista[posicion]);
					mostrarUno(lista[posicion]);
				}else{
					printf("\nVehiculo no encontado.");
				}
			}else{
				printf("No hay vehiculos.\n");
			}		
			break;
		case 4:
			if(tam > 0){
				mostrarListaPatente(lista, indicePatente, tam);
			}else{
				printf("No hay vehiculos.\n");
			}			
			break;	
		case 5:
			if(tam > 0){
				mostrar(lista, tam);
			}else{
				printf("No hay vehiculos.\n");
			}
			break;	
		}		
	}while(opcion != 0);
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Cargar un vehiculo.\n");
		printf("2 - Eliminar un vehiculo.\n");
		printf("3 - Modificar un vehiculo.\n");
		printf("4 - Mostrar vehiculos ordenados por patente.\n");	
		printf("5 - Mostrar vehiculos ordenados por DNI y patente.\n");
		printf("0 - Salir.\n");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 && op > 5);
	
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
	Retorna un vehiculo cargado.
*/
tVehiculo cargarUno(int i){
	tVehiculo nuevo;
	
	nuevo.codigo = i;
	printf("\n Ingrese patente:");
	leeCad(nuevo.patente, tam_max);
	printf("\n Ingrese modelo del vehiculo:");
	leeCad(nuevo.modelo, tam_max);
	printf("\n Ingrese falla del vehiculo:");
	leeCad(nuevo.falla, tam_max);
	printf("\n Ingrese dni del cliente:");
	scanf("%d", &nuevo.dni);
	printf("\n Ingrese apellido del cliente:");
	leeCad(nuevo.apellido, tam_max);
	printf("\n Ingrese nombre del cliente:");
	leeCad(nuevo.nombre, tam_max);
	printf("\n Ingrese telefono del cliente:");
	leeCad(nuevo.telefono, tam_max);
	printf("\n Ingrese estado del vehiculo:");
	leeCad(nuevo.estado, tam_max);
	
	return nuevo;
}

/*
	Inserta ordenado en el indice de codigo.
*/
void insertarUno(tLista lista, tIndice indice, int posicion){
	int i;
	i = posicion - 1;
	while ((i>0) && (lista[indice[i]].codigo > lista[posicion].codigo)){
		indice[i + 1] = indice[i];
		i--;
	}
	indice[i + 1] = posicion;
}

/*
	Inserta ordenado en el indice de patente.
*/
void insertarUnoPatente(tLista lista, tIndice indice, int posicion){
	int i;
	i = posicion - 1;
	while ((i>0) && (strcmp(lista[indice[i]].patente, lista[posicion].patente)>0)){
		indice[i + 1] = indice[i];
		i--;
	}
	indice[i + 1] = posicion;
}

/*
	Regenera los indices de oodigo y patente
*/
void cargarIndice(tLista lista, tIndice indiceCodigo, tIndice indicePatente, int tam){
	int i;
	for(i=1; i<=tam; i++){
		insertarUno(lista, indiceCodigo, tam);
		insertarUnoPatente(lista, indicePatente, tam);
	}
}

/*
	Carga en la lista un registro ordenado por dni y patente, y realiza la carga de los indices
*/
void cargarListaUno(tLista lista, tIndice indiceCodigo, tIndice indicePatente, int *tam){
	int i;
	tVehiculo aux;
	
	aux = cargarUno(*tam + 1);
	lista[0] = aux;
	i = *tam;
	while((aux.dni != lista[i].dni && strcmp(aux.patente, lista[i].patente) < 0) || (aux.dni < lista[i].dni)){
		lista[i + 1] = lista[i];
		i--;
	}
	lista[i + 1] = aux;
	*tam = *tam + 1;	
	
	insertarUno(lista, indiceCodigo, *tam);
	insertarUnoPatente(lista, indicePatente, *tam);
}

/*
	Retorna la posicion que se encuentra en el indice, usando busqueda binaria.
	Retorna -1 si no lo encuentra
*/
int buscarCodigo(tLista lista, tIndice indice, int tam, int buscado){
	int ini,fin,med;
	
	ini = 1;
	fin = tam;
	med = (ini+fin)/2;
	while(ini <= fin && lista[indice[med]].codigo != buscado){
		if (lista[indice[med]].codigo > buscado){
			fin=med-1;
		}			
		else{
			ini=med+1;
		}			
		med=(ini+fin)/2;
	}
	if (ini<=fin)
		return indice[med];
	else
		return -1;
}

/*
	Elimina un elemento de la lista.
*/
void eliminarUno(tLista lista, int *tam, int posicion){
	int i;
	
	for(i = posicion; i <= *tam - 1; i++){
		lista[i] = lista[i + 1];
	}
	*tam = *tam - 1;
}

/*
	Permite la modificacion de un registro, manteniendo el codigo.
*/
void modificarRegistro(tVehiculo *reg){
	
	printf("\n Ingrese patente:");
	leeCad(reg->patente, tam_max);
	printf("\n Ingrese modelo del vehiculo:");
	leeCad(reg->modelo, tam_max);
	printf("\n Ingrese falla del vehiculo:");
	leeCad(reg->falla, tam_max);
	printf("\n Ingrese dni del cliente:");
	scanf("%d", &reg->dni);
	printf("\n Ingrese apellido del cliente:");
	leeCad(reg->apellido, tam_max);
	printf("\n Ingrese nombre del cliente:");
	leeCad(reg->nombre, tam_max);
	printf("\n Ingrese telefono del cliente:");
	leeCad(reg->telefono, tam_max);
	printf("\n Ingrese estado del vehiculo:");
	leeCad(reg->estado, tam_max);
}

void mostrarUno(tVehiculo reg){
	
	printf("\nCodigo: %d", reg.codigo);
	printf("\nPatente: %s", reg.patente);
	printf("\nModelo del vehiculo: %s", reg.modelo);
	printf("\nFalla del vehiculo: %s", reg.falla);	
	printf("\nDNI del cliente: %d", reg.dni);	
	printf("\nApellido del cliente: %s", reg.apellido);
	printf("\nNombre del cliente: %s", reg.nombre);
	printf("\nTelefono del cliente: %s", reg.telefono);
	printf("\nEstado del vehiculo: %s", reg.estado);
}

/*
	Muestra la lista segun un indice.
*/
void mostrarListaPatente(tLista lista, tIndice indice, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		mostrarUno(lista[indice[i]]);
		printf("\n");
	}
}

void mostrar(tLista lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		mostrarUno(lista[i]);
		printf("\n");
	}
}

