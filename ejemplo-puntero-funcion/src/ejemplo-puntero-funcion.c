/*
 ============================================================================
 Name        : ejemplo-puntero-funcion.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejemplo-puntero-funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sumar(int parametro1, int parametro2, int* pResultado);
void restar(int parametro1, int parametro2, int* pResultado);
int calcular(int parametro1, int parametro2, void(*pFuncion)(int,int,int*));

int main(void) {
	setbuf(stdout, NULL);
	int auxiliar;
	auxiliar = calcular(10, 5, restar);
	printf("el resultado de la resta es: %d\n", auxiliar);

	auxiliar = calcular(10, 5, sumar);
	printf("el resultado de la suma es: %d\n", auxiliar);
	return 0;
}

void sumar(int parametro1, int parametro2, int* pResultado){
	*pResultado = parametro1 + parametro2;
}

void restar(int parametro1, int parametro2, int* pResultado){
	*pResultado = parametro1 - parametro2;
}

int calcular(int parametro1, int parametro2, void(*pFuncion)(int,int,int*)){
	int auxResultado;
	pFuncion(parametro1,parametro2,&auxResultado);
	return auxResultado;

}
