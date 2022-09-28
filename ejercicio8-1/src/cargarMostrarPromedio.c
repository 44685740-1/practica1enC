/*
 * cargarMostrarPromedio.c
 *
 *  Created on: 24 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargarMostrarPromedio.h"


void inicializarjugador(jugador unJugador){
	unJugador.goles = -1;
	unJugador.partidos = -1;
	unJugador.promedio = -1;
	for(int i = 0; i < sizeof(unJugador.nombre); i++){
		unJugador.nombre[i] = 'a';
	}
}
void cargarJugador(jugador unJugador){
	printf("ingrese el nombre del jugador\n");
	fgets(unJugador.nombre, sizeof(unJugador.nombre), stdin);
	unJugador.nombre[strlen(unJugador.nombre)-1]='\n';
	unJugador.nombre[strlen(unJugador.nombre)-1]='\0';
	printf("ingrese la catidad de goles que metio\n");
	scanf("%d", &unJugador.goles);
	printf("ingrese la cantidad de partidos que jugo\n");
	scanf("%d", &unJugador.partidos);
}


void mostrarJugador(jugador unJugador){

	printf("el nombre del jugador es %s \n", unJugador.nombre);
	printf("metio %d goles\n", unJugador.goles);
	printf("disputo %d partidos\n", unJugador.partidos);

}

void calcularPromedioJugador(jugador unJugador){
	unJugador.promedio = (float)unJugador.goles / unJugador.partidos;
	printf("el promedio de goles es %f", unJugador.promedio);
}

