/*
 ============================================================================
 Name        : ejercicio18-5.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char nombre[168];
	int edad;
}alumno;
int main(void) {
	FILE* pArchivo;
	setbuf(stdout, NULL);
	char id[168];
	char nombre[168];
	char edad[168];
	int retorno;
	int i= 0;

	//declaro arrya de alumnos
	alumno alumnos[50];


	pArchivo =	fopen("dataMock.csv", "r");
	if(pArchivo != NULL){
		//LECTURA FANTASMA PARA QUE NO ME IMPRIMA LA CABECERA
		fscanf(pArchivo, "%[^,], %[^,],%[^\n]\n", id, nombre, edad);
		do{
		retorno =  fscanf(pArchivo, "%[^,], %[^,],%[^\n]\n", id, nombre, edad);
		if(retorno == 3){
			//LO GUARDO EN EL ARRYA DE ALUMNOS
			//CON LOS TIPOS DE DATO CORRESPONDIENTES A LA ESTRUCTURA
			alumnos[i].id = atoi(id);
			strcpy(alumnos[i].nombre, nombre);
			alumnos[i].edad = atoi(edad);
			i++;
		} else{
			printf("\nHUBO UN ERROR\n");
		}

		}while(feof(pArchivo) == 0);//!feof(pArchivo) negarlo tambien es valido
		//CIERRO EL ARCHIVO SI PUSO SER ABIERTO
		fclose(pArchivo);
	} else{
		printf("\nNO SE PUDO ABRIR EL ARCHIVO\n");
	}

	//MUESTRO LOS DATOS LEIDOS DEL CSV QUE GUARDE EN EL ARRAY
	for(int j= 0; j < 50; j++){
		printf("\nid %d\n", alumnos[j].id);
		printf("\nnombre %s\n", alumnos[j].nombre);
		printf("\nedad %d\n", alumnos[j].edad);
	}

	return 0;
}
