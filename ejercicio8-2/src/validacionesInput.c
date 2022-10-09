/*
 * validacionesInput.c
 *
 *  Created on: 7 oct. 2022
 *      Author: ahuit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000//se usa para utn_get_alfanumerico

//utn get int
 static int esNumerica(char *cadena) {
 int i = 0;
 int retorno = 1;
 if (cadena != NULL && strlen(cadena) > 0) {
 while (cadena[i] != '\0') {
 if (cadena[i] < '0' || cadena[i] > '9') {
 retorno = 0;
 break;
 }
 i++;
 }
 }
 return retorno;
 }

 static int getFloat(int *pResultado) {
 int ret = -1;
 char buffer[64];
 fgets(buffer, sizeof(buffer), stdin);
 buffer[strlen(buffer) - 1] = '\n';
 buffer[strlen(buffer) - 1] = '\0';
 if (esNumerica(buffer)) {
 *pResultado = atoi(buffer);
 ret = 1;
 }
 return ret;
 }

 int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
 int minimo, int maximo, int reintentos) {
 int bufferInt;
 int retorno = -1;
 while (reintentos > 0) {
 reintentos--;
 printf("%s", mensaje);
 if (getFloat(&bufferInt) == 1) {
 if (bufferInt >= minimo && bufferInt <= maximo) {
 *pResultado = bufferInt;
 retorno = 0;
 break;
 }
 }
 printf("%s", mensajeError);
 }
 return retorno;
 }


//utn get alfa numerico
 int esNumeroflotante(char *valorReemplazoResultado) {
 int i = 0;
 int retorno = 0;
 int contadorPunto;
 contadorPunto = 0;
 if (valorReemplazoResultado != NULL && strlen(valorReemplazoResultado) > 0) {
 for (i = 0; valorReemplazoResultado[i] != '\0'; i++) {

 if (i == 0 && (valorReemplazoResultado[i] == '-' || valorReemplazoResultado[i] == '+')) {
 continue;
 }
 if (valorReemplazoResultado[i] < '0'  || valorReemplazoResultado[i] > '9') {
 if (valorReemplazoResultado[i] == '.' && contadorPunto == 0) {
 contadorPunto++;
 } else {
 retorno = -1;
 break;
 }
 }
 }
 }


 return retorno;
 }


 int recogerNumeroflotante(float *resultado) {
 int retorno = 0;
 char valorReemplazo[500];

 fgets(valorReemplazo, sizeof(valorReemplazo), stdin);
 valorReemplazo[strlen(valorReemplazo) - 1] = '\n';
 valorReemplazo[strlen(valorReemplazo) - 1] = '\0';

 int retornoEsNumero = esNumeroflotante(valorReemplazo);


 if (retornoEsNumero == 0) {
 *resultado = atof(valorReemplazo);
 retorno = 1;
 }
 return retorno;
 }




 int get_UTN_ValidacionNumeroflotante(float *resultado, char mensaje[],
 char mensajeFalla[], int numeroMinimo, int numeroMaximo,
 int repeticiones) {
 float valorReemplazo;
 int retorno = 0;

 if (resultado != NULL && mensaje != NULL && mensajeFalla != NULL
 && numeroMinimo <= numeroMaximo && repeticiones >= 0) {

 while (repeticiones > 0) {
 printf("%s", mensaje);
 if (recogerNumeroflotante(&valorReemplazo) == 1) {

 if (valorReemplazo >= numeroMinimo
 && valorReemplazo <= numeroMaximo) {

 repeticiones = -1;
 retorno = 1;
 } else {
 printf("%s. numero de intentos %d", mensajeFalla,
 repeticiones);
 repeticiones--;
 }

 }

 }
 if (repeticiones == 0) {
 retorno = -1;
 } else {
 retorno = 1;
 *resultado = valorReemplazo;
 }
 }

 return retorno;
 }



//utn get string
 int getString(char *string, int len) {
 int retorno = -1;
 char bufferString[LEN];

 if (string != NULL && string > 0) {
 fflush(stdin);
 if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
 if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
 == '\n') {
 bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
 '\0';
 }
 if (strnlen(bufferString, sizeof(bufferString)) <= len) {
 strncpy(string, bufferString, len);
 retorno = 0;
 }
 }
 }
 return retorno;
 }

 int isAlfaNumeric(char *string, int len) {
 int i = 0;
 int ret = 0;
 if (string != NULL && strlen(string) > 0) {
 while (string[i] != '\0') {
 if ((string[i] < '0' || string[i] > '9')
 && (string[i] < 'a' || string[i] > 'z')
 && (string[i] < 'A' || string[i] > 'Z')
 && string[i] != ' ' && string[i]!='.') {
 ret = -1;
 break;
 }
 i++;
 }
 }
 return ret;
 }

 int getAlfaNumeric(char *pResult, int len) {
 int ret = -1;
 char option[LEN];
 if (pResult != NULL) {
 if (getString(option, sizeof(option)) == 0
 && isAlfaNumeric(option,sizeof(option)) == 0) {
 if (strnlen(option, sizeof(option)) <= len) {
 strncpy(pResult, option, len);


 ret = 0;

 }

 }

 }
 return ret;
 }

 int utn_getAlfaNumeric(char *pResult, char *message, char *ErrorMessage,
 int retry) {
 int ret;
 char bufferString[LEN];
 while (retry > 0) {
 printf(message);
 if (getAlfaNumeric(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString))<LEN) {

 ret = 0;
 break;
 }
 fflush(stdin);
 retry--;
 printf(ErrorMessage);
 }
 if (retry == 0) {
 ret = -1;
 } else {
 ret = 0;
 strncpy(pResult,bufferString,LEN);
 }
 return ret;
 }



//utn get char
int utnGetChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int retorno;
	char bufferChar;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);//windows
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo){
				*pResultado = bufferChar;
				retorno = 0;
				break;
			} else{
				printf("%s", mensajeError);
				reintentos--;
			}
		} while(reintentos >= 0);
	}
	return retorno;
}






/*
static int productoObtenerID(void){
	static int incrementalID = 1000;
	return incrementalID++;
}

void prueba(void){
	printf("ID = %d\n", productoObtenerID());
}
*/





