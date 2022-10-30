/*
 ============================================================================
 Name        : ejercicio8-2.c
 Author      :  Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description :  ejercicio8-2.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesInput.h"
#include "entidadApple.h"
#define TAM 5
int main(void) {
	setbuf(stdout, NULL);
	//declaro el array de prodcuto apple
	productoApple prodcutosApple[TAM];
	int retornoOpcionMain;
	int resultadoOpcionMain;

	//inicializo apple
	apple_Inicializar(prodcutosApple, TAM);

	do{
		printf(" 1. ALTA \n 2. BAJA \n 3. MODIFICACION  \n 4. LISTADO \n 5. LISTADO ORDENADO PRECIO \n 6. LISTADO ORDENADO DESCRIPCION \n 7. SALIR");

		do{
			retornoOpcionMain = utn_getNumero(&resultadoOpcionMain, "\ningrese la opcion que desea del menu principal\n", "ERROR", 1, 7, 1);
		} while(retornoOpcionMain != 0);

		switch(resultadoOpcionMain){
		case 1:
			apple_Alta(prodcutosApple, TAM);
			break;
		case 2:
			apple_Baja(prodcutosApple, TAM);
			break;
		case 3:
			apple_Modificacion(prodcutosApple, TAM);
			break;
		case 4:
			apple_MostrarTodos(prodcutosApple, TAM);
			break;
		case 5:
			apple_SortPrecio(prodcutosApple, TAM, 1);
			apple_MostrarTodos(prodcutosApple, TAM);
			break;
		case 6:
			apple_SortDescripcion(prodcutosApple, TAM, 1);
			apple_MostrarTodos(prodcutosApple, TAM);
			break;
		case 7:
			printf("saliste");
			break;
		}

	} while(resultadoOpcionMain != 7);





	return 0;
}
