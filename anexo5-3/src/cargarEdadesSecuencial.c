/*
 * cargarEdadesSecuencial.c
 *
 *  Created on: 13 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include "inicializarArray.h"
void cargaEdadesSecuencial(int arrayEdades[]) {
	int i;
	int edades;

	for (i = 0; i < 5; i++) {
		printf("\ningrese una edad \n");
		fflush(stdin);
		scanf("%d", &edades);
		arrayEdades[i] = edades;
	}

	for (i = 0; i < 5; i++) {
		printf("%d", arrayEdades[i]);
	}
}

