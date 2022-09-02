/*
 ============================================================================
 Name        : ejercicio2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio1-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int numero3;

	//%d es la d de digito ya que hablamos de una variable que es un numero entero
	printf("ingrese el primer numero \n");
	scanf("%d", &numero1);
	printf("ingrese le segundo numero \n");
	scanf("%d", &numero2);
	printf("ingrese el tercer numero \n");
	scanf("%d", &numero3);

	if(numero1 > numero2 && numero1 > numero3){
		printf("el primero es el mayor %d", numero1);
	} else{
		if(numero2 > numero1 && numero2 > numero3){
			printf("el segundo es el mayor %d", numero2);
		} else{
			//si o si el tercero es el mas grande
			printf("el tercero es el mas grande %d", numero3);
		}
	}

	return 0;
}
