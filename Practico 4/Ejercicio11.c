#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
Autor: Fernando Orquera
Año: 2017
Se necesita el archivo ejericio11.txt.
*/

const int tam_max=100;

typedef char Tcadena[100];

typedef struct{
	Tcadena fecha;
	Tcadena marca;
	Tcadena matricula;
	int precio;	
}tVehiculo;

typedef tVehiculo tLista[100];

int menu();
int leeCad(Tcadena, int);
tVehiculo cargarUno(Tcadena cadena);
void formatearFecha(Tcadena fecha);
void vectorAuxiliar(char a[5][100], Tcadena cadena);
void eliminarC(Tcadena cadena,int posi);
void aammdd(Tcadena cadena);
void armarLista(tLista lista, int *tam);
void insertar(Tcadena cadena,char c,int posi);
void agregarGuiones(Tcadena fecha);
void mostrarUno(tVehiculo reg);
void mostrarLista(tLista lista,int tam);
void ordenar(tLista lista, int tam);
void mostrarVentasPorMarca(tLista lista, int tam, Tcadena marca);
void totalVentasMarcas(tLista lista, int tam);
void mostrarVentasAnteriores(tLista lista, int tam, Tcadena fecha);
void reemplazarGuiones(Tcadena cadena);

int main(){
	
	tLista lista;
	int tam, opcion;	
	Tcadena marca;
	
	tam = 0;
	srand(time(NULL));	
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				if(tam == 0){
					armarLista(lista, &tam);
					ordenar(lista, tam);
				}else{
					printf("Las ventas ya fueron cargadas.\n");
				}
				break;
			case 2:
				if(tam > 0){
					fflush(stdin);
					printf("Ingrese marca:\n");
					leeCad(marca, tam_max);
					mostrarVentasPorMarca(lista, tam, marca);
				}else{
					printf("Las ventas no fueron cargadas.\n");
				}
				break;
			case 3:
				if(tam > 0){
					totalVentasMarcas(lista, tam);
				}else{
					printf("Las ventas no fueron cargadas.\n");
				}				
				break;		
			case 4:
				if(tam > 0){
					fflush(stdin);
					printf("Ingrese fecha (dd-mm-aa):\n");
					leeCad(marca, tam_max);
					mostrarVentasAnteriores(lista, tam, marca);
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
		printf("\n1 - Cargar Ventas.\n");
		printf("2 - Listar ventas por marca.\n");
		printf("3 - Mostrar total de las marcas.\n");		
		printf("4 - Mostrar ventas anteriores dada una fecha.\n");
		printf("5 - Mostrar Ventas.\n");
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
	Retorna una venta cargada.
*/
tVehiculo cargarUno(Tcadena cadena){
	char a[5][100];
	tVehiculo nuevo;	
	
	vectorAuxiliar(a, cadena);
	formatearFecha(a[0]);
	strcpy(nuevo.fecha, a[0]);
	strcpy(nuevo.marca, a[1]);
	strcpy(nuevo.matricula, a[2]);
	nuevo.precio = atoi(a[3]);
	
	return nuevo;
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
	Invierte una fecha al formato aammdd.
*/
void aammdd(Tcadena cadena){	
	char aux1, aux2;
	int tam;
	
	tam = strlen(cadena) - 1;
	aux1 = cadena[0];
	aux2 = cadena[1];
	cadena[0] = cadena[tam - 1];
	cadena[1] = cadena[tam];
	cadena[tam] = aux2;
	cadena[tam - 1] = aux1;	
}

/*
	Borra los dos primeros caracteres de una fecha.
	aaaammdd -> aammdd
*/
void formatearFecha(Tcadena fecha){
	int i;
	
	for(i = 1; i<= 2; i++){
		eliminarC(fecha, 0);
	}	
}
/*
	Retorna un vector auxiliar almacenando los datos 
	extraidos de la cadena.
*/
void vectorAuxiliar(char a[5][100], Tcadena cadena){
	char limitador[3] = " \n";
	char *ptr;
	int i;
	
	i = 0;
	ptr = strtok(cadena, limitador);
	strcpy(a[i], ptr);
	while( (ptr = strtok( NULL, limitador )) != NULL ){
		i++;
		strcpy(a[i], ptr);
	}
}

/*
	Retorna la lista de registros.
*/
void armarLista(tLista lista, int *tam){
	
	FILE *archivo;
	Tcadena linea;
	char *pos;	
	
	archivo = fopen("ejercicio11.txt", "r");
	
	*tam = 0;
	if( archivo != NULL ){
		while (fgets(linea, sizeof(linea), archivo)) {
			if((pos=strchr(linea,'\n')) != NULL)
				*pos = '\0';
			*tam = *tam + 1;
			lista[*tam] = cargarUno(linea);
		}
	}
	
	
	fclose(archivo);
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
	Agregar guiones a una fecha.
	ddmmaa -> dd-mm-aa
*/
void agregarGuiones(Tcadena fecha){	
	
	insertar(fecha, '-', 2);
	insertar(fecha, '-', 5);
}

/*
	Muestra una sola venta.
*/
void mostrarUno(tVehiculo reg){
	Tcadena fechaAux;
	
	strcpy(fechaAux, reg.fecha);
	aammdd(fechaAux);
	agregarGuiones(fechaAux);
	printf("\n Fecha: %s", fechaAux);
	printf("\n Marca %s", reg.marca);
	printf("\n Matricula: %s", reg.matricula);
	printf("\n Precio: %d", reg.precio);	
	printf("\n---------------- \n");
}

/*
	Muestra la lista de ventas.
*/
void mostrarLista(tLista lista, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		mostrarUno(lista[i]);
	}
}


/*
	Ordena la lista de menor a mayor segun
	marca de vehiculo.
*/
void ordenar(tLista lista, int tam){
	int i, j;
	tVehiculo aux;
	
	for(i = 1; i <= tam - 1; i++){
		for(j = i + 1; j <= tam; j++){
			if(lista[j].marca < lista[i].marca){
				aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;
			}
		}		
	}
}

/*
	Muestras las ventas de determinada marca.
*/
void mostrarVentasPorMarca(tLista lista, int tam, Tcadena marca){
	int i, band;
	
	band = 0;
	for(i = 1; i <= tam; i++){
		if(strcmp(lista[i].marca, marca) == 0){
			band = 1;
			mostrarUno(lista[i]);
		}		
	}
	if(band == 0){
		printf("\nNo hay ventas para esa marca.");
	}
}


/*
	Muestra el total de ventas por marca.
*/
void totalVentasMarcas(tLista lista, int tam){
	int i, ventas;
	
	ventas = lista[1].precio;
	for(i = 2; i <= tam ; i++){
		if(strcmp(lista[i].marca, lista[i - 1].marca) == 0){
			ventas = ventas + lista[i].precio;
		}else{
			printf("\n Marca: %s", lista[i - 1].marca);
			printf("\n Total de Venta: %d", ventas);
			printf("\n---------------- \n");
			ventas = lista[i].precio;
		} 
	}
	printf("\n Marca: %s", lista[i - 1].marca);
	printf("\n Total de Venta: %d", ventas);
	printf("\n---------------- \n");
	ventas = lista[i].precio;
}

/*
	Quita los guiones de una fecha.
	dd-mm--aa -> ddmmaa.
*/
void reemplazarGuiones(Tcadena cadena){
	
	eliminarC(cadena, 5);
	eliminarC(cadena, 2);
}

/*
	Muestra las ventas anteriores a la fecha dada.
*/
void mostrarVentasAnteriores(tLista lista, int tam, Tcadena fecha){
	int i, band;
	
	band = 0;
	reemplazarGuiones(fecha);
	aammdd(fecha);
	for(i = 1; i <= tam; i++){
		if(atoi(lista[i].fecha) < atoi(fecha)){
			band = 1;
			mostrarUno(lista[i]);
		}
	}
	if(band == 0){
		printf("\nNo hay ventas anteriores a esa fecha.");
	}	
}
