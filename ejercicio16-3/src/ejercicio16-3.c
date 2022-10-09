/*
 ============================================================================
 Name        : ejercicio16-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio16-3.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int suma(int numero1, int numero2, int *pResultado);
int resta(int numero1, int numero2, int *pResultado);
int multiplicacion(int numero1, int numero2, int *pResultado);
int division(int numero1, int numero2, int *pResultado);
int calcular(int numero1, int numero2, int(*pFuncion)(int, int, int*));

int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	int pResultado;
	int retorno;
	int auxiliar;
	//incializar
	numero1 = 15;
	numero2 = 5;

	auxiliar = calcular(numero1, numero2, multiplicacion);
	printf("%d", auxiliar);

	return 0;
}

int suma(int numero1, int numero2, int *pResultado) {
	int resultado;
	int rtn;
	resultado = numero1 + numero2;
	*pResultado = resultado;
	if (pResultado != NULL) {
		rtn = 0;
	} else {
		rtn = -1;
	}

	return rtn;
}

int resta(int numero1, int numero2, int *pResultado) {
	int resultado;
	int rtn;
	resultado = numero1 - numero2;
	*pResultado = resultado;
	if (pResultado != NULL) {
		rtn = 0;
	} else {
		rtn = -1;
	}

	return rtn;
}

int multiplicacion(int numero1, int numero2, int *pResultado) {
	int resultado;
	int rtn;
	resultado = numero1 * numero2;
	*pResultado = resultado;
	if (pResultado != NULL) {
		rtn = 0;
	} else {
		rtn = -1;
	}

	return rtn;
}

int division(int numero1, int numero2, int *pResultado) {
	int resultado;
	int rtn;
	resultado = numero1 / numero2;
	*pResultado = resultado;
	if (pResultado != NULL) {
		rtn = 0;
	} else {
		rtn = -1;
	}

	return rtn;
}
										//importante cambiar el void por int atras de (*pFuncion)
int calcular(int numero1, int numero2, int(*pFuncion)(int, int, int*)){
	int auxiliar;
	pFuncion(numero1,numero2, &auxiliar);
	return auxiliar;
}
