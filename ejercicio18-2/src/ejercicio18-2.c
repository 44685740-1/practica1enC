/*
 ============================================================================
 Name        : ejercicio18-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio18-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
typedef struct{
	int legajo;
	char nombre[30];
	int nota;
}eAlumno;

int main(void) {
	eAlumno alumnos[TAM];
	alumnos[0].legajo = 2547;
	strcpy(alumnos[0].nombre, "ahuitz");
	alumnos[0].nota = 8;

	alumnos[1].legajo = 2589;
	strcpy(alumnos[1].nombre, "carlos");
	alumnos[1].nota = 9;

	alumnos[2].legajo =  4578;
	strcpy(alumnos[2].nombre, "juan");
	alumnos[2].nota = 6;

	return 0;
}
