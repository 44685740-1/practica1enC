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
	FILE* pFile;

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

	int a;
	char nombre[168];
	int b;
	//ESCRITURA EN MODO TEXTO SEPARADO POR COMAS CADA DATO Y POR ENTER CADA ALUMNO

	//abro en modo escritura de texto
	pFile = fopen("alumnos.csv", "w");

	if(pFile != NULL){
		//si lo pudo abrir escribo el archivo
		for(int i= 0; i < TAM; i++){
			fprintf(pFile, "%d,%s,%d\n", alumnos[i].legajo, alumnos[i].nombre, alumnos[i].nota);
			fscanf(pFile, "%d,%[^,],%d\n", &a, nombre, &b);
		}

		printf("\nlegajo : %d\n", a);
		printf("\nnombre %s\n", nombre);
		printf("\nnota %d\n", b);
	} else{
		printf("\nNO SE PUDO ABRIR EL ARCHIVO\n");
	}

	return 0;
}
