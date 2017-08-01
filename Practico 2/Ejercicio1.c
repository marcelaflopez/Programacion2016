#include <stdio.h>

int cargarAngulo();

int main() {
	int lado1, lado2, lado3;
	
	do {
		lado1 = cargarAngulo();
		lado2 = cargarAngulo();
		lado3 = cargarAngulo();
		
		if(lado1 + lado2 < lado3 && lado3 + lado2 < lado1 && lado1 + lado3 < lado2){
			printf("La suma de dos lados cualquieras tiene que ser mayor o igual al tercer lado!\n");
		}
	}while(lado1 + lado2 < lado3 && lado3 + lado2 < lado1 && lado1 + lado3 < lado2);
	
	if(lado1 != lado2 && lado2 != lado3 && lado1 != lado3 ){
		printf("El triangulo es escaleno\n");
	}else if(lado1 == lado2 && lado2 == lado3){
		printf("El triangulo es equilatero\n");
	}else{
		printf("El triangulo es isosceles\n");
	}
	
	return 0;
}

int cargarAngulo(){
	int nuevo;
	
	do {
		printf("Ingrese el valor del angulo:\n");
		scanf("%d", &nuevo);
		
		if(nuevo < 1){
			printf("Tiene que ser natural!\n");
		}
	}while(nuevo < 1);
	
	return nuevo;
}
