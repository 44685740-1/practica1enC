/*
 ============================================================================
 Name        : ejercicio1-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio 1-3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numero1;
	int numero2;
	int numero3;

	printf("ingrese el primer numero \n");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero \n");
	scanf("%d", &numero2);
	printf("ingrese el tercer numero \n");
	scanf("%d", &numero3);



	if((numero1 > numero2 && numero1 < numero3) || (numero1 < numero2 && numero1 > numero3)){
		printf("el primero es el numero del medio, %d", numero1);
	} else{
		if((numero2 > numero1 && numero2 < numero3) || (numero2 < numero1 && numero2 > numero3)){
			printf("el segundo numero es el del medio, %d", numero2);
		} else{
			if((numero3 > numero1 && numero3 < numero2) || (numero3 < numero1 && numero3 > numero2)){
				printf("el tercer numero es el del medio, %d", numero3);
			} else{
				//no hay ninguno que sea el del medio porque ya vimos las tres posibilidades
				printf("no hay numero del medio");
			}
		}
	}
	return 0;
}
