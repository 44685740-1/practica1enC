/*
 * cargarMostrarPromedio.h
 *
 *  Created on: 29 sep. 2022
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
void cargarJugador(jugador unJugador, jugador* pUnJugador);
void mostrarJugador(jugador pUnJugador);
void calcularPromedioJugador(jugador pUnJugador);
#endif /* CARGARMOSTRARPROMEDIO_H_ */
