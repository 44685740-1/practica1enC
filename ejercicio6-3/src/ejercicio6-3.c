/*
 ============================================================================
 Name        : ejercicio6-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio6-3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
int main(void) {
	setbuf(stdout, NULL);
	char nombre[20];
	char apellido[20];
	char nombreYapellido[50];
	char coma[2] = {',', ' '};
	printf("ingrese su nombre\n");
	fflush(stdin);
	fgets(nombre,20,stdin);
	nombre[strlen(nombre)-1]='\n';
	nombre[strlen(nombre)-1]='\0';
	printf("%s", nombre);
	printf("ingrese su apellido\n");
	fflush(stdin);
	fgets(apellido,20,stdin);
	apellido[strlen(apellido)-1]='\n';
	apellido[strlen(apellido)-1]='\0';
	printf("%s", apellido);
	strcat(apellido, coma);
	strcpy(nombreYapellido, apellido);
	strcat(nombreYapellido, nombre);
	printf("\n%s", nombreYapellido);
	return 0;
}
