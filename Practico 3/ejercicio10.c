#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

int jugadaPC();
void mostrarJugadaPC(int pc);
int jugadaJugador();
int analizarJugada(int jugador, int pc);

int main(int argc, char *argv[]) {
	int jugador, pc, puntajeJugador, puntajePC, continuar,jugada;
	
	srand(time(NULL));
	puntajeJugador = 0;
	puntajePC = 0;
	do{
		printf("Puntaje Jugador:%d\n", puntajeJugador);
		printf("Puntaje PC:%d\n", puntajePC);
		jugador = jugadaJugador();
		pc = jugadaPC();
		mostrarJugadaPC(pc);
		jugada = analizarJugada(jugador, pc); 
		if(jugada == 1){
			printf("Gana Jugador!\n");
			puntajeJugador++;
		}else if(jugada == -1){
			printf("Gana PC!\n");
			puntajePC++;
		}else{
			printf("Empate!\n");
		}
		printf("Puntaje Jugador:%d\n", puntajeJugador);
		printf("Puntaje PC:%d\n", puntajePC);
		printf("Ingrese 1, si desea seguir jugando:\n");
		scanf("%d", &continuar);
	}while(continuar == 1);
	
	
	return 0;
}

/*
	Retorna la jugada de la PC.
	1- Papel
	2- Piedra
	3- Tijera
*/
int jugadaPC(){
	
	return (rand() * 2 / RAND_MAX) + 1; 
}

void mostrarJugadaPC(int pc){
	switch(pc){
		case 1: 
			printf("PC eligio Papel.\n");
			break;
		case 2: 
			printf("PC eligio Piedra.\n");
			break;
		case 3: 
			printf("PC eligio Tijera.\n");
			break;
	}
}

int jugadaJugador(){
	int jugada;
	
	do{
		printf("Seleccionar jugada:\n");
		printf("1 - Papel.\n");
		printf("2 - Piedra.\n");
		printf("3 - Tijera.\n");
		scanf("%d", &jugada);
	}while(jugada <1 || jugada > 3);
	
	return jugada;
}

/*
	Devuelve 1 si gano el jugador.
	Devuelve -1 si gani la pc.
	Devuelve 0 si hay empate.
*/
int analizarJugada(int jugador, int pc){
	int resultado;
	
	if(jugador == pc){
		resultado = 0;
	}else if((jugador == 1 && pc == 2) || (jugador == 2 && pc == 3) || (jugador == 3 && pc == 1)){
		resultado = 1;
	}else{
		resultado = -1;
	}		
		
	return resultado;
}
