/*
 ============================================================================
 Name        : ejercicio3-5.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio3-5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumarDosEnteros1(int numero1, int numero2);
int sumarDosEnteros2(void);
void sumarDosEnteros3(int numero1, int numero2);
void sumarDosEnteros4(void);
int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	printf("ingrese el primer numero");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero");
	fflush(stdin);
	scanf("%d", &numero2);
	sumarDosEnteros3(numero1,numero2);
	return 0;
}


//pide los dos datos y ademas retorna
int sumarDosEnteros1(int numero1, int numero2) {
	int suma;
	suma = numero1 + numero2;
	return suma;
}


//no piede nada pero si retorna el resultado en este caso la suma
int sumarDosEnteros2(void) {
	int numero1;
	int numero2;
	int suma;
	printf("ingrese el primer numero");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero");
	fflush(stdin);
	scanf("%d", &numero2);
	suma = numero1 + numero2;
	return suma;
}


//pide los datos del main pero no retorna nada
void sumarDosEnteros3(int numero1, int numero2) {
	int suma;
	suma = numero1 + numero2;
	printf("%d", suma);
}


//hay que hacer todo aca no pide nada ni retorna nada
void sumarDosEnteros4(void) {
	int numero1;
	int numero2;
	int suma;
	printf("ingrese el primer numero");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero");
	fflush(stdin);
	scanf("%d", &numero2);
	suma = numero1 + numero2;
	printf("%d", suma);
}
