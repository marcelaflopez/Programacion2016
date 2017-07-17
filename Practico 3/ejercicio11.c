#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

/*Modulos para generar la fecha al azar*/
void generarFecha(int *anio, int *mes, int *dia);
int generarAnio();
int generarMes();
int generarDia(int mes);
int generarRand(int A, int B);

/*Modulos para calcular cantidad de dias dada una fecha*/
int diasMes(int mes);
unsigned long calcularDias(int dia, int mes, int anio);

/*Modulos para ingresar una fecha*/
void ingresarFecha(int *anio, int *mes, int *dia);
int ingresarAnio();
int ingresarMes();
int ingresarDia(int mes);
int ingresar(int A, int B);


int main() {
	int anioAzar, mesAzar, diaAzar, anio, mes, dia, tam, i;	
	double cantidadDias;
	
	srand(time(NULL));
	
	cantidadDias = 0;
	generarFecha(&anioAzar, &mesAzar, &diaAzar);
	printf("Fecha generada al azar %d/%d/%d .\n", diaAzar, mesAzar, anioAzar);
	printf("Ingrese cantidad de fechas:\n");
	scanf("%d", &tam);
	for(i = 1; i <= tam; i++){
		ingresarFecha(&anio, &mes, &dia);
		cantidadDias = cantidadDias + abs(calcularDias(dia, mes, anio) - calcularDias(diaAzar, mesAzar, anioAzar));		
	}
	printf("El promedio es: %2.f dias", cantidadDias / tam);
		
	return 0;
}

/*
	Genera una fecha valida.
	Formato dd/mm/aaaa.
*/
void generarFecha(int *anio, int *mes, int *dia){
	*anio = generarAnio();
	*mes = generarMes();
	*dia = generarDia(*mes);
}

/*
	Genera un anio entre el rango [1970, 2038]
*/
int generarAnio(){
	return generarRand(1970, 2038);
}
/*
	Genera un mes.
*/
int generarMes(){	
	return generarRand(1, 12);
}

/*
	Genera un dia de acuerdo al mes.
*/
int generarDia(int mes){
	int dia;
	
	switch(mes){
		case 1:case 3:case 5: case 7:
		case 8:case 10:case 12:
			dia = generarRand(1, 31);
			break;
		case 4:case 6:case 9:case 11:	
			dia = generarRand(1, 30);
			break;
		case 2:
			dia = generarRand(1, 28);
			break;
	}
	
	return dia;
}

/*
	Genera un numero aleatorio entre el rango [A, B]
*/
int generarRand(int A, int B){
	return (rand() * (B - A) / RAND_MAX) + A;
}

/*
	Retorna la cantidad de dias que tiene un mes.
	Ejemplos;
		diasMes(12) -> 31
		diasMes(2) -> 28
*/
int diasMes(int mes){
	int dias;
	
	switch(mes){
		case 1:case 3:case 5: case 7:
		case 8:case 10:case 12:
			dias = 31;
			break;
		case 4:case 6:case 9:case 11:	
			dias = 30;
			break;
		case 2:
			dias = 28;
			break;
	}
	
	return dias;
}
/*
	Calcula la cantidad de dias dada una fecha.
	Ejemplos:
		calcularDias(1, 1, 2017) -> 736206
		calcularDias(1, 1, 2000) -> 730001
*/
unsigned long calcularDias(int dia, int mes, int anio){
	unsigned long dias;
	int i;
	
	dias = 0;
	/*Sumo los dias de los anios, sin tener en cuenta el actual */
	dias = dias + (anio - 1) * 365;
	/*Sumo los dias de los meses, sin tener en cuenta el actual*/
	for(i = 1; i < mes; i++){
		dias = dias + diasMes(i);
	}
	/*Sumo los dias*/
	dias = dias + dia;
	
	return dias;
}

/*
	Permite que el usuario ingrese una fecha. 
	Formato dd/mm/aaaa.
*/

void ingresarFecha(int *anio, int *mes, int *dia){
	*anio = ingresarAnio();
	*mes = ingresarMes();
	*dia = ingresarDia(*mes);
}

/*
	Permite ingresar un anio entre el rango [1970, 2038]
*/
int ingresarAnio(){
	int anio;
	
	printf("A%co - ", 164);
	anio = ingresar(1970, 2038);
	
	return anio;
}

/*
	Permite ingresar un mes entre el rango [1, 12]
*/
int ingresarMes(){
	int mes;
	
	printf("Mes - ");
	mes = ingresar(1, 12);
	
	return mes;
}

/*
	Permite ingresar un dia valido de acuerdo al mes.
*/
int ingresarDia(int mes){
	int dia;
	
	printf("Dia - ");
	switch(mes){
	case 1:case 3:case 5: case 7:
	case 8:case 10:case 12:		
		dia = ingresar(1, 31);
		break;
	case 4:case 6:case 9:case 11:	
		dia = ingresar(1, 30);
		break;
	case 2:
		dia = ingresar(1, 28);
		break;
	}
	
	return dia;
}

/*
	Permite ingresar un valor entre el rango [A, B]
*/
int ingresar(int A, int B){
	int respuesta;
	
	do{
		printf("Ingrese:\n");
		scanf("%d",&respuesta);
	}while(respuesta < A || respuesta > B);
	
	return respuesta;
}






