/*
 ============================================================================
 Name        : anexo5-4.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : anexo5-4.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inicilalizarArratDeFomaAleatoria.h"
void inicializarArray(int arraEdades[]);
int main(void) {
	setbuf(stdout, NULL);
	int arrayEdades[5];
	inicializarArray(arrayEdades);
	inicilalizarArratDeFomaAleatoria(arrayEdades);
	return 0;
}


void inicializarArray(int arraEdades[]){
	int i;
	for(i=0;i<5;i++){
		arraEdades[i] = 0;
	}

	for(i=0;i<5;i++){
		printf("%d\n", arraEdades[i]);
	}
}
