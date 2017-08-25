#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Autor: Fernando Orquera
Año: 2017
*/

const int tam_max=20;

typedef char Tcadena[20]; 

typedef struct{
	int tarjeta;
	Tcadena nombre;
	float saldo;
}tUsuario;

typedef tUsuario tLista[100];

int menu();
int leeCad(Tcadena, int);
tUsuario cargarUno();
void mostrarUno(tUsuario reg);
void cargarLista(tLista lista,int *tam);
void mostrarLista(tLista lista,int tam);
int buscarUsuario(tLista lista, int tam, int cod);
void cargar(tUsuario *reg,float valor);
int verificarCobro(tUsuario reg, float valor);
void cobrar(tUsuario *reg, float valor);


int main(){
	
	tLista lista;
	int tam, posicion, codigo, opcion;
	float valor;
	
	tam = 0;
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				if(tam == 0){
					cargarLista(lista, &tam);
				}else{
					printf("Los usuarios ya fueron cargados.\n");
				}
				break;
			case 2:
				if(tam > 0){
					mostrarLista(lista, tam);
				}else{
					printf("Los usuarios no fueron cargados.\n");
				}
				break;
			case 3:
				printf("\n Ingrese numero de usuario a buscar:");
				scanf("%d",&codigo);
				posicion = buscarUsuario(lista, tam, codigo);
				if(posicion != -1){
					printf("\n Ingrese valor a cargar:");
					scanf("%f", &valor);
					cargar(&lista[posicion], valor);
					mostrarUno(lista[posicion]);
				}else{
					printf("\n El usuario no existe.");
				}
				break;
			case 4:
				printf("\n Ingrese numero de usuario a buscar:");
				scanf("%d",&codigo);
				posicion = buscarUsuario(lista, tam, codigo);
				if(posicion != -1){
					printf("\n Ingrese valor a cobrar:");
					scanf("%f", &valor);
					if(verificarCobro(lista[posicion], valor) == 1){
						cobrar(&lista[posicion], valor);
						mostrarUno(lista[posicion]);
					}else{
						printf("Saldo insuficiente.\n");
					}
					
				}else{
					printf("\n El usuario no existe.");
				}
				break;
		}
	}while(opcion != 0);	
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("1 - Cargar Usuarios.\n");
		printf("2 - Mostrar Usuarios.\n");
		printf("3 - Realizar una carga.\n");
		printf("4 - Realizar un cobro.\n");		
		printf("0 - Salir.\n");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 && op > 4);
	
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
	Retorna un usuario cargado, con el saldo en 0.
	La posicion es asignada automaticamente.
*/
tUsuario cargarUno(int posi){
	tUsuario nuevo;
	
	nuevo.tarjeta = posi;
	fflush(stdin);
	printf("\n Ingrese nombre del usuario:");
	leeCad(nuevo.nombre,tam_max);
	nuevo.saldo = 0;
	
	return nuevo;
}

/*
	Carga la lista de usuarios.
*/
void cargarLista(tLista lista,int *tam){
	int i;
	
	printf("\n Ingrese cantidad de usuarios:");
	scanf("%d",tam);
	for(i=1;i<=*tam;i++){
		printf("Ingrese el %d %c usuario:\n", i, 167);
		lista[i] = cargarUno(i);
	}
}

/*
	Muestra un solo usuario
*/
void mostrarUno(tUsuario reg){
	
	printf("\n Numero de tarjeta del usuario: %d",reg.tarjeta);
	printf("\n Nombre del usuario: %s",reg.nombre);
	printf("\n Saldo del usuario: %.2f",reg.saldo);
	printf("\n---------------- \n");
}

/*
	Muestra la lista de usuarios.
*/
void mostrarLista(tLista lista,int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		mostrarUno(lista[i]);
	}
}


/*
	Busqueda binaria.
*/
int buscarUsuario(tLista lista, int tam, int cod){
	int ini,fin,m;
	
	ini=1;
	fin=tam;
	m=(ini+fin)/2;
	while( ini<=fin && lista[m].tarjeta != cod){
		if(lista[m].tarjeta > cod){
			fin = m - 1;
		}else{
			ini = m +1 ;
		}
		m = (ini+fin)/2;	
	}
	if(ini<=fin){
		return m;
	}else
		return -1;
}

/*
	Modifica el saldo de un usuario.
*/
void cargar(tUsuario *reg,float valor){
	
	reg->saldo = reg->saldo + valor;
}

/*
	Retorna 1,si se puede realzar el retiro.
	Retorna -1, en caso contrario
*/
int verificarCobro(tUsuario reg, float valor){
	if(reg.saldo >= valor){
		return 1;
	}else{
		return -1;
	}
}

/*
	Modifica el saldo de un cliente.
*/
void cobrar(tUsuario *reg, float valor){
	
	reg->saldo = reg->saldo - valor;
}
