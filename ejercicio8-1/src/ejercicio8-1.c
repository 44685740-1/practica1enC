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
	//hecho con retorno
	//se puede hacer con punteros tambien

	jugador unJugador;
	jugador retornoInicializar;
	jugador retornoCarga;

	retornoInicializar =  inicializarjugador(unJugador);
	retornoCarga = cargarJugador(unJugador);
	mostrarJugador(retornoCarga);
	calcularPromedioJugador(retornoCarga);

	return 0;
}

