/*
 ============================================================================
 Name        : ejemploMalloc.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description :  ejemploMalloc.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *a;
	int *pAux;
	a = (int*) malloc(sizeof(int) * 20);
	if( a != NULL){
		pAux = (int*) realloc(a, (sizeof(int)) * 200);
	}

	a = pAux;
	if(a != NULL){
		for( int i = 0; i < 200; i++){
			*(a) = i;
			printf("%d", *a);
		}
	}

	free(a);
	return 0;
}
