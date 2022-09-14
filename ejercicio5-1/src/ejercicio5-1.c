/*
 ============================================================================
 Name        : ejercicio5-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define contadorVeltas 5 //ejemplo de uso del define para el la cantidad de vueltas que iteramos
//El define se resuelve en tiempo de compilación y la variable en tiempo de ejecución
//lo que hace le define es buscar donde esta algo igual al nombre que le pusimos y le asigna el valor que tiene al lado
int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int i;
	int acumuladorSuma;
	int arrayNumerosEnteros[5];
	//inicilizar
	acumuladorSuma = 0;
	for(i=0; i<contadorVeltas; i++){
		printf("ingrese un numero\n");
		scanf("%d", &numero);
		acumuladorSuma += numero;
		arrayNumerosEnteros[i] = numero;
	}

	printf("la suma es: %d \n", acumuladorSuma);
	printf("los numeros son: ");
	//hago otro for para recorrer el array y mostrar los numeros todos juntos
	for(i=0; i<contadorVeltas; i++){
		printf("%d", arrayNumerosEnteros[i]);
	}
	return 0;
}
