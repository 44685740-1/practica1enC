/*
 ============================================================================
 Name        : ejercicio3-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio3-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//prototipo
int ParImpar(int numero);
int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int parImpar;
	printf("ingrese un numero\n");
	scanf("%d", &numero);
	parImpar = ParImpar(numero);
	if(parImpar == 1){
		printf("es par");
	} else{
		printf("es impar");
	}
	return 0;
}

int ParImpar(int numero){
	int retorno;
	if(numero % 2 == 0){
		//es par
		retorno = 1;
	} else{
		//es impar
		retorno = 0;
	}
	return retorno;
}
