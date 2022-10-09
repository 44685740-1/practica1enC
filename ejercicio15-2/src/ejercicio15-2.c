/*
 ============================================================================
 Name        : ejercicio15-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio 15-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int cargarValorPuntero(int* pPuntero);
int main(void) {
	setbuf(stdout, NULL);
	int resultado;
	int retornoFuncion;
	retornoFuncion = cargarValorPuntero(&resultado);
	if(retornoFuncion != -1){
		printf("%d", resultado);
	} else{
		printf("ERROR");
	}

	return 0;
}

int cargarValorPuntero(int* pPuntero){
	int retorno = -1;
	int pResultado;
	printf("ingrese el valor por puntero\n");
	scanf("%d", &pResultado);
	*pPuntero = pResultado;
	if(pPuntero != NULL){
		retorno = 0;
	}
	return retorno;
}
