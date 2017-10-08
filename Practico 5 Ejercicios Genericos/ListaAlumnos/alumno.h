#ifndef ALUMNO_H
#define ALUMNO_H

typedef char tCadena[30];

typedef struct{
	int dni;
	tCadena apellido;
	tCadena nombre;
	int lu;
	tCadena carrera;	
}tAlumno;

tAlumno cargarUno();
void mostrarUno(tAlumno reg);
int retornarDNI(tAlumno reg);
void retornarCarrera(tAlumno reg, tCadena rcarrera);
void modificarCarreraLU(tAlumno *reg);
int compararApellidos(tAlumno reg1, tAlumno reg2);

#endif
