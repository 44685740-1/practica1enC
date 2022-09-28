/*
 * getNuemero.h
 *
 *  Created on: 19 sep. 2022
 *      Author: ahuit
 */

#ifndef GETNUEMERO_H_
#define GETNUEMERO_H_

//como no usamos array es el tp use esta validacion
//valida si lo ingresado por el usuario es numerico
//parametros:
// *pResultado = puntero que apunta a la direccion de memoria donde guardo el numero ingresado por el ususario si
// mensaje = puntero que apunta a un mensaje escrito en el main, el cual le indica al usuario que tiene que ingresar un numero
//mensajeError = puntero que apunta a un mensaje de error en el main
//minimo y maximo = son el rango en el que debe estar el numero ingresado
//reintentos = cantidad de veces que el usuario tiene la opurtinidad de ingrersar otro numero si se equivoco
//retorno:
// retorno = 0 si pudo ingresar un numero dentro del rango deseado en la cantidad de intentos permitidos
// retorno = -1 si no se pudo cumplir la condicion de arriba
// ademas paso por el puntero pResultado el numero ingresado en caso de que el retorno fue 0, sino me arroja basura
int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

#endif /* GETNUEMERO_H_ */
