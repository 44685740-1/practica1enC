/*
 ============================================================================
 Name        : ejercicio15-6.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio15-6.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	setbuf(stdout, NULL);
	char arrayUno[10];
	char arrayDos[5];
	int contador;
	contador = 0;


	printf("ingrese el primer array\n");
	fgets(arrayUno, sizeof(arrayUno), stdin);
	arrayUno[strlen(arrayUno)-1]='\n';
	arrayUno[strlen(arrayUno)-1]='\0';

	fflush(stdin);//windows hay que limpiar el stdin -> buffer antes de hacer otro fgets, sino te toma el valor que ya fue escrito en la consola

	printf("ingrese el segundo array\n");
	fgets(arrayDos, sizeof(arrayDos), stdin);
	arrayDos[strlen(arrayDos)-1]='\n';
	arrayDos[strlen(arrayDos)-1]='\0';


	for(int i = 0; i < strlen(arrayUno); i++){
		for(int j = 0; j < strlen(arrayDos); j++){
			if(arrayDos[j] == arrayUno[i]){
				contador++;
			}
	    }
	}

	if(contador == strlen(arrayDos)){
		printf("esta contenido");
	} else{
		printf("no esta contenido");
	}




	return 0;
}



