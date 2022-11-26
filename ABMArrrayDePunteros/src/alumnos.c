/*
 * alumnos.c
 *
 *  Created on: 2 nov. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "validacionesInput.h"

/**********************************************************/
//FUNCIONES DEL ARRAY DE PUNTEROS


int alumnos_IncializarArray(alumno* alumnos[]){
	int retorno = -1;

	if(alumnos != NULL && TAM > 0){
		retorno = 0;
		for(int i = 0; i < TAM; i++){
			//EN VES DE USAR EL ISEMPTY  INCIALIZO EL ARRAY EN NULL ES DECIR LIBRE
			alumnos[i] = NULL;
		}
	}
	return retorno;
}

int alumnos_BuscarIndexLibre(alumno* alumnos[]){
	int retorno = -1;
	if(alumnos != NULL && TAM > 0){
		for(int i = 0; i < TAM; i++){
			if(alumnos[i] == NULL){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumnos_BuscarIndexOcupado(alumno* alumnos[]){
	int retorno = -1;
	if(alumnos != NULL && TAM > 0){
		for(int i = 0; i < TAM; i++){
			if(alumnos[i] != NULL){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


