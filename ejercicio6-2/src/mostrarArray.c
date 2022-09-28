/*
 * mostrarArray.c
 *
 *  Created on: 16 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
//paso el array como puntero
void mostrarArray(int *array, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d", array[i]);
	}
}

