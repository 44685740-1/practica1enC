/*
 ============================================================================
 Name        : ejercicio2-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio 2-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int i;
	int contadorPares;
	int contadorImpar;
	int maximoPar;
	int numeroMenor;
	int acumuladorPositivos;
	int acumuladorProductoNegativo;




	//inicializar
	contadorPares = 0;
	contadorImpar = 0;
	acumuladorPositivos = 0;
	acumuladorProductoNegativo = 0;


	for(i=0; i<3;i++){
		printf("ingrese un numero \n");
		scanf("%d", &numero);
		if(numero % 2 == 0){
			contadorPares++;
			if(i==0){
				maximoPar = numero;
			} else{
				if(numero>maximoPar){
					maximoPar = numero;
				}
			}
		} else{
			contadorImpar++;
		}

		if(i==0){
			numeroMenor = numero;
		} else{
			if(numero < numeroMenor){
				numero = numeroMenor;
			}
		}

		if(numero >= 0){
			acumuladorPositivos = acumuladorPositivos + numero;
		} else{


		}
	}

	printf("la cantidad de numero pares es de: %d \n", contadorPares);
	printf("la cantidad de numeros impares es de: %d \n", contadorImpar);
	printf("el menor numero ingresado es: %d \n", numeroMenor);
	printf("el mayor de los numeros pares es: %d \n", maximoPar);
	printf("la suma de los positivos es de: %d \n", acumuladorPositivos);
	printf("el producto de los numeros negativos es de: %d ", acumuladorProductoNegativo);

	return 0;
}