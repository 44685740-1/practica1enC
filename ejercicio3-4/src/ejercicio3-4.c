/*
 ============================================================================
 Name        : ejercicio3-4.c
 Author      : Ahuitz Caraccciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio3-4.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//prototipo
int numeroValidadoRango(int rango1, int rango2);
int main(void) {
	setbuf(stdout, NULL);
	int rango1;
	int rango2;
	int validacion;
	printf("ingrese le primer valor del rango\n");
	scanf("%d", &rango1);
	printf("ingrese le segundo valor del rango\n");
	scanf("%d", &rango2);
	validacion = numeroValidadoRango(rango1,rango2);
	if(validacion == 0){
		printf("esta dentro del rango");
	} else{
		printf("esta fuera del rango");
	}
	return 0;
}

int numeroValidadoRango(int rango1, int rango2){
	int numero;
	int retorno;
	printf("ingrese un numero\n");
	scanf("%d", &numero);
	if(numero >= rango1 && numero <= rango2){
		retorno = 0;
	} else{
		retorno = -1;
	}
	return retorno;
}
