/*
 * ordenarArray.c
 *
 *  Created on: 16 sep. 2022
 *      Author: ahuit
 */
//paso el array como puntero en vez de con el corchete
int ordenarArray(int *array, int len) {
	int flagSwap;
	int i;
	int retorno = -1;
	int buffer;

	if (len > 0) {
		do {
			flagSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (array[i] > array[i + 1]) {//hay que cambiar este signo > si queres ordenar de mayor a menor o al reves
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

