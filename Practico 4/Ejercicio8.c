#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=50;

typedef char Tcadena[50]; 

int menu();
int leeCad(Tcadena, int);
int encontrar(Tcadena cadena, Tcadena subcadena);
int encontrar2(Tcadena cadena, Tcadena subcadena);
void eliminarC(Tcadena cadena,int posi);
void eliminarPal(Tcadena cadena, Tcadena palabra, int posi);
void insertar(Tcadena cadena,char c,int posi);
void insertarPal(Tcadena cadena, Tcadena palabra,int posi);


int main(){	
	Tcadena cadena,sub;
	int posi, opcion, band;	
	
	band = 0;
	do{
		opcion = menu();
		switch(opcion){
		case 1:			
			printf("\n Ingrese texto:");
			fflush(stdin);
			leeCad(cadena, tam_max);
			band = 1;
			break;
		case 2:
			if(band != 0){
				printf("\n Ingrese subtexto a buscar:");
				fflush(stdin);
				leeCad(sub, tam_max);
				posi = encontrar(cadena, sub);
				if(posi != -1){
					printf("Usando el metodo hecho a mano;\n");
					printf("\n La posicion de la subcadena es: %d", posi);
				}else{
					printf("No se encontro el subtexto.\n");
				}
				posi = encontrar2(cadena, sub);
				if(posi != -1){
					printf("\nUsando los metodos provistos;\n");
					printf("\n La posicion de la subcadena es: %d", posi);
				}else{
					printf("No se encontro el subtexto.\n");
				}
			}else{
				printf("El texto no fue ingresado.\n");
			}			
			break;
		case 3:
			if(band != 0){
				printf("\n Ingrese subtexto a eliminar:");
				fflush(stdin);
				leeCad(sub, tam_max);
				posi = encontrar(cadena, sub);
				if(posi != -1){
					eliminarPal(cadena,sub,posi-1);
					printf("\n Palabra eliminada:%s",cadena);
				}else{
					printf("\nNo se encontro el subtexto");
				}
			}else{
				printf("El texto no fue ingresado.\n");
			}		
			break;
		case 4:
			if(band != 0){
				printf("\n Ingrese subtexto a reemplazar:");
				fflush(stdin);
				leeCad(sub, tam_max);
				posi = encontrar(cadena, sub);
				if(posi != -1){
					eliminarPal(cadena,sub,posi-1);
					printf("\n Ingrese palabra a insertar:");
					leeCad(sub,tam_max);				
					insertarPal(cadena, sub, posi-1);				
					printf("\n Palabra insertada:%s", cadena);
				}else{
					printf("\nNo se encontro el subtexto");
				}	
			}else{
				printf("El texto no fue ingresado.\n");
			}
			break;
		case 5:
			if(band != 0){
				printf("\n En mayusculas:%s", strupr(cadena));
			}else{
				printf("El texto no fue ingresado.\n");
			}
			break;
		}
	}while(opcion != 0);
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Escribir texto.\n");
		printf("2 - Determinar posicion donde se encuentra una subfrase.\n");
		printf("3 - Eliminar una palabra del texto.\n");
		printf("4 - Reemplazar una palabra por otra.\n");
		printf("5 - Convertir todo el texto a mayusculas.\n");	
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
	Usando los metodos provistos por la libreria.
*/
int encontrar2(Tcadena cadena, Tcadena subcadena){
	char *ptr, *ptr2;
	char *c;
	
	ptr = &cadena[0];	
	c = strstr(cadena, subcadena);
	if( c != NULL){
		ptr2 = &c[0];
		return ptr2 - ptr + 1; 
	}else{
		return -1;
	}
}

/*
	Elimina un caracter de la cadena.
	Dada una posicion.
*/
void eliminarC(Tcadena cadena,int posi){
	int i;
	
	for(i=posi; i<strlen(cadena); i++){
		cadena[i]=cadena[i+1];
	}
}

/*
	Elimina una subcadena de la cadena.
*/
void eliminarPal(Tcadena cadena, Tcadena subcadena, int posi){	
	int i;
	
	i=strlen(subcadena);	
	while(i>0){
		eliminarC(cadena, posi);
		i = i - 1;
	}
}

/*
	Inserta un caracter en la cadena.
	Dada una posicion.
*/
void insertar(Tcadena cadena,char c,int posi){
	
	int i;
	
	for(i = strlen(cadena) ; i >= posi;i--){
		cadena[i+1]=cadena[i];
	}
	cadena[posi]=c;
}

/*
	Inserta una palabra en la cadena.
*/
void insertarPal(Tcadena cadena, Tcadena palabra,int posi){
	int i;
	
	for(i = strlen(palabra) - 1; i >= 0; i--){
		insertar(cadena, palabra[i], posi);
	} 
}
