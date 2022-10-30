/*
 ============================================================================
 Name        : ejercicio18-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	setbuf(stdout, NULL);
	FILE *pArchivo;
	int cantidad;
	int longitud = 5;
	int arrayCincoNumeros[4];
	arrayCincoNumeros[0] = 1;
	arrayCincoNumeros[1] = 2;
	arrayCincoNumeros[2] = 3;
	arrayCincoNumeros[3] = 4;
	arrayCincoNumeros[4] = 5;

	if ((pArchivo = fopen("archivoCincoNumeros.bin", "rb")) == NULL) {
		//Si el modo anterior dio error el archivo
		if ((pArchivo = fopen("archivoCincoNumeros.bin", "wb")) == NULL) {
			printf("\nEl archivo no puede ser abierto");
			exit(1);
		}
		//no existe, por lo tanto se crea
		cantidad = fwrite(arrayCincoNumeros, sizeof(int), longitud, pArchivo);
		if (cantidad != longitud) {
			printf("no se pudo escribir correctamente");
		} else {
			printf("se pudo escribir correctamente");
		}
		fclose(pArchivo);
	}

	if ((pArchivo = fopen("archivoCincoNumeros.bit", "rb")) == NULL) {
		printf("No se pudo abrir el archivo");
		exit(1);
	}
	while (!feof(pArchivo)) {

		cantidad = fread(arrayCincoNumeros, sizeof(int), 5, pArchivo);
		if (cantidad != 4) {
			if (feof(pArchivo))
				break;
			else {
				printf("No leyo el ultimo registro");
				break;
			}
		}
		printf("numero: %d %d %d %d %d", arrayCincoNumeros[0],
				arrayCincoNumeros[1], arrayCincoNumeros[2],
				arrayCincoNumeros[3], arrayCincoNumeros[4]);

	}
	fclose(pArchivo);

	return 0;
}
