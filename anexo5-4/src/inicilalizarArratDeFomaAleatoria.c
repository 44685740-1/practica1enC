/*
 * inicilalizarArratDeFomaAleatoria.c
 *
 *  Created on: 13 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
void inicilalizarArratDeFomaAleatoria(int arrayEdades[]){
	/*
	muestra cada elemto del array diciendo en que posicion esta
	int i;
	int edad;
	for(i=1; i<6; i++){
		printf("ingrese la edad \n");
		scanf("%d", &edad);
		arrayEdades[i] = edad;
	}

	for(i=1; i<6; i++){
		printf("%d", arrayEdades[i]);
		printf(" posicion: %d \n", i);

	}
	*/

	int i;
	int posicion;
	char continuar;
	int acumulador;
	int promedio;
	//inicilalizar
	acumulador = 0;
	for(i=0;i<5;i++){
		//ya esta inicializado el array
		do{
			printf("ingrese la posicion donde va a ingresar la edad");
			scanf("%d", &posicion);
			printf("ingrese la edad");
			fflush(stdin);
			scanf("%d", &arrayEdades[posicion]);
			printf("desea seguir ingresando datos s/n");
			fflush(stdin);
			scanf("%c", &continuar);
		} while(continuar == 's');
		i=6;
	}

	//recorro el array para que lo muestre
	for(i=0;i<5;i++){
		printf("%d", arrayEdades[i]);
		acumulador += arrayEdades[i];
	}

	promedio = acumulador / 5;
	printf("el promedio del array cargado de forma aleatoria es: %d", promedio);//por retorno seria lo mismo nada mas que: return promedio
}

