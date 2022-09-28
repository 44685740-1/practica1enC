/*
 ============================================================================
 Name        : ejercicio6-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio6-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int a;
	int buffer;
	int b;
	printf("ingrese el valor de a: \n");
	fflush(stdin);
	scanf("%d", &a);
	printf("ingrese el valor de b: \n");
	fflush(stdin);
	scanf("%d", &b);
	//nos piden hacer un intercambio de valores entre a y b es decir hacer un swap
	//para esto usamos una variable temporal que la llamamos buffer por regla de estilo
	buffer = a;
	a = b;
	b = buffer;
	printf("a: %d y b: %d",a,b);
	return 0;
}
