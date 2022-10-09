/*
 ============================================================================
 Name        : ejercicio16-4.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio16-4.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int id;
	int precio;
	char marca[10];
}producto;
#define TAM 5
int main(void) {
	setbuf(stdout, NULL);
	producto productos[TAM];

	return 0;
}
