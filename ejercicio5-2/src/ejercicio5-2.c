/*
 ============================================================================
 Name        : ejercicio5-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio5-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "recorridoNumerosIngresados.h"
#include "recorridoNumerosPares.h"
#include "recorridoNumerosPosicionImpar.h"
#define contadorVueltas 5
int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int i;
	int contadorDePositivos;
	int contadorDeNegativos;
	int acumuladorPares;
	int mayorImpar;
	int contadorNumerosPar;
	int contadorPosicionesImpar;
	int arrayNumerosIngresados[contadorVueltas];

	//inicializar
	acumuladorPares = 0;
	contadorDeNegativos = 0;
	contadorDePositivos = 0;
	contadorNumerosPar = 0;
	contadorPosicionesImpar = 0;
	int arrayNumerosPares[contadorNumerosPar];
	int arrayPosicionesImpares[contadorPosicionesImpar];

	for (i = 0; i < contadorVueltas; i++) {
		do {
			printf("ingrese un numero entre 1000 y -1000 \n");
			scanf("%d", &numero);
		} while (numero <= -1000 || numero >= 1000);
		//contador positivos y negativos
		if (numero >= 0) {
			contadorDePositivos++;
		} else {
			contadorDeNegativos++;
		}
		//acumulador pares y mayor impar
		if (numero % 2 == 0) {
			acumuladorPares += numero;
			contadorNumerosPar++;
			arrayNumerosPares[i] = numero; //array numeros pares
		} else {
			if (i == 0) { //la i tiene que ser 0 para la bandera porque recien se incrementa cuando da la vuelta otra vez
				mayorImpar = numero;
			} else {
				if (numero > mayorImpar) {
					mayorImpar = numero;
				}
			}
		}

		//array numeros ingresados
		arrayNumerosIngresados[i] = numero;

		//array en posicioners impares
		if (i % 2 != 0) {
			contadorPosicionesImpar++;
			arrayPosicionesImpares[i] = numero;
		}

	}

	printf("la cantidad de positivos es: %d\n", contadorDePositivos);
	printf("la cantidad de negativos es: %d \n", contadorDeNegativos);
	printf("la sumatoria de los pares: %d \n", acumuladorPares);
	printf("el mayor de los impares es: %d \n", mayorImpar);
	//recorridos de e) f) d)
	recorridoNumerosIngresados(arrayNumerosIngresados);
	recorridoNumerosPares(arrayNumerosPares, contadorNumerosPar);
	recorridoNumerosPosicionImpar(arrayPosicionesImpares,
			contadorPosicionesImpar);
	return 0;
}
