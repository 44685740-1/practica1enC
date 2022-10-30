/*
 * validacionesInput.h
 *
 *  Created on: 24 oct. 2022
 *      Author: ahuit
 */

#ifndef VALIDACIONESINPUT_H_
#define VALIDACIONESINPUT_H_

//utn get string
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);

//utn get name
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido);


//utn signed int
int utn_getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int isValidNumber(char* stringRecibido);
int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int reintentos, int* input);
int isValidSignedNumber(char* stringRecibido);

//utn get float
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);

//utn get telefono
int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidTelephone(char* stringRecibido);

//utn get DNI
int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidDNI(char* stringRecibido);

//utn get cuit
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input);
int isValidCUIT(char* stringRecibido);

//utn get email
int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidEmail(char* stringRecibido);

//utn get texto
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidTexto(char* stringRecibido);

//utn get alfa numerico
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidAlphanumeric(char* stringRecibido);

//utn get char
int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidChar(char charRecibido);

//utn get sexo
int utn_getSexo(char* msg,char* msgError,char* resultado);
#endif /* VALIDACIONESINPUT_H_ */
