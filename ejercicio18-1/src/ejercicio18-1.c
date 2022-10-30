/*
 ============================================================================
 Name        : ejercicio18-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio18-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// importante /////
/// el archivo fue creado con el nombre nombres.txt ///
// buscar en disco //
//fucnion generica para abrir un archivo y copiarle un array
int escribirNombreTXT(char* nombres, char* path);
int main(void) {
	setbuf(stdout, NULL);
	char nombreArchivo [] = "nombre.txt";
	char arrayNombres [] = "Ahuitz Caracciolo Carlos Sanchez Carolina Gangi francisco Caracciolo Sebastian Climent";
	escribirNombreTXT(arrayNombres, nombreArchivo);
	return 0;
}

//path es simplemente el nombre del archivo que lo paso por paramentro
int escribirNombreTXT(char* arraynombres, char* path){
	int longitud;
		int cantidad;
		longitud = strlen(arraynombres);
		int retorno;
		FILE *parch;
		//Se abre en modo lectura
		if ((parch = fopen(path, "r")) == NULL) {
			//Si el modo anterior dio error el archivo
			if ((parch = fopen(path, "w")) == NULL) {
				retorno = -1;
				exit(1);
			}
			//no existe, por lo tanto se crea
			cantidad =  fwrite(arraynombres, sizeof(char), longitud, parch);
			if(cantidad != longitud){
				retorno = -1;
			} else{
				retorno = 0;
			}
			fclose(parch);
		}

		return retorno;
}
