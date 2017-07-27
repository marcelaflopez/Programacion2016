#include <stdio.h>
#include <string.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=20;

typedef char Tcadena[20]; 
typedef int tvec[20];

int leeCad(Tcadena, int);
void mostrarCadena(Tcadena cadena);
void frecuencia(Tcadena cadena,Tcadena lista,tvec frec, int *n);
int mayorFrec(tvec frec,int n);
int cantM(Tcadena cadena);
int cantm(Tcadena cadena);
void trimCadena(Tcadena cadena);
void eliminarCaracter(Tcadena cadena, int posi);
int cantPal(Tcadena cadena); 

int main() {
	
	Tcadena cadena,lista;
	tvec frec;
	int posi,tam;
	
	printf("\nIngrese cadena: ");
	leeCad(cadena, tam_max);
	mostrarCadena(cadena);
	printf("\nCantidad de caracteres: %d", strlen(cadena));
	
	frecuencia(cadena, lista, frec, &tam);
	if(tam > 0){
		posi = mayorFrec(frec, tam);
		printf("\nEl caracter que mas se repite es: %c", lista[posi]);
		
	}else{
		printf("\nLa cadena esta vacia!");
	}
	
	trimCadena(cadena);
	printf("\nLa cantidad de mayusculas: %d", cantM(cadena));
	printf("\nLa cantidad de minusculas: %d", cantm(cadena));	
	printf("\nCantidad de palabras: %d", cantPal(cadena));
	
	return 0;
}

int leeCad(Tcadena cadena, int tam){
	int j, ret;
	char c;
	j=0;
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

void mostrarCadena(Tcadena cadena){
	int i;	
	
	printf("\n");
	for(i=0 ; i < strlen(cadena); i++){
		printf("%c",cadena[i]);
	}
}

/*
	Retorna la frecuencia de las letras en dos vectores asociados.
	Ejemplo:
		frecuencia("hola hola", [], [], 0) -> (["h", "o", "l", "a", " "], [2, 2, 2, 2, 1], 5)
*/
void frecuencia(Tcadena cadena,Tcadena lista, tvec frec,int *n){
	int i, j;
	
	*n = 0;
	for(i = 0; i < strlen(cadena); i++){
		j = 1;
		while(j <= *n && cadena[i] != lista[j]){
			j++;
		}
		if( j> *n ){
			*n = *n + 1;
			lista[*n] = cadena[i];
			frec[*n] =1;
		}else{
			frec[j] = frec[j] + 1;
		}			
	}
}

/*
	Retorna la posicion del caracter que mas se repite.
	Recibe el vector con las frecuencias de cada caracter.
	Ejemplo:
		mayorFrec([1,4,5,2], 4) -> 3
*/
int mayorFrec(tvec frec,int n){
	int i, mayor, posi;
	
	mayor = frec[1];
	posi = 1;
	for(i = 1; i <= n; i++){
		if(frec[i] > mayor){
			mayor = frec[i];
			posi = i;
		}
	}
	return posi;
}

/*
	Retorna la cantidad de mayusculas.
	Ejemplo:
		cantM("Hola Mundo") -> 2
*/
int cantM(Tcadena cadena){
	int i,cont;
	
	cont = 0;
	for(i = 0; i < strlen(cadena); i++){
		if(cadena[i] >= 'A' && cadena[i] <= 'Z'){
			cont = cont + 1;
		}
	}
	return cont;
}

/*
	Retorna la cantidad de minusculas.
	Ejemplo:
		cantm("Hola Mundo") -> 7
*/
int cantm(Tcadena cadena){
	int i,cont;
	
	cont = 0;
	for(i = 0; i < strlen(cadena); i++){
		if(cadena[i] >= 'a' && cadena[i] <= 'z'){
			cont = cont + 1;
		}
	}
	return cont;
}

/*
	Borra los espaciones en blanco de adelante y de atras de la cadena.
	No funcioan si solo se ingresan espacios.
	Ejemplos:
		trimCadena("  hola mundo  ") -> ("hola mundo")
		trimCadena("hola  "]) -> ("hola")
*/
void trimCadena(Tcadena cadena){
	int i;
	
	i = 0;
	while(cadena[i] == ' ' && i < strlen(cadena)){
		eliminarCaracter(cadena, i);		
	}
	i = strlen(cadena) - 1;
	while(cadena[i] == ' ' && i >= 0){
		eliminarCaracter(cadena, i);		
		i--;
	}
}

/*
	Elimina un caracter de la lista.
	No reduce el tamaño.
	Ejemplos:
		eliminarCaracter("hola", 1) -> ("ola")
		eliminarCaracter("hola", 2) -> ("hla")
*/
void eliminarCaracter(Tcadena cadena, int posi){
	int i;
	
	for(i = posi; i <= strlen(cadena) - 1; i++){
		cadena[i] = cadena[i + 1];
	}
}

/*
	Devuelve la cantidad de palabras, si se ingresaron solo espacios en blanco devuelve 0.
	Espera una cadena sin espacion en blanco adelante o al final.
	Ejemplos:
		cantidadPal("hola mundo") -> 2
		cantidadPal("hola") -> 1
		cantidadPal("") -> 0
*/

int cantPal(Tcadena cadena){
	int i, cantidad;
	
	if(strlen(cadena) > 0){
		cantidad = 1;
		for(i = 0; i < strlen(cadena); i++){
			if(cadena[i] == ' '){
				cantidad++;
			}
		}
	}else{
		cantidad = 0;
	}
	
	return cantidad;
}
