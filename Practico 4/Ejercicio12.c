#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=50;

typedef char Tcadena[50];
typedef char tMatriz[50][50]; 

int menu();
int leeCad(Tcadena, int);
void cargarMatriz(tMatriz matriz, int *n, int *m);
void mostrarMatriz(tMatriz matriz, int n, int m);
int encontrar(Tcadena cadena, Tcadena subcadena);
int buscarMatrizFila(tMatriz matriz, int n, int m,  Tcadena cadena);
int buscarMatrizColumna(tMatriz matriz, int n, int m,  Tcadena cadena);
void invertirCadena(Tcadena cadena);

int main(){	
	Tcadena cadena;
	int opcion, band, n, m, cant;
	tMatriz matriz;
	
	band = 0;
	do{
		opcion = menu();
		switch(opcion){
		case 1:			
			cargarMatriz(matriz, &n, &m);
			band = 1;
			break;
		case 2:
			if(band != 0){
				cant = 0;
				printf("\n Ingrese la palabra a buscar:");
				fflush(stdin);
				leeCad(cadena, tam_max);
				cant = cant + buscarMatrizFila(matriz, n, m, cadena);
				cant = cant + buscarMatrizColumna(matriz, n, m, cadena);
				printf("\nLa palabra esta en la sopa de letras %d veces.", cant);
			}else{
				printf("\nLa sopa de letra no fue ingresada.");
			}			
			break;
		case 3:
			if(band != 0){
				mostrarMatriz(matriz, n, m);
			}else{
				printf("\nLa sopa de letra no fue ingresada.");
			}		
			break;		
		}
	}while(opcion != 0);
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Cargar matriz.\n");
		printf("2 - Buscar palabra.\n");		
		printf("3 - Mostrar matriz.\n");	
		printf("0 - Salir.\n");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 && op > 3);
	
	return op;
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

void cargarMatriz(tMatriz matriz, int *n, int *m){
	int i, j;
	
	printf("Ingrese cantidad de filas:\n");
	scanf("%d", n);
	printf("Ingrese cantidad de columnas:\n");
	scanf("%d", m);
	for(i = 1; i <= *n; i++){
		for(j = 1; j <= *m; j++){
			printf("Ingrese caracter:");
			fflush(stdin);
			scanf("%c", &matriz[i][j]);
		}
	}
}

void mostrarMatriz(tMatriz matriz, int n, int m){
	int i, j;
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			printf("\t%c", matriz[i][j]);
		}
		printf("\n");
	}
}

/*
	Devuelve la posicion en donde empieza la subcadena en la cadena.
	Devuelve -1 si no se encuentra la subcadena.
*/
int encontrar(Tcadena cadena, Tcadena subcadena){	
	int i, j;
	
	j=0;
	i=0;
	while( i < strlen(cadena) && j != (strlen(subcadena)) ){
		if(subcadena[j] == cadena[i]){
			j++;			
		}else{
			j = 0;
		} 
		i++;
	}
	if(j == strlen(subcadena)){
		return (1 + i - j);
	}else{
		return -1;
	} 
}

/*
	Me devuelve la cantidad de veces que se encontro la palabra en
	la matriz recorriendo las filas, tanto de izquierda a derecha, 
	como de derecha a izquierda.
*/
int buscarMatrizFila(tMatriz matriz, int n, int m, Tcadena cadena){
	Tcadena aux;
	int i, j, cant;
	
	cant = 0;	
	for(i = 1; i <= n; i++){
		aux[0] = (char) 0; /*Inicializo la cadena en vacio.*/
		for(j = 1; j <= m; j++){
			strncat(aux, &matriz[i][j], 1);
		}
		if(encontrar(aux, cadena) != -1){
			cant++;
		}
		invertirCadena(aux);
		if(encontrar(aux, cadena) != -1){
			cant++;
		}
	}
	
	return cant;
}

/*
	Me devuelve la cantidad de veces que se encontro la palabra en
	la matriz recorriendo las columnas, tanto de arriba a abajo,
	como de abajo a arriba.
*/
int buscarMatrizColumna(tMatriz matriz, int n, int m,  Tcadena cadena){
	Tcadena aux;
	int i, j, cant;
	
	cant = 0;	
	for(j = 1; j <= m; j++){
		aux[0] = (char) 0; /*Inicializo la cadena en vacio.*/
		for(i = 1; i <= n; i++){
			strncat(aux, &matriz[i][j], 1);
		}
		if(encontrar(aux, cadena) != -1){
			cant++;
		}
		invertirCadena(aux);
		if(encontrar(aux, cadena) != -1){
			cant++;
		}
	}
	
	return cant;
}

/*
	Invierte una cadena.
	"hola" -> "aloh" 
*/
void invertirCadena(Tcadena cadena){
	int i, tam;
	char aux;
	
	tam = strlen(cadena) - 1;
	for(i = 0; i <= tam / 2; i++){
		aux = cadena[i];
		cadena[i] = cadena[tam - i];
		cadena[tam - i] = aux;
	}
}

