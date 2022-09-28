/*
 * getNuemero.c
 *
 *  Created on: 19 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int ret;
	int num;
	while (reintentos > 0) {
		printf(mensaje);
		if (scanf("%d", &num) == 1) {//usamos el retono del scanf para saber si pudo o no guardar un entero
			if (num <= maximo && num >= minimo)
				break;
		}
		fflush(stdin);//windows

		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;//asignamos el numero al puntero en caso que el retorno es 0
	}


	return ret;
	}


