/*
 ============================================================================
 Name        : FuncionSumarDosEnteros.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : FuncionSumarDosEnteros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//prototipo como se lee de arriba a abajo hay que poner esto para que compile bien y conozca las variables
//mas adelante haremos nuestras propias librerias en otros archivos y utilizaremos el #include
int SumarDosEnteros(int numero1, int numero2);
int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	int resultado;
	printf("ingrese el primer numero\n");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero\n");
	scanf("%d", &numero2);
	resultado = SumarDosEnteros(numero1,numero2);
	printf("%d",resultado);
	return 0;
}

int SumarDosEnteros(int numero1, int numero2){
	setbuf(stdout, NULL);
	int suma;
	suma = numero1 + numero2;
	return suma;
}




