/*
 ============================================================================
 Name        : ejercicio5-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define contadorVueltas 3
int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int i;
	int acumuladorPositivos;
	int contadorPositivos;
	int promedioPositivos;
	int menorNegativo;
	int acumuladorAntecesor;
	//inicializar
	acumuladorPositivos = 0;
	contadorPositivos = 0;
	acumuladorAntecesor = 0;
	for (i = 0; i < contadorVueltas; i++) {
		do {
			printf("ingrese un numero \n");
			scanf("%d", &numero);
		} while (numero == 0);

		if (numero >= 1) {
			contadorPositivos++;
			acumuladorPositivos += numero;
		} else {
			//si o si es negativo porque no es 0 y tampoco es mayor o igual a 1
			if (i == 1) {
				menorNegativo = numero;
			} else {
				if (numero < menorNegativo) {
					menorNegativo = numero;
				}
			}

		}

	}
	/*
	for(i = menorNegativo + 1; i < 0; i++){
		printf("%d", i);
		acumuladorAntecesor += i;
	}
	*/

	for(i=0; i > menorNegativo ;i--){
		printf("%d", i);
		acumuladorAntecesor += i;
	}


	promedioPositivos = acumuladorPositivos / contadorPositivos;
	printf("el promedio de los positivos es: %d \n", promedioPositivos);
	printf("el menor de los negativos es: %d", menorNegativo);
	//suma de los antecesores de el menor negativo
	printf("la suma de los antecesores del menor negativo es: %d", acumuladorAntecesor);
	return 0;
}
