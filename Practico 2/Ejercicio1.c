#include <stdio.h>

int cargarAngulo();

int main() {
	int angulo1, angulo2, angulo3;
	
	do {
		angulo1 = cargarAngulo();
		angulo2 = cargarAngulo();
		angulo3 = cargarAngulo();
		
		if(angulo1 + angulo2 + angulo3 != 180){
			printf("La suma de los angulos internos tiene que ser 180 grados!\n");
		}
	}while(angulo1 + angulo2 + angulo3 != 180);
	
	if(angulo1 > 90 || angulo2 > 90 || angulo3 > 90){
		printf("El triangulo es obtusangolo\n");
	}else if(angulo1 == 90 || angulo2 == 90 || angulo3 == 90){
		printf("El triangulo es rectangulo\n");
	}else{
		printf("El triangulo es acutangolo\n");
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
