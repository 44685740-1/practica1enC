/*
 * menu.c
 *
 *  Created on: 9 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>

void menuDeOpciones(void) {
	setbuf(stdout, NULL);
	int opciones;
	//menu de opciones

	printf(
			"opciones: \n 1-Inicializar \n 2-Cargar \n 3-Mostrar \n 4-Calcular Promedio \n 5-Ordenar \n 6-salir");
	do {
		fflush(stdin);
		printf("\n ingrese la opcion que desea \n");
		fflush(stdin);
		scanf("%d", &opciones);
	} while (opciones < 1 || opciones > 6);

	switch (opciones) {
	case 1:
		printf("Ud. ha seleccionado lo opción 1-Inicializar");
		break;
	case 2:
		printf("Ud. ha seleccionado lo opción 2-cargar");
		break;
	case 3:
		printf("Ud. ha seleccionado lo opción 3-mostrar");
		break;
	case 4:
		printf("Ud. ha seleccionado lo opción 4-Calcular promedio");
		break;
	case 5:
		printf("Ud. ha seleccionado lo opción 5-Ordenar");
		break;
	case 6:
		printf("salida");
		break;
	}
}

