/*
 ============================================================================
 Name        : ejercicio17-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio17-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirArray(int array[], int* len);
int* removeArray(int* array, int* len, int numeroEliminar);
int main(void) {
	setbuf(stdout, NULL);
	int* array;
	int numeroEliminar;
	int len = 5;

	array = (int*) malloc(sizeof(int) * 5);
	if(array != NULL){
		array[0] = 5;
		array[1] = 4;
		array[2] = 2;
		array[3] = 1;
		array[4] = 3;
	}


	imprimirArray(array, &len);

	printf("\ningrese el valor del array que desea eliminar\n");
	scanf("%d", &numeroEliminar);
	array = removeArray(array, &len, numeroEliminar);
	imprimirArray(array, &len);

	return 0;
}




int* removeArray(int* array, int* len, int numeroEliminar){
	int* arrayAuxiliar;
	int indice;
	arrayAuxiliar = (int*) malloc(sizeof(int) * 4);
	for(int i = 0; i < *len; i++){
		if(array[i] != numeroEliminar){
			indice = i;
			break;
		}
	}


	*len = *len -1;
	return arrayAuxiliar;
}







void imprimirArray(int* array, int* len){
	for(int i = 0; i < *len; i++){
		printf("%d\n", *(array + i));
	}
}
