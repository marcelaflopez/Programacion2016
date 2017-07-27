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
	Tcadena calle;
	Tcadena numero;
	Tcadena ciudad;
	Tcadena telefono;
}tDomicilio;

typedef struct{
	int nro;
	Tcadena nombre;
	float saldo;
	tDomicilio domicilio;
}tCliente;

typedef tCliente tLista[100];

int menu();
int leeCad(Tcadena, int);
tCliente cargarUno();
tDomicilio cargarDomicilio();
void mostrarUno(tCliente reg);
void mostrarDomicilio(tDomicilio reg);
void cargarLista(tLista lista,int *tam);
void mostrarLista(tLista lista,int tam);
int buscarCliente(tLista lista, int tam, int cod);
void depositar(tCliente *reg,float valor);
int verificarRetiro(tCliente reg, float valor);
void retirar(tCliente *reg, float valor);
void modificarCliente(tCliente *reg);


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
					printf("Los clientes ya fueron cargados.\n");
				}
				break;
			case 2:
				if(tam > 0){
					mostrarLista(lista, tam);
				}else{
					printf("Los clientes no fueron cargados.\n");
				}
				break;
			case 3:
				printf("\n Ingrese numero de cliente a buscar:");
				scanf("%d",&codigo);
				posicion = buscarCliente(lista, tam, codigo);
				if(posicion != -1){
					printf("\n Ingrese valor a depositar:");
					scanf("%f", &valor);
					depositar(&lista[posicion], valor);
					mostrarUno(lista[posicion]);
				}else{
					printf("\n El cliente no existe.");
				}
				break;
			case 4:
				printf("\n Ingrese numero de cliente a buscar:");
				scanf("%d",&codigo);
				posicion = buscarCliente(lista, tam, codigo);
				if(posicion != -1){
					printf("\n Ingrese valor a retirar:");
					scanf("%f", &valor);
					if(verificarRetiro(lista[posicion], valor) == 1){
						retirar(&lista[posicion], valor);
						mostrarUno(lista[posicion]);
					}else{
						printf("Saldo insuficiente.\n");
					}
					
				}else{
					printf("\n El cliente no existe.");
				}
				break;
			case 5:
				printf("\n Ingrese numero de cliente a buscar:");
				scanf("%d", &codigo);
				posicion = buscarCliente(lista, tam, codigo);
				if(posicion != -1){
					mostrarUno(lista[posicion]);
					modificarCliente(&lista[posicion]);
					mostrarUno(lista[posicion]);
				}else{
					printf("\n El cliente no existe.");
				}
				break;
		}
	}while(opcion != 0);	
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("1 - Cargar Clientes.\n");
		printf("2 - Mostrar Clientes.\n");
		printf("3 - Realizar un deposito.\n");
		printf("4 - Realizar un retiro.\n");
		printf("5 - Modificar datos de un cliente.\n");
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
	Retorna un cliente cargado, con el saldo en 0.
	La posicion es asignada automaticamente.
*/
tCliente cargarUno(int posi){
	tCliente nuevo;
	
	nuevo.nro = posi;
	fflush(stdin);
	printf("\n Ingrese nombre del cliente:");
	leeCad(nuevo.nombre,tam_max);
	nuevo.saldo = 0;
	nuevo.domicilio = cargarDomicilio();
	
	return nuevo;
}

/*
	Carga el domicilio de un cliente;
*/
tDomicilio cargarDomicilio(){
	tDomicilio nuevo;
	
	fflush(stdin);
	printf("\n Ingrese calle:");
	leeCad(nuevo.calle, tam_max);
	fflush(stdin);
	printf("\n Ingrese numero:");
	leeCad(nuevo.numero, tam_max);
	fflush(stdin);
	printf("\n Ingrese Ciudad:");
	leeCad(nuevo.ciudad, tam_max);
	fflush(stdin);
	printf("\n Ingrese Telefono:");
	leeCad(nuevo.telefono, tam_max);
	
	return nuevo;
	
}

/*
	Carga la lista de clientes.
*/
void cargarLista(tLista lista,int *tam){
	int i;
	
	printf("\n Ingrese cantidad de clientes:");
	scanf("%d",tam);
	for(i=1;i<=*tam;i++){
		printf("Ingrese el %d %c cliente:\n", i, 167);
		lista[i] = cargarUno(i);
	}
}

/*
	Muestra un solo cliente
*/
void mostrarUno(tCliente reg){
	
	printf("\n Numero del cliente: %d",reg.nro);
	printf("\n Nombre del cliente: %s",reg.nombre);
	printf("\n Saldo del cliente: %f",reg.saldo);
	mostrarDomicilio(reg.domicilio);
	printf("\n---------------- \n");
}

/*
	Muestra el domicilio de un cliente.
*/
void mostrarDomicilio(tDomicilio reg){
	printf("\n Calle : %s", reg.calle);
	printf("\n Numero : %s", reg.numero);
	printf("\n Ciudad : %s", reg.ciudad);
	printf("\n Telefono : %s", reg.telefono);
}
/*
	Muestra la lista de clientes.
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
int buscarCliente(tLista lista, int tam, int cod){
	int ini,fin,m;
	
	ini=1;
	fin=tam;
	m=(ini+fin)/2;
	while( ini<=fin && lista[m].nro != cod){
		if(lista[m].nro > cod){
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
	Modifica el saldo de un cliente.
*/
void depositar(tCliente *reg,float valor){
	
	reg->saldo = reg->saldo + valor;
}

/*
	Retorna 1,si se puede realzar el retiro.
	Retorna -1, en caso contrario
*/
int verificarRetiro(tCliente reg, float valor){
	if(reg.saldo >= valor){
		return 1;
	}else{
		return -1;
	}
}

/*
	Modifica el saldo de un cliente.
*/
void retirar(tCliente *reg, float valor){
	
	reg->saldo = reg->saldo - valor;
}

/*
	Modifica los datos de un cliente.
*/
void modificarCliente(tCliente *reg){	
	
	fflush(stdin);
	printf("\n Ingrese nombre del cliente:");
	leeCad(reg->nombre, tam_max);
	reg->domicilio = cargarDomicilio();	
}


