/*
 ============================================================================
 Name        : sabado17-9.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : sabado17-9
 1) que convierta una cadena a MAYUSCULAS (replicar tolupper)
 2) que convuierta una cadena a minusculas (replicar tolower)
 3) que copie un literal a una cadena validando el tamaño del literal
 4) que valide si todos sus caracteres son alfabeticos
 5) que pida y guarde un literal en una cadena con el siguiente HEAD:
 int get_string(char* MSJ, char* ERROR_MSJ, char* pString, int len)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toLowerToUpper.h"
#include "validacionAlfabetico.h"
int main(void) {
	setbuf(stdout, NULL);
	/*
	 * toLower y toUpper para strings
	 char cadenaMayusculas[15];
	 int lenCadenaMayuscula;
	 char cadenaMinusculas[15];
	 int lenCadenaMinuscula;
	 //funcion toUpper de string
	 printf("ingrese una cadena en minusculas\n");
	 fflush(stdin);
	 fgets(cadenaMinusculas, 15, stdin);
	 printf("sin la funcion \n %s", cadenaMinusculas);
	 lenCadenaMinuscula = strlen(cadenaMinusculas);
	 toUpper(cadenaMinusculas, lenCadenaMinuscula);
	 //funcion toLower de string
	 printf("ingrese una cadena en mayusculas\n");
	 fflush(stdin);
	 fgets(cadenaMayusculas, 15, stdin);
	 printf("sin la funcion \n %s", cadenaMayusculas);
	 lenCadenaMayuscula = strlen(cadenaMayusculas);
	 toLower(cadenaMayusculas, lenCadenaMayuscula);
	 */

	//validacion que los caraccteres sean alfabeticos
	char arrayAfabetico[3];
	int retornoValidacion;
	int lenArrayAlfabetico;
	printf("ingrese una cadena alfabetica\n");
	fgets(arrayAfabetico, 3, stdin);

	lenArrayAlfabetico = strlen(arrayAfabetico);
	retornoValidacion = validacionAlfabeticos(arrayAfabetico, lenArrayAlfabetico);
	printf("%d", retornoValidacion);
	return 0;
}
