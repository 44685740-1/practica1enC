/*
 ============================================================================
 Name        : ejercicio16-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio16-2.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int calcularMayorArray(int *arrayEnteros, int *pMayorResultado);
int calcularMenorArray(int *arrayEnteros, int *pMenorResultado);
int calcularMayorMenor(int* arrayEnteros, int *pResultado, void(*pFuncion)(int* , int*));
int main(void) {
	setbuf(stdout, NULL);
	int arrayEnteros[11];
	int pMayorResultado;
	int retornoCalcularMayor;
	int retornoCalcularMenor;
	int pMenorResultado;
	int auxResultado;
	int retornoCalcularMayorMenor;
	for (int i = 0; i < 10; i++) {
		arrayEnteros[i] = i;
	}
	/*
	retornoCalcularMayor = calcularMayorArray(arrayEnteros, &pMayorResultado);
	if (retornoCalcularMayor != -1) {
		printf("mayor: %d\n", pMayorResultado);
	}

	retornoCalcularMenor = calcularMenorArray(arrayEnteros, &pMenorResultado);
	if (retornoCalcularMenor != -1) {
			printf("menor: %d\n", pMenorResultado);
		}
	*/
	auxResultado = calcularMayorMenor(arrayEnteros, &auxResultado, calcularMayorArray);
	auxResultado = calcularMayorMenor(arrayEnteros, &auxResultado, calcularMenorArray);

				printf("mayor: %d\n", auxResultado);

	return 0;
}

int calcularMayorArray(int *arrayEnteros, int *pMayorResultado) {
	int mayor;
	int rtn;
	for (int i = 0; i < 10; i++) {
		if (arrayEnteros[i] < arrayEnteros[i + 1]) {
			mayor = arrayEnteros[i];
		}
	}

	*pMayorResultado = mayor;
	if (pMayorResultado != NULL) {
		rtn = 0;
	} else {
		rtn = -1;
	}

	return rtn;
}

int calcularMenorArray(int *arrayEnteros, int *pMenorResultado) {
	int mayor;
	int rtn;
	for (int i = 0; i > 10; i++) {
		if (arrayEnteros[i] < arrayEnteros[i + 1]) {
			mayor = arrayEnteros[i];
		}
	}

	*pMenorResultado = mayor;
	if (pMenorResultado != NULL) {
		rtn = 0;
	} else {
		rtn = -1;
	}

	return rtn;
}

int calcularMayorMenor(int* arrayEnteros, int *pResultado, void(*pFuncion)(int* , int*)){
	int auxResultado;
	pFuncion(arrayEnteros,&auxResultado);
	return auxResultado;
}
