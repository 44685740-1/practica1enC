/*
 ============================================================================
 Name        : ejercicio17-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio17-3.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrayPush(int *array, int len, int valor, int indice);
int main(void) {
	setbuf(stdout, NULL);
	int *array;
	int indice;
	int valor;
	array = (int*) malloc(sizeof(int) * 4);
	if(array != NULL){
		array[0] = 1;
		array[1] = 5;
		array[2] = 4;
		array[3] = 9;
	}


	for(int i = 0; i < 4; i++){
		printf("%d", array[i]);
	}

	printf("\nindique el indice donde quiere hacer el push");
	scanf("%d", &indice);
	printf("\ningrese el valor con el cual queire hacer le push\n");
	scanf("%d", &valor);

	arrayPush(array, 4, valor, indice);
	return 0;
}

void arrayPush(int *array, int len, int valor, int indice){
	int *pAuxArray;
	if(array != NULL){
		pAuxArray = (int*) realloc(array, (sizeof(int)) * 5);
	}

	if(pAuxArray != NULL){
		array = pAuxArray;
	}
	for(int i = 0; i < 4; i++){
		if(i == indice){
			do{
				array[i + 1] = array[i];
			} while(i < 4);
		}
	}

	for(int i = 0; i < 5; i++){
			printf("%d", array[i]);
		}


}
