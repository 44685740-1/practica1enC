/*
 ============================================================================
 Name        : manejoPünteros.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : manejo punteros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int myAge = 43;// An int variable
	int* ptr = &myAge;// A pointer variable, with the name ptr, that stores the address of myAge ptr tiene guardado la direccion de memoria de myage

	// Output the value of myAge (43)
	printf("%d\n", myAge);

	// Output the memory address of myAge (0x7ffe5367e044)
	printf("%p\n", &myAge);

	// Output the memory address of myAge with the pointer (0x7ffe5367e044)
	printf("%p\n", ptr);//se usa la mascara p de puntero

	// Dereference: Output the value of myAge with the pointer (43)
	printf("%d\n", *ptr);
	return 0;
}
