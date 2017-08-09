#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

/*Modulos para generar la hora al azar*/
int generarHora();
int generarMinutos();
int generarSegundos();
int generarRand(int A, int B);

/*Modulos para calcular cantidad de segundos dada una hora*/
unsigned long calcularSegundos(int hora, int minutos, int segundos);

/*Modulos para ingresar una fecha*/
int ingresarHora();
int ingresarSegundos();
int ingresarMinutos();
int ingresar(int A, int B);


int main() {
	int horaAzar, minutosAzar, segundosAzar, hora, minutos, segundos, tam, i;	
	double cantidadSegundos;
	
	srand(time(NULL));
	
	cantidadSegundos = 0;
	horaAzar = generarHora();
	minutosAzar = generarMinutos();
	segundosAzar = generarSegundos();
	printf("Hora generada al azar %d-%d-%d .\n", horaAzar, minutosAzar, segundosAzar);
	printf("Ingrese cantidad de horas:\n");
	scanf("%d", &tam);
	for(i = 1; i <= tam; i++){
		hora = ingresarHora();
		minutos = ingresarMinutos();
		segundos = ingresarSegundos();
		cantidadSegundos = cantidadSegundos + abs(calcularSegundos(hora, minutos, segundos) - calcularSegundos(horaAzar, minutosAzar, segundosAzar));		
	}
	printf("\nEl promedio es: %2.f segundos", cantidadSegundos / tam);
		
	return 0;
}

/*
	Genera una hora entre el rango [0, 23]
*/
int generarHora(){
	return generarRand(0, 23);
}
/*
	Genera minutos en el rango [0, 59].
*/
int generarMinutos(){	
	return generarRand(0, 59);
}

/*
	Genera segundos en el rango [0, 59].
*/
int generarSegundos(){
	return generarRand(0, 59);
}

/*
	Genera un numero aleatorio entre el rango [A, B]
*/
int generarRand(int A, int B){
	return (rand() * (B - A) / RAND_MAX) + A;
}


/*
	Calcula la cantidad de segundos dada una hora.
	Ejemplos:
		calcularDias(23, 12, 59) -> 83579
		calcularDias(7, 55, 15) -> 28515
*/
unsigned long calcularSegundos(int hora, int minutos, int segundos){
	unsigned long seg;
	
	seg = 0;
	/*Calculo la cantidad de segundos en la hora */
	seg = seg + (hora * 60 * 60);
	/*Calculo la cantidad de segundos en los minutos */
	seg = seg + (minutos * 60);
	/*Sumo los segundos*/
	seg = seg + segundos;
	
	return seg;
}


/*
	Permite ingresar una hora entre el rango [0, 23]
*/
int ingresarHora(){
	int hora;
	
	printf("Hora - ");
	hora = ingresar(0, 23);
	
	return hora;
}

/*
	Permite ingresar minutos entre el rango [0, 59]
*/
int ingresarMinutos(){
	int minutos;
	
	printf("Minutos - ");
	minutos = ingresar(0, 59);
	
	return minutos;
}

/*
	Permite ingresar segundos entre el rango [0, 59].
*/
int ingresarSegundos(){
	int segundos;
	
	printf("Segundos - ");
	segundos = ingresar(0, 59);
	
	return segundos;
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






