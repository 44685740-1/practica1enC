/*
 * promedioArrayEdad.c
 *
 *  Created on: 13 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
int promedioArrayEdad(int arrayEdad[], float* pPromedio){
	int i;
	int acumulador;
	int retorno;
	float promedio;

	//inicializar
	acumulador = 0;
	for(i=0;i<5;i++){
		printf("ingrese la edad");
		scanf("%d", &arrayEdad[i]);
		acumulador += arrayEdad[i];
	}

	promedio = (float)acumulador / 5;
	printf(" antes %f \n", promedio);
	*pPromedio = promedio;
	printf(" despues %f", *pPromedio);
	if(promedio > 0){
		retorno = 0;
	} else{
		retorno = -1;
	}

	return retorno;
}

