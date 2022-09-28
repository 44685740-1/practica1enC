/*
 * cargarMostrarPromedio.h
 *
 *  Created on: 24 sep. 2022
 *      Author: ahuit
 */

#ifndef CARGARMOSTRARPROMEDIO_H_
#define CARGARMOSTRARPROMEDIO_H_
typedef struct{
	char nombre[30];
	int goles;
	int partidos;
	float promedio;
}jugador;
void inicializarjugador(jugador unJugador);
void cargarJugador(jugador unJugador);
void mostrarJugador(jugador unJugador);
void calcularPromedioJugador(jugador unJugador);

#endif /* CARGARMOSTRARPROMEDIO_H_ */
