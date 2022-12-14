/*
 ============================================================================
 Name        : ejercicio2-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio2-3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	//variables
	int numeroDeCliente;
	int edad;
	int temperaturaCorporal;
	char estadoCivil;
	char genero;
	int precioPorPasajero;
	int contadorViudoViejo;
	int contadorPasajeros;
	int flagSolteraMasJoven;
	int numeroSolteraMasJoven;
	int edadSolteraMasJoven;
	int totalSinDescuento;
	int contadorMas60;
	int totalConDescuento;

	char deseaContinuar;

	//inicializar
	precioPorPasajero = 600;
	deseaContinuar = 's';
	contadorViudoViejo = 0;
	contadorPasajeros = 0;
	flagSolteraMasJoven = 1;
	contadorMas60 = 0;

	while (deseaContinuar == 's' && contadorPasajeros <= 100) {
		contadorPasajeros++;
		printf("ingrese su numero de cliente \n");
		scanf("%d", &numeroDeCliente);

		do {
			printf("ingrese su edad \n");
			scanf("%d", &edad);
		} while (edad <= 17);

		if(edad > 60){
			contadorMas60++;
		}

		printf("ingrese su estado civil s para soltero c para casado o v viudo \n");
		scanf("%c", &estadoCivil); //c de char
		switch (estadoCivil) {
		case 's':
			estadoCivil = "soltero";
			break;
		case 'c':
			estadoCivil = "casado";
			break;
		case 'v':
			estadoCivil = "viudo";
			if(edad > 60){
				contadorViudoViejo++;
			}
			break;
		}


		do {
			printf("ingrese su temperatura corporal \n");
			scanf("%d", &temperaturaCorporal);
		} while (temperaturaCorporal <= 0);


		printf("ingrese su genero f para femenino m para masculino y o para no binario \n");
		scanf("c%", &genero); //c de char


		switch (genero) {
		case 'f':
			genero = "femenino";
			if(estadoCivil == "soltero"){
				if(flagSolteraMasJoven == 1){
					edadSolteraMasJoven = edad;
					numeroSolteraMasJoven = numeroDeCliente;
					flagSolteraMasJoven = 0;
				} else{
					if(edad < edadSolteraMasJoven){
						edadSolteraMasJoven = edad;
						numeroSolteraMasJoven = numeroDeCliente;
					}
				}
			}
			break;
		case 'm':
			genero = "masculino";
			break;
		case 'o':
			genero = "no binario";
			break;
		}

		printf("desea continuar (s/n) \n");
		scanf("%c", &deseaContinuar); //c de char
	}

	totalSinDescuento = contadorPasajeros * precioPorPasajero;//cantidad pasajeros * precio de cada pasajero
	totalConDescuento = totalSinDescuento * 0.75;//descuento del 25% a el total sin descuento
	printf("la cantidad de viudos con edad mayor a 60 es de: %d \n", contadorViudoViejo);
	printf("el numero de clinte %d y la edad %d de la mujer mas joven \n", numeroSolteraMasJoven, edadSolteraMasJoven);
	printf("el total sin descuento es de: %d", totalSinDescuento);

	if(contadorMas60 > (contadorPasajeros * 0.5)){
		printf("el total con descuento es de: %d \n", totalConDescuento);
	}


	return 0;

}
