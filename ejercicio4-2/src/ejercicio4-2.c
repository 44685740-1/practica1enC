/*
 ============================================================================
 Name        : ejercicio4-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio4-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validacionCelcius.h"
#include "validacionFahrenheit.h"
#include "tranformacionCelcius.h"
#include "transfotmacionFahrenheit.h"
int main(void) {
	setbuf(stdout, NULL);
	int temperatura;
	char tipoTemperatura;
	int retornoValidacionCelcius;
	int retornoValidacionfahrenheit;
	int retornoTransformacioCelcius;
	int retornoTransformacionFahrenheit;
	printf("indique c/f si va a ingresar temperatura en celcius y fahrenheit");
	scanf("%c", &tipoTemperatura);

	if (tipoTemperatura ==  'c') {
		printf("ingrese la temperatura en celcius");
		scanf("%d", &temperatura);
		retornoValidacionCelcius = validacionCelcius(temperatura);
		if(retornoValidacionCelcius == 0){
			retornoTransformacioCelcius = transformacionCelcius(temperatura);
			printf("%d", retornoTransformacioCelcius);
		} else{
			printf("fuera del rango");
		}
	} else {
		if (tipoTemperatura == 'f') {
			printf("ingrese la temperatura en fahrenheit");
			scanf("%d", &temperatura);
			retornoValidacionfahrenheit = validacionFahrenheit(temperatura);
			if(retornoValidacionfahrenheit == 0){
				retornoTransformacionFahrenheit = transformacionFahrenheit(temperatura);
				printf("%d", retornoTransformacionFahrenheit);
			} else{
				printf("fuera de rango");
			}
		}
	}

	return 0;
}
