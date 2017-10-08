#include "lectura_cadena.h"
#include "alumno.h"
#include <stdio.h>

tAlumno cargarUno(){
	tAlumno nuevo;
	
	printf("\n Ingrese DNI:");
	scanf("%d", &nuevo.dni);	
	printf("\n Ingrese Apellido:");
	leeCad(nuevo.apellido, 30);	
	printf("\n Ingrese Nombre:");
	leeCad(nuevo.nombre, 30);
	printf("\n Ingrese LU:");
	scanf("%d", &nuevo.lu);	
	printf("\n Ingrese Carrera:");
	leeCad(nuevo.carrera, 30);
	
	return nuevo;
}

void mostrarUno(tAlumno reg){
	printf("\n DNI:%d", reg.dni);
	printf("\n Apellido:%s", reg.apellido);
	printf("\n Nombre:%s", reg.nombre);
	printf("\n LU:%d", reg.lu);
	printf("\n Carrera:%s", reg.carrera);	
}

int retornarDNI(tAlumno reg){
	
	return reg.dni;
}

void retornarCarrera(tAlumno reg, tCadena rcarrera){
	
	strcpy(rcarrera, reg.carrera);
}


void modificarCarreraLU(tAlumno *reg){
	
	printf("\n Ingrese LU:");
	scanf("%d", &reg->lu);	
	printf("\nIngrese nueva carrera: ");
	leeCad(reg->carrera, 30);
	
}

int compararApellidos(tAlumno reg1, tAlumno reg2){
	
	return strcmp(reg1.apellido, reg2.apellido);
}
