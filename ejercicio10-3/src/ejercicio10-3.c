/*
 ============================================================================
 Name        : ejercicio10-3.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio10-3.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidadApple.h"
#include "validacionesInput.h"
int main(void) {
	setbuf(stdout, NULL);
	int resultadoMenuPrincipal;
	int retornoMenuPrincipal;
	char resultadoConfirmacionSalir;
	int retornoObtenerIndexOcupado;
	int resultadoMenuInformes;
	int retornoMenuInformes;
	int resultadoMenuInformes2;
	//declaro el array de prodcutos Apple
	eApple prodcutosApple[TAM];
	//inicializo el array de prodcutos Apple
	eApple_Inicializar(prodcutosApple);
	//declaro el array de tipo prodcuto
	eTipoProducto tipoProdcutos[4];
	//hardcodeo el array de tipoProdcutos
	hardcodeoTipoProdcuto(tipoProdcutos);

	do{
		printf("\n1. ALTA \n2. BAJA \n3. MODIFICACION \n4. LISTADO PRODUCTOS \n5. LISTADO ORDENADO POR PRECIO \n6. LISTADO ORDENADO POR DESCRIPCION \n 7. INFORMES \n 8. SALIR");
			do{
				retornoMenuPrincipal = utn_getNumero(&resultadoMenuPrincipal, "\ningrese la opcion que desea del menu principal\n", "ERROR", 1, 8, 1);
			} while(retornoMenuPrincipal != 0);

			switch(resultadoMenuPrincipal){
			case 1:
					eApple_Alta(prodcutosApple);
				break;
			case 2:
				retornoObtenerIndexOcupado = eApple_ObtenerIndexOcupado(prodcutosApple);
				if(retornoObtenerIndexOcupado != -1){
					eApple_Baja(prodcutosApple);
				} else{
					printf("\ntiene que teneer hecho al meno 1 alta\n");
				}
				break;
			case 3:
				retornoObtenerIndexOcupado = eApple_ObtenerIndexOcupado(prodcutosApple);
				if(retornoObtenerIndexOcupado != -1){
					eApple_Modificacion(prodcutosApple);
				} else{
					printf("\ntiene que teneer hecho al meno 1 alta\n");
				}
				break;
			case 4:
				retornoObtenerIndexOcupado = eApple_ObtenerIndexOcupado(prodcutosApple);
				if(retornoObtenerIndexOcupado != -1){
					eApple_MostrarTodos(prodcutosApple);
				} else{
					printf("\ntiene que teneer hecho al meno 1 alta\n");
				}
				break;
			case 5:
				retornoObtenerIndexOcupado = eApple_ObtenerIndexOcupado(prodcutosApple);
				if(retornoObtenerIndexOcupado != -1){
					eApple_SortPrecio(prodcutosApple, 1);//ordenado de mayor a menor
					eApple_MostrarTodos(prodcutosApple);
				} else{
					printf("\ntiene que teneer hecho al meno 1 alta\n");
				}
				break;
			case 6:
				retornoObtenerIndexOcupado = eApple_ObtenerIndexOcupado(prodcutosApple);
				if(retornoObtenerIndexOcupado != -1){
					eApple_SortDescripcion(prodcutosApple, 1);//ordenado de mayor a menor
					eApple_MostrarTodos(prodcutosApple);
				} else{
					printf("\ntiene que teneer hecho al meno 1 alta\n");
				}
				break;
			case 7:
				printf("\n1. El listado de todos los productos con la descripción del tipo\n 2. Por cada tipo la lista de productos.");
				do{
					retornoMenuInformes =   utn_getNumero(&resultadoMenuInformes, "\ningrese le informe que desea ver\n", "ERROR", 1, 2, 1);
				} while(retornoMenuInformes != 0);
				switch(resultadoMenuInformes){
				case 1:
					eApple_MostrarTodosConDescripcionDelTipo(prodcutosApple, tipoProdcutos);
					break;
				case 2:
					utn_getNumero(&resultadoMenuInformes2, "\ningrese el tipo del transporte del cual desea ver el informe 1. IPHONE 2. IPAD 3. MAC 4. ACCSESORIOS\n", "ERROR", 1, 4, 1);
					switch(resultadoMenuInformes2){
					case 1:
						eApple_MostrarTodosCadaTipo(prodcutosApple, tipoProdcutos, 1000);
						break;
					case 2:
						eApple_MostrarTodosCadaTipo(prodcutosApple, tipoProdcutos, 1001);
						break;
					case 3:
						eApple_MostrarTodosCadaTipo(prodcutosApple, tipoProdcutos, 1002);
						break;
					case 4:
						eApple_MostrarTodosCadaTipo(prodcutosApple, tipoProdcutos, 1003);
						break;
					}
					break;
				}
				break;
			case 8:
				ValidacionSalir(&resultadoConfirmacionSalir, "\nSeguro desea salir (s/n)\n", "ERROR", 's', 'n', 1);
				if(resultadoConfirmacionSalir == 'n'){
					resultadoMenuPrincipal = 0;
				}
				break;
			}
	} while(resultadoMenuPrincipal != 8);

	return 0;
}
