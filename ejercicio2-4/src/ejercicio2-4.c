/*
 ============================================================================
 Name        : ejercicio2-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio2-4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//nos permite saber si el caraccter es mayuscula o minuscula
int main(void) {
	setbuf(stdout, NULL);
	char caraccter;
	int i;
	int contadorp;

	//inicializar
	contadorp = 0;

	for(i=0;i<5;i++){
		printf("ingrese una letra cualquiera \n");
		scanf("c%", &caraccter);//c de caraccter
		if(caraccter == 'p'){
			contadorp++;
		}
	}
	printf("se ingresaron %d letras p minuscula", contadorp);
	return 0;
}
