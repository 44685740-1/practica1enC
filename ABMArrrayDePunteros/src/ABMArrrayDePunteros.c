/*
 ============================================================================
 Name        : ABMArrrayDePunteros.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ABMArrrayDePunteros.c
 * 1 Alta alumno
 * 2 Baja alumno
 * 3 Modificar alumno
 * 4 Ordenar por nombre
 * 5 Imprimir
 * 6 Informe promedio alturas
 * 7 Informe alumno mas alto
 * 8 Guardar a Archivo
 * 9 Leer desde Archivo
 * 10 Salir

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "validacionesInput.h"

int main(void) {
	setbuf(stdout, NULL);
	int retornoMenuPrincipal;
	int resultadoMenuPrincipal;


	//DECLARO ARRAY DE PUNTEROS
	alumno* arrayPunterosAlumnos[TAM];

	//INCIALIZO EL ARRAY DE PUNTEROS
	alumnos_IncializarArray(arrayPunterosAlumnos);
	do{
	printf("\n 1. ALTA \n 2. BAJA \n 3. MODIFICACION \n 4. ORDENAR POR NOMBRE \n 5. IMPRIMIR \n 6. INFORMAR PROMEDIO ALTURAS \n 7. INFORME ALUNO MAS ALTO \n 8. GUARDAR A ARCHIVO \n 9. LEER DESDE ARCHIVO \n 10. SALIR\n");
	do{
		retornoMenuPrincipal = utn_getUnsignedInt("\ningrese la opcion que desea del menu pricipal\n", "\nERROR\n", 1, 3, 1, 10, 1, &resultadoMenuPrincipal);
	}while(retornoMenuPrincipal != 0);
	switch(resultadoMenuPrincipal){
	case 1:
		printf("\nOPCION 1\n");
		break;
	case 2:
		printf("\nOPCION 2\n");
		break;
	case 3:
		printf("\nOPCION 3\n");
		break;
	case 4:
		printf("\nOPCION 4\n");
		break;
	case 5:
		printf("\nOPCION 5\n");
		break;
	case 6:
		printf("\nOPCION 6\n");
		break;
	case 7:
		printf("\nOPCION 7\n");
		break;
	case 8:
		printf("\nOPCION 8\n");
		break;
	case 9:
		printf("\nOPCION 9\n");
		break;
	case 10:
		printf("\nSALISTE\n");
		break;
	}
	}while(resultadoMenuPrincipal != 10);
	return 0;
}
