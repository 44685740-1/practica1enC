/*
 * toLowerToUpper.c
 *
 *  Created on: 18 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void toUpper(char *array, int len) {
	for (int i = 0; i < len; i++) {
		array[i] = toupper(array[i]);
	}
	printf("con la funcion: \n %s", array);
}

void toLower(char *array, int len) {
	for (int i = 0; i < len; i++) {
		array[i] = tolower(array[i]);
	}
	printf("con la funcion: \n %s", array);
}
