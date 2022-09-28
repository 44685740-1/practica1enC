/*
 * ordenarArray.c
 *
 *  Created on: 16 sep. 2022
 *      Author: ahuit
 */
int ordenarArrayCrecientePositivos(int *array, int len) {
	int flagSwap;
	int i;
	int retorno = -1;
	int buffer;

	if (len > 0) {
		do {
			flagSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (array[i] > array[i + 1]) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				}
			}
		} while (flagSwap);
	}
	retorno = 0;
	return retorno;
}


/////

int ordenarArrayDecrecienteNegativos(int *array, int len) {
	int flagSwap;
	int i;
	int retorno = -1;
	int buffer;

	if (len > 0) {
		do {
			flagSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (array[i] > array[i + 1]) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				}
			}
		} while (flagSwap);
	}
	retorno = 0;
	return retorno;
}
