/*
 ============================================================================
 Name        : ejercicio8-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio8-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargarMostrarPromedio.h"


int main(void) {
	setbuf(stdout, NULL);
	jugador unJugador;
	inicializarjugador(unJugador);
	cargarJugador(unJugador);
	mostrarJugador(unJugador);
	calcularPromedioJugador(unJugador);

	return 0;
}

