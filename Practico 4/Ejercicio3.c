#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int tmat[100][100];

int menu();
void cargarMatriz(tmat mat, int *n, int *m);
void mostrarMatriz(tmat mat, int n, int m);
void eliminarColumna(tmat mat, int n, int *m, int posi);
void insertarFila(tmat mat, int *n, int m);
void insertarCol(tmat mat, int n, int *m);
void ordenarColumna(tmat mat, int posi, int m);
void ordenarColumnaF(tmat mat, int n, int m ,int posi);


int main() {
	tmat mat;
	int n, m, posi, opcion;
	
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				cargarMatriz(mat, &n, &m);
				break;
			case 2:
				if(n > 0){
					printf("Matriz:\n ");
					mostrarMatriz(mat, n, m);
				}else{
					printf("No hay matriz!\n");
				}				
				break;
			case 3:
				if(n > 0){
					printf("\n Ingrese columna a eliminar:");
					scanf("%d",&posi);
					eliminarColumna(mat, n, &m, posi);
				}else{
					printf("No hay matriz!\n");
				}
				break;
			case 4:
				insertarFila(mat, &n, m);				
				break;
			case 5:
				insertarCol(mat, n, &m);;
				break;
			case 6:
				if(n > 0){
					printf("\n Ingrese columna a ordenar:");
					scanf("%d", &posi);
					ordenarColumna(mat, posi, m);
				}else{
					printf("No hay matriz!\n");
				}
				break;
			case 7:
				if(n > 0){
					printf("\n Ingrese columna a ordenar,manteniendo filas:");
					scanf("%d",&posi);
					ordenarColumnaF(mat, n, m, posi);
				}else{
					printf("No hay matriz!\n");
				}
				break;
		}
	}while(opcion != 0);	
		
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("1 - Cargar Matriz.\n");
		printf("2 - Mostrar Matriz.\n");
		printf("3 - Eliminar una columna de la Matriz.\n");
		printf("4 - Insertar una nueva fila.\n");
		printf("5 - Insertar una nueva columna.\n");
		printf("6 - Ordenar una columna.\n");
		printf("7 - Ordenar una columna preservando las filas.\n");
		printf("0 - Salir.\n");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 && op > 7);
	
	return op;
}

void cargarMatriz(tmat mat, int *n, int *m){
	
	int i,j;
	
	printf("\n Ingrese cantidad de filas:");
	scanf("%d", n);
	printf("\n Ingrese cantidad de columnas:");
	scanf("%d", m);
	
	for(i = 1; i <= *n; i++){
		for(j = 1; j <= *m; j++){
			printf("\n Ingrese valor:");
			scanf("%d", &mat[i][j]);
		}
	}
}

void mostrarMatriz(tmat mat, int n, int m){
	int i,j;
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			printf("\t %d", mat[i][j]);
		}
		printf("\n");
	}
}

/*
	Elimina una fila de la matriz.
	Ejemplo:
	eliminarColumna([1, 2, 3  , 3, 3, 2) -> ([1, 3), 3, 2) 
				     4, 5, 6				  4, 6
				     7, 8 ,9]				  7, 9]
*/
void eliminarColumna(tmat mat, int n, int *m, int posi){
	
	int i,j;
	
	for(j = posi; j <= *m - 1; j++){
		for(i = 1; i <= n; i++){
			mat[i][j] = mat[i][j + 1];
		}
	}
	*m = *m -1;
}

/*
	Inserta una fila a la matriz, al final.
	Ejemplo:
		insertarFila([1, 2, 3  , 2, 3) -> ([1, 2, 3  , 3, 3)
					  7, 8, 9]              7, 8 ,9
											4, 5, 6]
*/                                         
void insertarFila(tmat mat, int *n, int m){
	int j;
	
	for(j = 1; j <= m; j++){
		printf("\n Ingrese valor:");
		scanf("%d", &mat[*n+1][j]);
	}
	*n = *n + 1;
	
}

/*
	Inserta una columna a la matriz, al final.
	Ejemplo:
		insertarCol([1, 2  , 3, 2) -> ([1, 2, 3  , 3, 3)
					 4, 5               4, 5, 6
					 7, 8]              7, 8, 9]
*/
void insertarCol(tmat mat, int n, int *m){
	
	int i;
	
	for(i = 1; i <= n; i++){
		printf("\n Ingrese valor:");
		scanf("%d", &mat[i][*m+1]);
	}
	*m = *m + 1;
}

/*
	Ordena una fila de la matriz.
	Ejemplo:
		ordenarColumna([1, 4, 3  , 2, 3) -> ([1, 2, 3) ) 
					    6, 8, 5				  6, 4, 5
					    7, 2 ,9]              7, 8, 9]  
*/
void ordenarColumna(tmat mat, int posi, int m){
	int i,j,aux;
	
	for(i = 1; i <= m - 1; i++){
		for(j = i + 1; j <= m; j++){
			if( mat[j][posi] < mat[i][posi]){
				aux = mat[j][posi];
				mat[j][posi] = mat[i][posi];
				mat[i][posi] = aux;
			}
		}
	}
}

/*
	Ordena una columna de la matriz, pero preservando
	las filas.
	Ejemplo:
		ordenarColumnaF([1, 4, 3  , 3, 3, 2) -> ([7, 2, 9) ) 
					     6, 8, 5			      1, 4, 3
					     7, 2 ,9]                 6, 8, 5] 
*/
void ordenarColumnaF(tmat mat, int n, int m ,int posi){
	int i,j,aux,k;
	
	for(i = 1; i <= n - 1; i++){
		for(j = i + 1; j <= n; j++){
			if( mat[j][posi] < mat[i][posi]){
				for(k = 1; k <= m; k++){					
					aux = mat[i][k];
					mat[i][k] = mat[j][k];
					mat[j][k] = aux;
				}
			}
		}
	}	
}
