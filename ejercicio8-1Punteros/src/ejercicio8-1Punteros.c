/*
 ============================================================================
 Name        : ejercicio8-1Punteros.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio8-1Punteros.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargarMostrarPromedio.h"
int main(void) {
	setbuf(stdout, NULL);
	jugador unJugador;
	jugador* pUnJugador;
	pUnJugador = &unJugador;
	cargarJugador(unJugador, pUnJugador);
	mostrarJugador(*pUnJugador);
	calcularPromedioJugador(*pUnJugador);
	return 0;
}
