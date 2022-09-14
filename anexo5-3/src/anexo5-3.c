/*
 ============================================================================
 Name        : anexo5-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : anexo5-3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inicializarArray.h"
#include "cargarEdadesSecuencial.h"
int main(void) {
	setbuf(stdout, NULL);
	int arrayEdades[5];
	inicializarArray(arrayEdades);
	cargaEdadesSecuencial(arrayEdades);
	return 0;
}
