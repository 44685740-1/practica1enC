/*
 ============================================================================
 Name        : ejercicio3-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio3-3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int retornoEnteroIngresado ();
int main(void) {
	setbuf(stdout, NULL);
	int numeroDeLaFuncion;
	numeroDeLaFuncion = retornoEnteroIngresado ();
	printf("%d", numeroDeLaFuncion);
	return 0;
}

int retornoEnteroIngresado (){
	int numero;
	printf("ingrese un numero entero\n");
	scanf("%d", &numero);
	return numero;
}
