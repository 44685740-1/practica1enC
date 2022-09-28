/*
 ============================================================================
 Name        : ejercicio4-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio4-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validacionNumeroPositivo.h"
int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int retornoValidacionPositivo;
	int acumulador;
	//inicializar
	acumulador = 1; //importante inicializarlo en 1
	printf("ingrese un numero positivo para calcular el factorial");
	fflush(stdin);
	scanf("%d", &numero);
	retornoValidacionPositivo = validacionNumeroPositivo(numero);
	if (retornoValidacionPositivo == 0) {
		for (int i = numero; numero > 0; numero--) {
			acumulador *= numero;
			printf("%d *", numero);
		}
		printf("el factorial es: %d", acumulador);
	} else {
		printf("ingrese un numero positivo");
	}
	/*
	 factorial hecho con recursividad
	 int factorial(int numero) {

	 if (numero <= 1){
	 return 1;
	 }

	 return numero * factorial(numero - 1);
	 }

	 int main(void) {
	 int numero = 3;
	 int factorialDelNumero = factorial(numero);
	 printf("El factorial de %d es %d", numero, factorialDelNumero);
	 }

	 */
	return 0;
}
