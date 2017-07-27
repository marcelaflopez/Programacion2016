#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=20;

typedef char Tcadena[20];

typedef struct{
	long int fecha;
	Tcadena cantante;
	Tcadena nombre;
	Tcadena cancion;
	float duracion;
	Tcadena ritmo;
}tCelular;

typedef tCelular tLista[100];

int menu();
int leeCad(Tcadena, int);
tCelular cargarUno();
int compararRegistros(tCelular reg1, tCelular reg2);
void baraja(tLista lista, int *tam, tCelular reg);
void ordenar(tLista lista, int tam);
void mostrarUno(tCelular reg);
void cargarLista(tLista lista,int *tam);
void mostrarLista(tLista lista,int tam);
void aleatorio(tLista lista, int tam, int n);
int aleatorioRango(int A, int B);
int buscarCancion(tLista lista, int tam, Tcadena buscado);


int main(){
	
	tLista lista;
	int tam, posicion, opcion, n;
	tCelular aux;
	Tcadena buscado;
	
	srand(time(NULL));	
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				if(tam == 0){
					cargarLista(lista, &tam);
					ordenar(lista, tam);
				}else{
					printf("Las canciones ya fueron cargados.\n");
				}
				break;
			case 2:
				if(tam > 0){
					printf("Ingrese N:\n");
					scanf("%d", &n);
					aleatorio(lista, tam, n);
				}else{
					printf("Las canciones no fueron cargadas.\n");
				}
				break;
			case 3:
				if(tam > 0){
					aux = cargarUno();
					baraja(lista, &tam, aux);
					mostrarLista(lista, tam);
				}else{
					printf("Las personas no fueron cargadas.\n");
				}				
				break;		
			case 4:
				if(tam > 0){
					fflush(stdin);
					printf("\n Ingrese nombre de la cancion a buscar:");
					leeCad(buscado,tam_max);
					posicion = buscarCancion(lista, tam, buscado);
					if(posicion != -1){
						mostrarUno(lista[posicion]);
						lista[posicion] = cargarUno();
						ordenar(lista, tam);
						mostrarLista(lista, tam);
					}else{
						printf("\n La persona no existe.");
					}
				}else{
					printf("Las personas no fueron cargadas.\n");
				}
				break;
			case 5:
				mostrarLista(lista, tam);
			break;
		}
	}while(opcion != 0);	
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Cargar Canciones.\n");
		printf("2 - Simular reproduccion aleatoria.\n");
		printf("3 - Agregar una cancion.\n");		
		printf("4 - Modificar una cancion.\n");
		printf("5 - Mostrar canciones.\n");
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
	Retorna una cancion cargada.
*/
tCelular cargarUno(){
	tCelular nuevo;
	
	fflush(stdin);
	printf("\n Ingrese cantante:");
	leeCad(nuevo.cantante,tam_max);
	fflush(stdin);
	printf("\n Ingrese nombre del disco:");
	leeCad(nuevo.nombre,tam_max);
	fflush(stdin);
	printf("\n Ingrese nombre de la cancion:");
	leeCad(nuevo.cancion,tam_max);
	fflush(stdin);
	printf("\n Ingrese duracion de la cancion:");
	scanf("%f", &nuevo.duracion);
	fflush(stdin);
	printf("\n Ingrese ritmo:");
	leeCad(nuevo.ritmo,tam_max);
		
	return nuevo;
}

/*
	Compara dos registros por ritmo, y a igual ritmo
	por duracion. 
	Retorna 1 si el reg1 es menor que reg2.
	Retorna -1 en caso contrario.
*/
int compararRegistros(tCelular reg1, tCelular reg2){
	int comp, resultado;
	
	comp = strcmp(reg1.ritmo, reg2.ritmo); 
	if(comp == 0){
		if(reg1.duracion < reg2.duracion){
			resultado = 1;
		}
	}else if(comp < 0){
		resultado = 1;
	}else{
		resultado = -1;
	}
	
	return resultado;
}

/*
	Inserta un registro de manera ordenada.
*/
void baraja(tLista lista, int *tam, tCelular reg){
	int i;	
	
	i = *tam;
	while(compararRegistros(reg, lista[i]) == 1 && i > 0){
		lista[i + 1] = lista[i];
		i--;
	}
	lista[i + 1] = reg;
	*tam = *tam + 1;	
}

/*
	Ordena la lista completa.
*/
void ordenar(tLista lista, int tam){
	int i, j;
	tCelular aux;
	
	for(i = 1; i <= tam - 1; i++){
		for(j = i + 1; j <= tam; j++){
			if(compararRegistros(lista[j], lista[i]) == 1){
				aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;
			}
		}
	}
}
/*
	Carga la lista de personas.
*/
void cargarLista(tLista lista,int *tam){
	int i;
	
	printf("\n Ingrese cantidad de canciones:");
	scanf("%d",tam);
	for(i=1;i<=*tam;i++){
		printf("Ingrese la %d %c cancion:\n", i, 167);
		lista[i] = cargarUno();
	}
}

/*
	Muestra una sola persona.
*/
void mostrarUno(tCelular reg){
	
	printf("\n Cantante: %s", reg.cantante);
	printf("\n Nombre del disco: %s", reg.nombre);
	printf("\n Nombre de la cancion: %s", reg.cancion);
	printf("\n Duracion %f", reg.duracion);
	printf("\n Ritmo: %s", reg.ritmo);
		
	printf("\n---------------- \n");
}

/*
	Muestra la lista de personas.
*/
void mostrarLista(tLista lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		mostrarUno(lista[i]);
	}
}

/*
	Reproduce aleatoriamente n canciones.
*/
void aleatorio(tLista lista, int tam, int n){
	int numero, i;
	
	for(i = 1; i <= n; i++){
		numero = aleatorioRango(1, tam);
		mostrarUno(lista[numero]);
	}
}

/*
	Retorna un numero aleatorio entre el rango [A, B]
*/
int aleatorioRango(int A, int B){
	
	return (rand() * (B - A) / RAND_MAX) + 1;
}

/*
	Busca una cancion en la lista, por nombre de cancion.
*/
int buscarCancion(tLista lista, int tam, Tcadena buscado){
	int i;
	
	i = 1;
	while(i <= tam && strcmp(lista[i].cancion, buscado) != 0){
		i++;
	}
	if(i <= tam){
		return i;
	}else{
		return -1;
	}
}








