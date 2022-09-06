/*
 ============================================================================
 Name        : ejercicio5-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int i;
	int acumuladorSuma;
	//inicilizar
	acumuladorSuma = 0;
	for(i=0; i<5; i++){
		printf("ingrese un numero\n");
		scanf("%d", &numero);
		acumuladorSuma += numero;
	}

	printf("la suma de los cinco numeros es: %d", acumuladorSuma);
	return 0;
}
