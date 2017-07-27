#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=50;

typedef char Tcadena[100]; 

void cargarNumero(Tcadena numero);
int validarNumero(Tcadena numero);
void completarNumero(Tcadena numero1, Tcadena numero2);
void sumarNumeros(Tcadena numero1, Tcadena numero2, Tcadena resultado);
void sumaAcarreo(char a, char b, int *acarreo, char *resultado);
int sumarCaracteres(char a, char b);
void insertar(Tcadena cadena, char c);


int main(){	
	Tcadena numero1, numero2, resultado = "\0";
	
	cargarNumero(numero1);
	cargarNumero(numero2);
	completarNumero(numero1, numero2);	
	sumarNumeros(numero1, numero2, resultado);
	printf("El resultado de la suma es: %s", resultado);
	
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

/*
	Carga un numero valido.
*/
void cargarNumero(Tcadena numero){
	int validacion;
	
	do{
		printf("\n Ingresar numero:");
		fflush(stdin);
		leeCad(numero, tam_max);
		validacion = validarNumero(numero);
		if(validacion != 1){
			printf("La cadena solo tiene que contener numeros!\n");
		}
	}while(validacion != 1);	
}

/*
	Verifica que la cadena solo este compuesto de
	digitos.
	Retorna 1 si es valida.
	Retorna -1 en caso contrario.
*/
int validarNumero(Tcadena numero){
	int i, band;
	
	band = 1;
	i = 0;
	while(i < strlen(numero) && band == 1){
		if(numero[i] < '0' || numero[i] > '9'){
			band = 0;
		}
		i++;
	}
	
	return band;
}

/*
	Rellena con 0 a la izquierda al numero de menor 
	cantidad de digitos, Hasta igualar al otro.
*/
void completarNumero(Tcadena numero1, Tcadena numero2){
	int tam1, tam2, i;
	
	tam1 = strlen(numero1);
	tam2 = strlen(numero2);
	if(tam1 > tam2){
		for(i = 1; i <= tam1 - tam2; i++){
			insertar(numero2, '0');
		}
	}else{
		for(i = 1; i <= tam2 - tam1; i++){
			insertar(numero1, '0');
		}
	}
}

/*
	Suma los numeros representados en las cadenas.
	Y retorna el resultado en otra cadena.
*/
void sumarNumeros(Tcadena numero1, Tcadena numero2, Tcadena resultado){
	int i, acarreo;
	char caracter;
		
	i = 0;	
	acarreo = 0;
	for(i = strlen(numero1) - 1; i >= 0 ; i--){
		sumaAcarreo(numero1[i], numero2[i], &acarreo, &caracter);
		insertar(resultado, caracter);
	}
	if(acarreo == 1){
		insertar(resultado, '1');
	}
}

/*
	Suma dos caracteres, devolviendo el acarreo y el resultado.
*/
void sumaAcarreo(char a, char b, int *acarreo, char *resultado){
	int tmp;
	
	tmp = sumarCaracteres(a, b);
	tmp = tmp + * acarreo;
	*acarreo = tmp / 10;
	tmp = tmp % 10;
	*resultado = tmp + '0';
}


/*
	Suma dos caracteres
*/
int sumarCaracteres(char a, char b){
	int dig1, dig2;
	
	dig1 = a - '0';
	dig2 = b - '0';
	return dig1 + dig2;
}
/*
	Inserta un caracter en una cadena cadena.
*/
void insertar(Tcadena cadena, char c){
	int i;
	
	for(i = strlen(cadena) ; i >= 0;i--){
		cadena[i+1]=cadena[i];
	}
	cadena[0]=c;
}

