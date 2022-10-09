/*
 * cargarMostrarPromedio.c
 *
 *  Created on: 29 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargarMostrarPromedio.h"

void cargarJugador(jugador unJugador, jugador* pUnJugador) {
	printf("ingrese el nombre del jugador\n");
	fgets(unJugador.nombre, sizeof(unJugador.nombre), stdin);
	unJugador.nombre[strlen(unJugador.nombre) - 1] = '\n';
	unJugador.nombre[strlen(unJugador.nombre) - 1] = '\0';
	printf("ingrese la catidad de goles que metio\n");
	scanf("%d", &unJugador.goles);
	printf("ingrese la cantidad de partidos que jugo\n");
	scanf("%d", &unJugador.partidos);
	*pUnJugador = unJugador;
}

void mostrarJugador(jugador pUnJugador) {
	printf("el nombre del jugador es %s \n", pUnJugador.nombre);
	printf("metio %d goles\n", pUnJugador.goles);
	printf("disputo %d partidos\n", pUnJugador.partidos);
}

void calcularPromedioJugador(jugador pUnJugador) {
	pUnJugador.promedio = (float) pUnJugador.goles / pUnJugador.partidos;
	printf("el promedio de goles es %.2f", pUnJugador.promedio);
}
