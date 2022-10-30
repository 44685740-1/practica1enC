/*
 ============================================================================
 Name        : ejercicio17-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio17-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	int edad;
	char nombre[30];
	float nota;
}eAlumno;

eAlumno* cargarAlumno();
int MostrarAlumno(eAlumno* pDato);
int main(void) {
	setbuf(stdout, NULL);
	eAlumno* pDato;

	pDato = cargarAlumno();//pDato recibe el retorno de cargar alumno
	MostrarAlumno(pDato);
	return 0;
}

eAlumno* cargarAlumno(){

	eAlumno* pAlumno;

	pAlumno = (eAlumno*) malloc(sizeof(eAlumno));

	if(pAlumno != NULL){
		pAlumno->edad = 0;
		strcpy(pAlumno->nombre,"ahuitz");
		pAlumno->nota = 0;
	}
	return pAlumno;
}

int MostrarAlumno(eAlumno* pDato)//constructor por defecto tambien se puede cargar con parametros
{
	int todoOk;
	todoOk = 0;
	if(pDato!=NULL)
	{
		todoOk = 1;
		printf("edad: %d\n", pDato->edad);
		printf("nota: %f\n", pDato->nota);
		printf("nombre: %s\n", pDato->nombre);
	}
	return todoOk;
}
