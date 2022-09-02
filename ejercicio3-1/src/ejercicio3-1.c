/*
 ============================================================================
 Name        : ejercicio3-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio3-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//prototipo
float imprimirNumeroFlotante(float numeroFlotante);
int main(void) {
	setbuf(stdout, NULL);
	float numeroFlotante;
	float numeroImpreso;
	printf("ingrese un numero flotante");
	scanf("%f", &numeroFlotante);
	numeroImpreso = imprimirNumeroFlotante(numeroFlotante);
	printf("%f", numeroImpreso);
	return 0;
}

float imprimirNumeroFlotante(float numeroFlotante){
	float retorno;
	retorno = numeroFlotante;
	return retorno;
}
