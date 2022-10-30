/*
 ============================================================================
 Name        : ejercicio9-1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio9-1.c
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
	int resultadoOpcionMain;
	int retornoOpcionMain;
	int resultadoSubMenu;
	int retornoSubMenu;

	//declaro el array de productos apple
	productoApple productosApple[TAM];
	//lo inicializo fuera del menu
	apple_Inicializar(productosApple, TAM);

	do {
		printf(" 1. ALTA \n 2. BAJA \n 3. MODIFICACION \n 4. LISTADO PRODUCTOS \n 5. LISTADO ORDENADO PRECIO \n 6. LISTADO ORDENADO POR DESCRIPCION \n 7. INFORMES \n 8. SALIR");

		do {
			retornoOpcionMain = utn_getNumero(&resultadoOpcionMain,"\n ingrese la opcion del menu principal\n", "ERROR", 1, 8,1);
		} while (retornoOpcionMain != 0);

		switch (resultadoOpcionMain) {
		case 1:
			apple_Alta(productosApple, TAM);
			break;
		case 2:
			apple_Baja(productosApple, TAM);
			break;
		case 3:
			apple_Modificacion(productosApple, TAM);
			break;
		case 4:
			apple_MostrarTodos(productosApple, TAM);
			break;
		case 5:
			apple_SortPrecio(productosApple, TAM, 1);
			apple_MostrarTodos(productosApple, TAM);
			break;
		case 6:
			apple_SortDescripcion(productosApple, TAM, 1);
			apple_MostrarTodos(productosApple, TAM);
			break;
		case 7:
			do{
				printf("\t INFORMES \n 1. LOS PRODUCTOS MAS CAROS \n 2. LOS PRODCUTOS QUE CUESTAN 700 \n 3. PRECIO PROMEDIO POR TIPO DE PRODCUTO \n 4. DE LOS IPHONE EL MAS BARATO \n 5. LOS PRODCUTOS MADE IN CHINA \n 6. LAS MAC QUE CUESTAN MAS DE 700 \n 7. EL/LOS ACCSESORIOS MAS CAROS \n 8. SALIR DE INFORMES");
				do{
					retornoSubMenu = utn_getNumero(&resultadoSubMenu, "\ningrese la opcion del informe que desea\n", "ERROR", 1, 8, 1);
				} while(retornoSubMenu != 0);

				switch(resultadoSubMenu){
				case 1:
					apple_MostrarMasCaro(productosApple, TAM, 1);
					apple_MostrarTodosCaros(productosApple, TAM);
					break;
				case 2:
					apple_MostrarPrecioSetecientos(productosApple, TAM);
					break;
				case 3:
					apple_MostrarPromedioTipoPrecio(productosApple, TAM);
					break;
				case 4:
					apple_SortPrecioIPHONE(productosApple, TAM, -1);
					apple_MostrarBaratoIPHONE(productosApple, TAM);
					break;
				case 5:
					apple_MostrarMadeInCHINA(productosApple, TAM);
					break;
				case 6:
					apple_MostrarMayorSetecientosMAC(productosApple, TAM);
					break;
				case 7:
					//los acsesorios mas caros es mas de lo mismo, no vale la pena hacerlo
					break;
				case 8:
					printf("\nsaliste de informes\n");
					break;
				}
			} while(resultadoSubMenu != 8);

			break;
		case 8:
			printf("saliste");
			break;
		}

	} while (resultadoOpcionMain != 8);



	return 0;
}
