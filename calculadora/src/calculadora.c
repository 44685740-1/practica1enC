/*
 ============================================================================
 Name        : calculadora.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : calculadora-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validacionDividirDosNumeros.h"
#include "dividirDosEnteros.h"
#include  "porcentaje.h"
int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	char operacion;
	int validacionDivision;
	int division;
	int suma;
	int resta;
	int multiplicacion;
	int resto;
	int porcentajeResultado;

	printf("ingrese el primer numero\n");
	scanf("%d", &numero1);
	do {
		printf("ingrese la operacion\n");
		fflush(stdin); //windows, cleans buffer
		scanf("%c", &operacion);
	} while (operacion != '+' && operacion != '-' && operacion != '*'
			&& operacion != '/' && operacion != '%' && operacion != 'p');
	printf("ingrese el segundo numero\n");
	fflush(stdin); //windows, cleans buffer
	scanf("%d", &numero2);

	//logica funciones

	switch (operacion) {
	case '/':
		validacionDivision = validacionDividirDosNumeros(numero1, numero2);
		if (validacionDivision == -1) {
			printf("error");
		} else {
			division = dividirDosEnteros(numero1, numero2);
			printf("%d", division);
		}
		break;
	case '+':
		suma = numero1 + numero2;
		printf("%d", suma);
		break;
	case '-':
		resta = numero1 - numero2;
		printf("%d", resta);
		break;
	case '*':
		multiplicacion = numero1 * numero2;
		printf("%d", multiplicacion);
		break;
	case '%':
		resto = numero1 % numero2;
		printf("%d", resto);
		break;
	case 'p':
		porcentajeResultado = porcentajeDosEnteros(numero1,  numero2);
		printf("%d porciento", porcentajeResultado);
		break;
	}
	return 0;
}
