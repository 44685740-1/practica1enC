/*
 ============================================================================
 Name        : ejemploSetyGet.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejemploSetyGet.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int legajo;
	char nombre[31];
	char sexo;
	float sueldo;
} eEmpleado;

int mostrarEmpleado(eEmpleado pUnEmpleado);
eEmpleado* newEmpleado(); //encapsula el malloc
eEmpleado newEmpleadoParam(int legajo, char *nombre, char sexo, float sueldo); //encapsula el malloc
int empleadoSetLegajo(eEmpleado pEmpleado, int legajo);
int empleadoSetNombre(eEmpleado pEmpleado, char *nombre);
int empleadoSetSueldo(eEmpleado pEmpleado, float sueldo);
int empleadoSetSexo(eEmpleado pEmpleado, char sexo);
int empleadoGetLegajo(eEmpleado this);
float empleadoGetSueldo(eEmpleado this);
char empleadoGetSexo(eEmpleado this);
void empleadosOrdenar(eEmpleado *this, int tam);

int main(void) {
	setbuf(stdout, NULL);
	int i;
	//puntero a un array de estructura en memoria dinámica
	eEmpleado *pEmpl = (eEmpleado*) malloc(sizeof(eEmpleado) * 5);

	if (pEmpl == NULL) {
		printf("No se pudo crear empleado 1");
		exit(EXIT_FAILURE);
	} else {
		*(pEmpl + 0) = newEmpleadoParam(123, "Juan", 'm', 2000);
		*(pEmpl + 1) = newEmpleadoParam(124, "Ana", 'f', 4000);
		*(pEmpl + 2) = newEmpleadoParam(125, "Pedro", 'm', 3000);
		*(pEmpl + 3) = newEmpleadoParam(126, "Maria", 'f', 5000);
		*(pEmpl + 4) = newEmpleadoParam(127, "Rolo", 'm', 3000);

		for (i = 0; i < 5; i++) {
			mostrarEmpleado(*(pEmpl + i));
		}

		empleadosOrdenar(pEmpl, 5);

		printf("Ordenados por Sueldo \n\n");

		for (i = 0; i < 5; i++) {
			mostrarEmpleado(*(pEmpl + i));
		}

		free(pEmpl);

	}

	return 0;
}

int mostrarEmpleado(eEmpleado pUnEmpleado) {
	int error = 1;

	error = 0;
	printf("%d  %s  %c  %.2f\n", empleadoGetLegajo(pUnEmpleado),
			pUnEmpleado.nombre, empleadoGetSexo(pUnEmpleado),
			empleadoGetSueldo(pUnEmpleado));

	return error;
}

eEmpleado* newEmpleado() {
	//Pide memoria dinámica e inicializa los datos
//
	eEmpleado *nuevoEmpleado;
	nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

	if (nuevoEmpleado != NULL) {
		nuevoEmpleado->legajo = 0;
		strcpy(nuevoEmpleado->nombre, " ");
		nuevoEmpleado->sexo = ' ';
		nuevoEmpleado->sueldo = 0;
	}

	return nuevoEmpleado;

}

eEmpleado newEmpleadoParam(int legajo, char *nombre, char sexo, float sueldo) {
	eEmpleado nuevoEmpleado;

	nuevoEmpleado.legajo = legajo;
	strcpy(nuevoEmpleado.nombre, nombre);
	nuevoEmpleado.sexo = sexo;
	nuevoEmpleado.sueldo = sueldo;

	return nuevoEmpleado;

}
int empleadoSetLegajo(eEmpleado pEmpleado, int legajo) {
	//Validan datos
	int retorno = 0;

	pEmpleado.legajo = legajo;
	retorno = 1;

	return retorno;
}
int empleadoSetSueldo(eEmpleado pEmpleado, float sueldo) {
	int retorno = 0;

	pEmpleado.sueldo = sueldo;
	retorno = 1;

	return retorno;
}
int empleadoSetSexo(eEmpleado pEmpleado, char sexo) {
	int retorno = 0;

	pEmpleado.sexo = sexo;
	retorno = 1;

	return retorno;
}
int empleadoSetNombre(eEmpleado pEmpleado, char *nombre) {
	int retorno = 0;

	strcpy(pEmpleado.nombre, nombre);
	retorno = 1;

	return retorno;
}
int empleadoGetLegajo(eEmpleado this) {

	return this.legajo;

}

float empleadoGetSueldo(eEmpleado this) {

	return this.sueldo;

}
char empleadoGetSexo(eEmpleado this) {

	return this.sexo;

}
void empleadosOrdenar(eEmpleado *this, int tam) {
	int i, j;
	eEmpleado aux;

	for (i = 0; i < tam - 1; i++) {
		for (j = i + 1; j < tam; j++) {

			if ((*(this + i)).sueldo > ((*(this + j)).sueldo)) {
				aux = *(this + i);
				*(this + i) = *(this + j);
				*(this + j) = aux;
			}
		}

	}
}

