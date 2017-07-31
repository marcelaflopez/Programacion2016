#include <stdio.h>

int cargarAngulo();

int main() {
	int angulo1, angulo2, angulo3;
	
	do {
		angulo1 = cargarAngulo();
		angulo2 = cargarAngulo();
		angulo3 = cargarAngulo();
		
		if(angulo1 + angulo2 < angulo3 && angulo3 + angulo2 < angulo1 && angulo1 + angulo3 < angulo2){
			printf("La suma de dos lados cualquieras tiene que ser mayor o igual al tercer lado!\n");
		}
	}while(angulo1 + angulo2 < angulo3 && angulo3 + angulo2 < angulo1 && angulo1 + angulo3 < angulo2);
	
	if(angulo1 != angulo2 && angulo2 != angulo3 && angulo1 != angulo3 ){
		printf("El triangulo es escaleno\n");
	}else if(angulo1 == angulo2 && angulo2 == angulo3){
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
