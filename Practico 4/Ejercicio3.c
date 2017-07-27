#include <stdio.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef int tmat[100][100];

int menu();
void cargarMatriz(tmat mat, int *n, int *m);
void mostrarMatriz(tmat mat, int n, int m);
void eliminarFila(tmat mat, int *n, int m, int posi);
void insertarFila(tmat mat, int *n, int m);
void insertarCol(tmat mat, int n, int *m);
void ordenarFila(tmat mat, int posi, int m);
void ordenarFilaC(tmat mat, int n, int m ,int posi);


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
					printf("\n Ingrese fila a eliminar:");
					scanf("%d",&posi);
					eliminarFila(mat, &n, m, posi);
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
					printf("\n Ingrese fila a ordenar:");
					scanf("%d", &posi);
					ordenarFila(mat, posi, m);
				}else{
					printf("No hay matriz!\n");
				}
				break;
			case 7:
				if(n > 0){
					printf("\n Ingrese fila a ordenar,manteniendo columnas:");
					scanf("%d",&posi);
					ordenarFilaC(mat, n, m, posi);
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
		printf("3 - Eliminar una fila de la Matriz.\n");
		printf("4 - Insertar una nueva fila.\n");
		printf("5 - Insertar una nueva columna.\n");
		printf("6 - Ordenar una fila.\n");
		printf("7 - Ordenar una fila preservando las columnas.\n");
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
	eliminarFila([1, 2, 3  , 3, 3, 2) -> ([1, 2, 3), 2, 3) 
				  4, 5, 6				   7, 8 ,9]
				  7, 8 ,9]
*/
void eliminarFila(tmat mat, int *n, int m, int posi){
	
	int i,j;
	
	for(i = posi; i <= *n - 1; i++){
		for(j = 1; j <= m; j++){
			mat[i][j] = mat[i+1][j];
		}
	}
	*n = *n -1;
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
		eliminarFila([1, 2, 3  , 2, 3) -> ([1, 2, 3) ) 
					  6, 4, 5				4, 5, 6
					  7, 8 ,9]              7, 8, 9]  
*/
void ordenarFila(tmat mat, int posi, int m){
	int i,j,aux;
	
	for(i = 1; i <= m - 1; i++){
		for(j = i + 1; j <= m; j++){
			if( mat[posi][j] < mat[posi][i]){
				aux = mat[posi][j];
				mat[posi][j] = mat[posi][i];
				mat[posi][i] = aux;
			}
		}
	}
}

/*
	Ordena una fila de la matriz, pero preservando
	las columnas.
	Ejemplo:
		eliminarFila([1, 2, 3  , 2, 3) -> ([2, 3, 1) ) 
					  6, 4, 5				4, 5, 6
					  7, 8 ,9]              8, 9, 7] 
*/
void ordenarFilaC(tmat mat, int n, int m ,int posi){
	int i,j,aux,k;
	
	for(i = 1; i <= m - 1; i++){
		for(j = i + 1; j <= m; j++){
			if( mat[posi][j] < mat[posi][i]){
				for(k = 1; k <= n; k++){					
					aux = mat[k][i];
					mat[k][i] = mat[k][j];
					mat[k][j] = aux;
				}
			}
		}
	}	
}
