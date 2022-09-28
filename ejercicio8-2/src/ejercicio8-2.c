/*
 ============================================================================
 Name        : ejercicio8-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio8-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "menuCadaOpcionDelMain.h"
int main(void) {
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	getNumero(&opcionMenuPrincipal, "\t ingrese que opcion desea del menu principal\n", "ERROR opcion invalida", 1, 6, 1);
	switch(opcionMenuPrincipal){
	case 1:
		//
		break;
	case 2:
		//
		break;
	case 3:
		//
		break;
	case 4:
		//
		break;
	case 5:
		//
		break;
	case 6:
		//
		break;
	}


	return 0;
}
