/*
 * recorridoNumerosPosicionImpar.c
 *
 *  Created on: 8 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#define contadorVueltas 5
void recorridoNumerosPosicionImpar(int arrayNumerosPosicionImpar[], int contadorPosicionImpar){
	int i;
	printf("recorrido numeros en posiciones impares");
	for (i = 0; i < contadorPosicionImpar; i++){
		printf("%d", arrayNumerosPosicionImpar[i]);
	}
}
