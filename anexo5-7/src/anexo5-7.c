/*
 ============================================================================
 Name        : anexo5-7y5-8.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : anexo5-7y5-8
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void inicializarArray(int arraEdades[]);
float cargaDeArrayYpromedio(int arrayEdades[]);
int main(void) {
	setbuf(stdout, NULL);
	int arrayEdades[5];
	float retornoPromedio;
	inicializarArray(arrayEdades);
	retornoPromedio =  cargaDeArrayYpromedio(arrayEdades);
	printf("%f", retornoPromedio);
	return 0;

}

void inicializarArray(int arraEdades[]) {
	int i;
	for (i = 0; i < 5; i++) {
		arraEdades[i] = 0;
	}

	for (i = 0; i < 5; i++) {
		printf("%d\n", arraEdades[i]);
	}
}

float cargaDeArrayYpromedio(int arrayEdades[]){
	int i;
	float promedio;
	int acumulador;
	int edad;
	//inicializar
	acumulador = 0;

	for(i=0;i<5;i++){
		printf("ingrese una edad");
		scanf("%d", &edad);
		arrayEdades[i] = edad;
		printf("%d \n", arrayEdades[i]);
		//acumulador += arrayEdades[i];
	}


	for(i=0;i<5;i++){
		//printf("%d", arrayEdades[i]);
		acumulador += arrayEdades[i];
	}

	promedio = (float)acumulador / 5;//convierte el acumulador a float solo en esta linea
	return promedio;
}

