/*
 * inicializarArray.c
 *
 *  Created on: 16 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
void incializarArray(int* array, int len){
	for(int i=0; i<len;i++){
		array[i] = 0;
		printf("%d", array[i]);
	}
}

