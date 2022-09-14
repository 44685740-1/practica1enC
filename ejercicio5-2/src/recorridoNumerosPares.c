/*
 * recorridoNumerosPares.c
 *
 *  Created on: 8 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#define contadorVueltas 5

void recorridoNumerosPares(int arrayNumerospares[], int contadorNumerospar){
	int i;
	printf("recorrido nuemros pares");
	for (i = 0; i < contadorNumerospar; i++){
		printf("%d", arrayNumerospares[i]);
	}
}
