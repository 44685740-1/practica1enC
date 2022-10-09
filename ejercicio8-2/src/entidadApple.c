/*
 * entidadApple.c
 *
 *  Created on: 7 oct. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesInput.h"
#include "entidadApple.h"

static int apple_ObtenerID(void);
static int apple_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int apple_idIncremental = 1000;
	return apple_idIncremental++;
}

//alta
void apple_Inicializar(productoApple productosApple[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			productosApple[i].isEmpty = LIBRE;
		}
	}
}

int apple_ObtenerIndexLibre(productoApple productosApple[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (productosApple[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


productoApple apple_CargarDatos(void) {
	productoApple auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	fflush(stdin);
	utn_getAlfaNumeric(auxiliar.descripcion, "\ningrese la descripcion del prodcuto apple\n", "ERROR", 0);
	utn_getNumero(&auxiliar.nacionalidad, "\ningrese la nacionalidad del prodcuto 1. EEUU - 2. CHINA - 3. OTRO", "ERROR", 1, 3, 1);
	utn_getNumero(&auxiliar.tipo, "\n ingrese el tipo del producto 1. IPHONE 2. -MAC 3. - IPAD 4. - ACCESORIOS", "ERROR", 1, 4, 1);
	utn_getNumero(&auxiliar.precio, "\ningrese le precio del producto\n", "ERROR", 0, 10000, 1);
	return auxiliar;
}

int apple_Alta(productoApple productosApple[], int TAM) {
	int rtn = 0;
	productoApple auxApple;

	//BUSCO ESPACIO EN ARRAY
	int index = apple_ObtenerIndexLibre(productosApple, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxApple = apple_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxApple.productoID = apple_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxApple.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		productosApple[index] = auxApple;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

//baja

int apple_BuscarPorID(productoApple productosApple[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (productosApple[i].productoID == ID && productosApple[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


productoApple apple_ModificarUno(productoApple productosApple) {
	productoApple auxiliar = productosApple;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	utn_getNumero(&auxiliar.precio, "\ningrese el nuevo precio del producto\n", "ERROR", 0, 10000, 1);
	utn_getNumero(&auxiliar.tipo, "\ningrese el nuevo tipo del prodcuto\n", "ERROR", 1, 4, 1);
	return auxiliar;
}

void apple_MostrarUno(productoApple productosApple) {
	//PRINTF DE UN SOLO Gen
	printf("ID: %d\n", productosApple.productoID);
	printf("descripcion: %s\n", productosApple.descripcion);
	printf("precio: %d\n", productosApple.precio);
	printf("nacionalidad: %d\n", productosApple.nacionalidad);
	printf("tipo: %d\n", productosApple.tipo);
}


int apple_MostrarTodos(productoApple productosApple[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	//puts("\n\t> LISTADO Gen");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (productosApple[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				apple_MostrarUno(productosApple[i]);
				//CONTADOR DE Gen
				cantidad++;

			}
		}

		//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
			if (cantidad > 0) {
				rtn = 1;
			}

	}


	return rtn;
}




int apple_Baja(productoApple productosApple[], int TAM) {
	int rtn = 0;
	int IDapple;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (apple_MostrarTodos(productosApple, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero(&IDapple, "\n ingrese el ID que quiere dar de baja\n", "ERROR", 1000, 2000, 1);

		//BUSCO INDEX POR ID EN ARRAY
		while (apple_BuscarPorID(productosApple, TAM, IDapple) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero(&IDapple, "\n ingrese el ID que quiere dar de baja\n", "ERROR", 1000, 2000, 1);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = apple_BuscarPorID(productosApple, TAM, IDapple);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		productosApple[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

//modificacion

productoApple eGen_ModificarUno(productoApple prodcuctosApple) {
	productoApple auxiliar = prodcuctosApple;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	utn_getNumero(&auxiliar.precio, "\n ingrese el nuevo valor de precio\n", "ERROR", 0, 10000, 1);
	utn_getNumero(&auxiliar.tipo, "\n ingrese el nuevo valor de tipo\n", "ERROR", 1, 4, 1);
	return auxiliar;
}

int apple_Modificacion(productoApple productosApple[], int TAM) {
	int rtn = 0;
	int IDapple;
	int index;
	int flag = 0;
	productoApple auxiliar;

	//LISTO TODOS LOS Gen
	if (apple_MostrarTodos(productosApple, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero(&IDapple, "\ningrese el ID a modificar\n", "ERROR", 1000, 2000, 1);

		//BUSCO INDEX POR ID EN ARRAY
		while (apple_BuscarPorID(productosApple, TAM, IDapple) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero(&IDapple, "\ningrese el ID a modificar\n", "ERROR", 1000, 2000, 1);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = apple_BuscarPorID(productosApple, TAM, IDapple);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = apple_ModificarUno(productosApple[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		productosApple[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

