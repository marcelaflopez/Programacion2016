#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=50;

typedef char Tcadena[100];
typedef int listaInt[100];

int leeCad(Tcadena cadena, int tam);
void iniciarEncontradas(listaInt lista, int tam);
int buscarLetra(Tcadena palabra, listaInt encontradas, int tam, char c);
void marcarLetra(Tcadena palabra, listaInt encontradas, int tam, char c);
void mostrarPalabra(Tcadena palabra, listaInt encontradas, int tam);
int analizarEncontradas(listaInt encontradas, int tam);
void mostrarGanador(int acu);
void jugar(Tcadena palabra, listaInt encontradas, int tam);

int main(int argc, char *argv[]) {
	Tcadena palabra;
	listaInt encontradas;
	int tam;
	
	printf("\nIngrese la palabra a adivinar:");
	leeCad(palabra, tam_max);
	tam = strlen(palabra);
	iniciarEncontradas(encontradas, tam);
	jugar(palabra, encontradas, tam);
	
	return 0;
}

int leeCad(Tcadena cadena, int tam){
	int j, ret;
	char c;
	j=0;
	fflush(stdin);
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
	Inicia un vector del mismo tamaño de la palabra
	lleno con 0, para indicar que letra fue adivinada o no.
*/
void iniciarEncontradas(listaInt lista, int tam){
	int i;
	
	for(i = 0; i < tam; i++){
		lista[i] = 0;
	}
}

/*
	Busca una letra en la palabra, devuelve 1 si la encuentra.
	-1 en caso contrario.
*/
int buscarLetra(Tcadena palabra, listaInt encontradas, int tam, char c){
	int i;
	
	i = 0;
	while(i < tam && palabra[i] != c){
		i++;
	}
	if(i < tam){
		return 1;
	}else{
		return -1;
	}
}

/*
	Busca la letra en la palabra, si la encuentra, marca que fue encontrada en el
	vector de encontradas.
*/
void marcarLetra(Tcadena palabra, listaInt encontradas, int tam, char c){
	int i;
	
	for(i = 0; i < tam; i++){
		if(palabra[i] == c){
			encontradas[i] = 1;
		}
	}
}

/*
	Muestra la palabra con las letras adivinas hasta el momento.
*/
void mostrarPalabra(Tcadena palabra, listaInt encontradas, int tam){
	int i;
	
	printf("\n");
	for(i = 0; i < tam; i++){
		if(encontradas[i] == 1){
			printf("%c", palabra[i]);
		}else{
			printf("%c", '_');
		}
		printf(" ");
	}
}


/*
	Devuelve 1 si todas las letras fueron adivinadas, -1 en caso contrario.
*/
int analizarEncontradas(listaInt encontradas, int tam){
	int i, band;
	
	i = 0;
	band = 1;
	while(i < tam && band == 1){
		if(encontradas[i] == 0){
			band = 0;
		}else{
			i++;
		}
	}
	
	return band;
}

/*
	Muestra quien fue el ganador de la partida.
*/
void mostrarGanador(int acu){
	
	if(acu == 5){
		printf("\nPerdio el jugador que tenia que adivinar.");
	}else{
		printf("\nGano el jugador que tenia que adivinar.");
	}
}

/*
	Controla el juego.
*/
void jugar(Tcadena palabra, listaInt encontradas, int tam){
	int acu;
	char c;
	
	acu = 0;
	while(acu < 5 && analizarEncontradas(encontradas, tam) != 1){
		printf("\nIngrese letra:");
		fflush(stdin);
		scanf("%c", &c);
		if(buscarLetra(palabra, encontradas, tam, c) == 1){
			marcarLetra(palabra, encontradas, tam, c);			
		}else{
			acu++;
		}
		printf("\nPuntuacion: %d", acu);
		mostrarPalabra(palabra, encontradas, tam);
	}
	mostrarGanador(acu);
}
