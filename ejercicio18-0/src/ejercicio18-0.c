/*
 ============================================================================
 Name        : ejercicio18-0.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio18-0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	//hay veces que mo pone el espacio en el explorador de archivos de eclipse
	//buscare en los directorio del didco duro por las dudas
	setbuf(stdout, NULL);
	int longitud;
	int cantidad;
	char nombreApellido[] = "Hola Carolina!!";
	longitud = strlen(nombreApellido);
	FILE *parch;
	//Se abre en modo lectura
	if ((parch = fopen("archivo.txt", "r")) == NULL) {
		//Si el modo anterior dio error el archivo
		if ((parch = fopen("archivo.txt", "w")) == NULL) {
			printf("\nEl archivo no puede ser abierto");
			exit(1);
		}
		//no existe, por lo tanto se crea
		cantidad =  fwrite(nombreApellido, sizeof(char), longitud, parch);
		if(cantidad != longitud){
			printf("no se pudo escribir correctamente");
		} else{
			printf("se pudo escribir correctamente");
		}
		fclose(parch);
	}
	return 0;
}
