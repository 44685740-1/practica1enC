/*
 * validacionAlfabetico.c
 *
 *  Created on: 18 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validacionAlfabeticos(char *array, int len) {
	//valido que el caraccter sea una letra mayuscula o minuscula
	//es decir entre el rango del ASCII 65-122
	int retorno;
	int i;
	i = 0;
	while (array[i] != '\0') {
		if ((array[i] >= 65 && array[i] <= 90)
				|| (array[i] >= 97 && array[i] <= 122)) {
			retorno = 0;
		}

		if ((array[i] <= 65 && array[i] >= 90)
				|| (array[i] <= 97 && array[i] >= 122)) {
			retorno = -1;
		}
	}

	return retorno;
	printf("%s", array);
}

