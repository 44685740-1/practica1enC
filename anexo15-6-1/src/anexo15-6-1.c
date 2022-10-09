/*
 ============================================================================
 Name        : anexo15-6-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : anexo15-6-1.c
 1-Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido,
por el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.
Versión 2. Utilizar aritmetica de punteros

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void remplazarCaracterCadena(char* array, char caracter1, char caracter2);
int main(void) {
	setbuf(stdout, NULL);
	char array[7];
	char caracter1;
	char caracter2;

	caracter1 = 'a';
	caracter2 = 'x';
	printf("ingrese el string\n");
	scanf("%s", array);
	remplazarCaracterCadena(array, caracter1, caracter2);
	return 0;
}
/*
void remplazarCaracterCadena(char* array, char caracter1, char caracter2){

	for(int i = 0; i < 7; i++){
		if(array[i] == caracter1){
			array[i] = caracter2;
		}
	}

	printf("%s\n", array);
}
*/
//usando aritmetica de punteros
void remplazarCaracterCadena(char* array, char caracter1, char caracter2){

	for(int i = 0; i < 7; i++){
		if(array[i] == caracter1){
			*(array+i) = caracter2;
		}
	}
	printf("%s\n", array);
}
