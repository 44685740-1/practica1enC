/*
 * getString.c
 *
 *  Created on: 18 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  getNumero(char *MSJ, char *ERROR_MSJ, int *pResultado, int maximo,
		int minimo, int reintentos) {
	int ret;
	int num;
	while (reintentos > 0) {
		printf("%s", MSJ);
		if (scanf("%d", &num) == 1) {
			if (num <= maximo && num >= minimo)
				break;
		}
		reintentos--;
		printf("%s", ERROR_MSJ);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}



