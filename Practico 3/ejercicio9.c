#include <stdio.h>
#include <math.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

typedef float listaInt[50];

void cargarLista(listaInt lista, int *tam);
void notacionCientifica(float *numero, int *exponente);
void mantizaNormalizada(float *numero, int *exponente);
void formarParteEntera(float *numero, int *exponente);
int menorLista(listaInt lista, int tam);
int mayorLista(listaInt lista, int tam);

int main(int argc, char *argv[]) {
	int menor, mayor, tam;
	listaInt lista;
	
	cargarLista(lista, &tam);	
	menor = menorLista(lista, tam);
	mayor = mayorLista(lista, tam);
	printf("El menor de la lista es :%f\n", lista[menor]);
	printf("El mayor de la lista es :%f\n", lista[mayor]);
	printf("El promedio de esos dos numero es:%.2f\n",(lista[menor] + lista[mayor]) / 2);
	
	return 0;
}

/*
	Devuelve el numero expresado en notacion cientifica.
	Con mantiza normalizada.
	Ejemplos:
		notacionCientifica(732.5051, 0) -> (0.7325051, 3)
		notacionCientifica(0.005612, 0) -> (0.5612, -2)
*/
void notacionCientifica(float *numero, int *exponente){
	int expAuxiliar;
	
	expAuxiliar = 0;
	if(*numero >= 1){
		mantizaNormalizada(numero, &expAuxiliar);	
	}else{
		formarParteEntera(numero, &expAuxiliar);
		mantizaNormalizada(numero, &expAuxiliar);
	}
	*exponente = expAuxiliar;	
}

/*
	Encuentra la mantiza normalizada de un numero, siempre que el numero
	sea mayor o igual a 1.
	Ejemplos:
		mantizaNormalizada(732.5051, 0) -> (0.7325051, 3)
*/
void mantizaNormalizada(float *numero, int *exponente){
	while(*numero >= 1){
		*numero = *numero / 10;
		*exponente = *exponente + 1;	
	}	
}

/*
	Transforma un numero compuesto solo de parte fraccionara, a tener parte entera.
	Ejemplos.
		formarParteEntera(0.213, 0) -> (2.13, -1)
		formarParteEntera((0.005612, 0) -> (5.612, -3)
*/
void formarParteEntera(float *numero, int *exponente){
	while(*numero < 1){
		*numero = *numero * 10;
		*exponente = *exponente - 1;
	}
}

void cargarLista(listaInt lista, int *tam){
	int i;
	
	printf("Ingrese el tama%co de la lista:\n", 164); /*Estoy agrendo el caracter ñ*/
	scanf("%d", tam);
	for(i = 1; i <= *tam; i++){
		printf("Ingrese %d %c numero:", i, 167); /*Estoy agregando el caracter º*/
		scanf("%f", &lista[i]);
	}
}

/*
	Devuelve la posicion del menor de la lista,
	analizando el exponente y en caso de igualda,
	la mantiza.
	Ejemplos:
		menorLista([732.5051, 0.005612]) -> 2;		
*/
int menorLista(listaInt lista, int tam){
	int menor, i, exponente, exponenteAuxiliar;
	float auxiliar, menorAuxiliar;
	
	menor = 1;
	menorAuxiliar = lista[1];
	notacionCientifica(&menorAuxiliar, &exponenteAuxiliar);
	for(i = 2; i <= tam; i++){
		auxiliar = lista[i];
		notacionCientifica(&auxiliar, &exponente);
		if(exponente >= exponenteAuxiliar){
			if(exponente == exponenteAuxiliar){
				if(auxiliar < menorAuxiliar){
					menor = i;
					menorAuxiliar = lista[i];
					notacionCientifica(&menorAuxiliar, &exponenteAuxiliar);
				}
			}
		}else{
			menor = i;
			menorAuxiliar = lista[i];
			notacionCientifica(&menorAuxiliar, &exponenteAuxiliar);
		}
	}
	
	return menor;
}

/*
	Devuelve la posicion del menor de la lista,
	analizando el exponente y en caso de igualda,
	la mantiza.
	Ejemplos:
		menorLista([732.5051, 0.005612]) -> 1;		
*/
int mayorLista(listaInt lista, int tam){
	int mayor, i, exponente, exponenteAuxiliar;
	float auxiliar, mayorAuxiliar;
	
	mayor = 1;
	mayorAuxiliar = lista[1];
	notacionCientifica(&mayorAuxiliar, &exponenteAuxiliar);
		for(i = 2; i <= tam; i++){
			auxiliar = lista[i];
			notacionCientifica(&auxiliar, &exponente);
			if(exponente <= exponenteAuxiliar){
				if(exponente == exponenteAuxiliar){
					if(auxiliar > mayorAuxiliar){
						mayor = i;
						mayorAuxiliar = lista[i];
						notacionCientifica(&mayorAuxiliar, &exponenteAuxiliar);
					}
				}
			}else{
				mayor = i;
				mayorAuxiliar = lista[i];
				notacionCientifica(&mayorAuxiliar, &exponenteAuxiliar);
			}
		}
	
	return mayor;
}

