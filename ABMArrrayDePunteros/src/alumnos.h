/*
 * alumnos.h
 *
 *  Created on: 2 nov. 2022
 *      Author: ahuit
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_
//TAMAÑO ARRAY DE PUNTEROS DE ALUMNOS
#define TAM 50
typedef struct
{
	char nombre[168];
	float altura;
	int id;
}alumno;

int alumnos_IncializarArray(alumno* alumnos[]);
int alumnos_BuscarIndexLibre(alumno* alumnos[]);
int alumnos_BuscarIndexOcupado(alumno* alumnos[]);
#endif /* ALUMNOS_H_ */
