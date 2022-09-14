/*
 * recorridoNumerosIngresados.c
 *
 *  Created on: 8 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#define contadorVueltas 5
void recorridoNumerosIngresados(int arrayNumeroIngresado[]){
	int i;
	printf("numeros ingresados");
	for (i = 0; i < contadorVueltas; i++){
		printf("%d", arrayNumeroIngresado[i]);
	}
}


