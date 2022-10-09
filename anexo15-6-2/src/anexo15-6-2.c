/*
 ============================================================================
 Name        : anexo15-6.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description :  anexo15-6.c
 2-Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calcularMayorArray(int* arrayEnteros, int* mayorResultado);
int main(void) {
	setbuf(stdout, NULL);
	int arrayEnteros[11];
	int pMayorResultado;
	int retornoCalcularMayor;
	for(int i = 0; i< 10; i++){
		arrayEnteros[i] = i;
	}
	retornoCalcularMayor = calcularMayorArray(arrayEnteros, &pMayorResultado);
	if(retornoCalcularMayor != -1){
		printf("mayor: %d", pMayorResultado);
	}
	return 0;
}

/*
int calcularMayorArray(int* arrayEnteros, int* pMayorResultado){
	int mayor;
	int rtn;
	for(int i = 0; i < 10; i++){
		if(arrayEnteros[i] > arrayEnteros[i + 1]){
			mayor = arrayEnteros[i];
		}
	}

	*pMayorResultado = mayor;
	if(pMayorResultado != NULL){
		rtn = 0;
	} else{
		rtn = -1;
	}

	return rtn;
}
*/
//usando aritmetica de punteros
int calcularMayorArray(int* arrayEnteros, int* pMayorResultado){
	int mayor;
		int rtn;
		for(int i = 0; i < 10; i++){
			if(arrayEnteros[i] > arrayEnteros[i + 1]){
				mayor = *(arrayEnteros+i);
			}
		}

		*pMayorResultado = mayor;
		if(pMayorResultado != NULL){
			rtn = 0;
		} else{
			rtn = -1;
		}

		return rtn;
}
