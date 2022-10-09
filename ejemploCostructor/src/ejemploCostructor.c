/*
 ============================================================================
 Name        : ejemploCostructor.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejemploCostructor.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int legajo;
    char nombre[31];
    char sexo;
    float sueldo;
} eEmpleado;
int mostrarEmpleado(eEmpleado* pUnEmpleado);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);
int main(void) {
	//puntero a una estrcutura usando memoria dinamica
	eEmpleado* pEmpl;
	pEmpl = newEmpleado();

	eEmpleado* pEmplParam;
	pEmplParam = newEmpleadoParam(4321,"Ana",'f',4000);
	if(pEmpl != NULL){
		//uso el operador flecha porque estoy trabajando con un puntero a la estructura
		//inicializo
		pEmpl->legajo = 1234;
		strcpy(pEmpl->nombre, "juan");
		pEmpl->sexo = 'm';
		pEmpl->sueldo = 2000;

		free(pEmpl);
	}


	mostrarEmpleado(pEmpl);
	newEmpleado();
	mostrarEmpleado(pEmpl);
	mostrarEmpleado(pEmplParam);
	pEmplParam = newEmpleadoParam(100, "ahuitz", 'f', 500);
	mostrarEmpleado(pEmplParam);
	return 0;
}

int mostrarEmpleado(eEmpleado* pUnEmpleado)
{
    int error =1;

    if(pUnEmpleado != NULL)
    {
        error=0;
        printf("nombre: %s\n", pUnEmpleado->nombre);
        printf("legajo: %d\n", pUnEmpleado->legajo);
        printf("sueldo: %f\n", pUnEmpleado->sueldo);
        printf("sexo: %c\n", pUnEmpleado->sexo);

    }

    return error;
}

eEmpleado* newEmpleado(){
	eEmpleado*  nuevoEmpleado= NULL;
	nuevoEmpleado = (eEmpleado*)malloc(sizeof(eEmpleado));
	if(nuevoEmpleado != NULL){
		nuevoEmpleado->legajo = 0;
		nuevoEmpleado->sexo = ' ';
		nuevoEmpleado->sueldo = 0;
		strcpy(nuevoEmpleado->nombre, " ");
	}

	return nuevoEmpleado;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo)
{
    //Antes de cargar deben validarse los datos
    eEmpleado* nuevoEmpleado = NULL;
    nuevoEmpleado= (eEmpleado*) malloc(sizeof(eEmpleado));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo=legajo;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sexo=sexo;
        nuevoEmpleado->sueldo=sueldo;
    }

    return nuevoEmpleado;

}
