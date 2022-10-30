/*
 * entidadApple.c
 *
 *  Created on: 11 oct. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesInput.h"
#include "entidadApple.h"

//declaro contadores de tipo de producto
int contadorIPHONE;
int contadorMAC;
int contadorIPAD;
int contadorACSESORIOS;

//declaro acumuladores de precio segun tipo de prodcuto
int acumuladorIPHONE;
int acumuladorMAC;
int acumuladorIPAD;
int acumuladorACSESORIOS;

//inicializo contadores de tipo de producto
int contadorIPHONE = 0;
int contadorMAC = 0;
int contadorIPAD = 0;
int contadorACSESORIOS = 0;

//declaro acumuladores de precio segun tipo de prodcuto
int acumuladorIPHONE = 0;
int acumuladorMAC = 0;
int acumuladorIPAD = 0;
int acumuladorACSESORIOS = 0;

//declaro variables de promedio de cada tipo
int promedioIPHONE;
int promedioMAC;
int promedioIPAD;
int promedioACSESORIOS;

//declaro flag para de los IPHONE  el mas barato
int flagPrimero = 1;//1 == TRUE
int maximo;
int minimo;

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
	printf("\ningrese la decripcion\n");
	scanf("%s", auxiliar.descripcion);
	fflush(stdin);
	//utn_getAlfaNumeric(auxiliar.descripcion, "\ningrese la descripcion del prodcuto apple\n", "ERROR", 0);
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
		auxApple.idproducto = apple_ObtenerID();
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
			if (productosApple[i].idproducto == ID && productosApple[i].isEmpty == OCUPADO) {
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
	utn_getNumero(&auxiliar.tipo, "\ningrese el nuevo tipo del prodcuto 1. IPHONE 2. -MAC 3. - IPAD 4. - ACCESORIOS\n", "ERROR", 1, 4, 1);
	return auxiliar;
}

void apple_MostrarUno(productoApple productosApple) {
	//PRINTF DE UN SOLO Gen
	printf("ID: %d\n", productosApple.idproducto);
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

//ordenado por precio
int apple_SortPrecio(productoApple productosApple[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	productoApple aux;

	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].precio > productosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].precio < productosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

//ordenamiento descripcion

int apple_SortDescripcion(productoApple productosApple[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	productoApple aux;

	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].descripcion[0] > productosApple[j].descripcion[0]) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].descripcion[0] < productosApple[j].descripcion[0]) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

//mostrar mas caro

int apple_MostrarMasCaro(productoApple productosApple[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	productoApple aux;

	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].precio > productosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].precio < productosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int apple_MostrarTodosCaros(productoApple productosApple[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	//puts("\n\t> LISTADO Gen");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < 1; i++) {
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


//mostar los productos que cuestan 700

int apple_MostrarPrecioSetecientos(productoApple productosApple[], int TAM) {
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
				//AGREGO LA CONDICON DE 700
				if(productosApple[i].precio == 700){
					apple_MostrarUno(productosApple[i]);
				}
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

//precio promedio por tipo de prodcuto

int apple_MostrarPromedioTipoPrecio(productoApple productosApple[], int TAM) {
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
				switch(productosApple[i].tipo){
				case 1:
					contadorIPHONE++;
					acumuladorIPHONE += productosApple[i].precio;
					break;
				case 2:
					contadorMAC++;
					acumuladorMAC += productosApple[i].precio;
					break;
				case 3:
					contadorIPAD++;
					acumuladorIPAD += productosApple[i].precio;
					break;
				case 4:
					contadorACSESORIOS++;
					acumuladorACSESORIOS += productosApple[i].precio;
					break;
				}
				//CONTADOR DE Gen
				cantidad++;

			}
		}

		//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
			if (cantidad > 0) {
				rtn = 1;
			}

	}

	promedioIPHONE = acumuladorIPHONE / contadorIPHONE;
	promedioACSESORIOS = acumuladorACSESORIOS / contadorACSESORIOS;
	promedioIPAD = acumuladorIPAD / contadorIPAD;
	promedioMAC = acumuladorMAC / contadorMAC;

	printf("promedio IPHONE: %d\n", promedioIPHONE );
	printf("promedio ACSESORIOS: %d\n", promedioACSESORIOS);
	printf("promedio MAC: %d\n", promedioMAC);
	printf("promedio IPAD: %d\n", promedioIPAD);

	return rtn;
}

//de los IPHONE el mas barato
int apple_SortPrecioIPHONE(productoApple productosApple[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	productoApple aux;

	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].precio > productosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (productosApple[i].isEmpty == OCUPADO
							&& productosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (productosApple[i].precio < productosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = productosApple[i];
							productosApple[i] = productosApple[j];
							productosApple[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int apple_MostrarBaratoIPHONE(productoApple productosApple[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	//puts("\n\t> LISTADO Gen");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		//solo una iteracion
		for (i = 0; i < 1; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (productosApple[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				if(productosApple[i].tipo == 1){
					apple_MostrarUno(productosApple[i]);
				}
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


//los productos MADE IN CHINA
int apple_MostrarMadeInCHINA(productoApple productosApple[], int TAM) {
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
				if(productosApple[i].nacionalidad == 2){
					apple_MostrarUno(productosApple[i]);
				}
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


//los MAC que cuestan mas 700

int apple_MostrarMayorSetecientosMAC(productoApple productosApple[], int TAM) {
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
				if(productosApple[i].tipo == 2 && productosApple[i].precio > 700){
					apple_MostrarUno(productosApple[i]);
				}
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
