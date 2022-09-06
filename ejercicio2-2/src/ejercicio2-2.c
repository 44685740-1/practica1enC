/*
 ============================================================================
 Name        : ejercicio2-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio 2-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
	setbuf(stdout, NULL);
	int i;
	int numero;
	int contadorPar;
	int contadorImpar;
	int mayorPar;
	int menorNumero;
	int acumuladorPositivos;
	int acumuladorProdcutoNegativos;
	//inicializar
	contadorImpar = 0;
	contadorPar = 0;
	acumuladorPositivos = 0;
	acumuladorProdcutoNegativos = 1;//muy importante inicializar en 1 para hacer el acumulador de multipplicacio *=


	for (i = 0; i < 3; i++) {
		printf("ingrese un numero entero que no sea 0\n");
		fflush(stdin);
		scanf("%d", &numero);
		//if par o impar
		if (numero % 2 == 0) {
			contadorPar++;
			if (i == 1) {
				mayorPar = numero;
			} else {
				if (numero > mayorPar) {
					mayorPar = numero;
				}
			}
		} else {
			contadorImpar++;
		}

		//if bandera menor numero
		if(i == 1){
			menorNumero = numero;
		} else{
			if(numero < menorNumero){
				menorNumero = numero;
			}
		}

		//if suma positivos
		if(numero > 0){
			acumuladorPositivos += numero;
		}

		//if producto de los negativos
		if(numero < 0){
			acumuladorProdcutoNegativos *= numero;
		}
	}


	printf("la cantidad de impares es de: %d", contadorImpar);
	printf("la cantidad de pares es de: %d", contadorPar);
	printf("el menor numero ingresado es: %d", menorNumero);
	printf("el mayor de los numeros pares es: %d", mayorPar);
	printf("la suma de los positivos es de: %d", acumuladorPositivos);
	printf("el producto de los negativos es: %d", acumuladorProdcutoNegativos);
	return 0;
}
