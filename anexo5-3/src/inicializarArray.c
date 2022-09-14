/*
 * inicializarArray.c
 *
 *  Created on: 13 sep. 2022
 *      Author: ahuit
 */

void inicializarArray(int arrayEdades[]) {
	int i;

	for (i = 0; i < 5; i++) {
		arrayEdades[i] = 0;
	}

	for (i = 0; i < 5; i++) {
		printf("%d", arrayEdades[i]);
	}

}

