/*
 * entidadApple.c
 *
 *  Created on: 16 oct. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidadApple.h"
#include "validacionesInput.h"
static int eApple_ObtenerID(void);
static int eApple_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int eApple_idIncremental = 1000;
	return eApple_idIncremental++;
}
void hardcodeoTipoProdcuto(eTipoProducto tipoProdcutos[]){
	tipoProdcutos[0].idTipo = 1000;
	tipoProdcutos[1].idTipo = 1001;
	tipoProdcutos[2].idTipo = 1002;
	tipoProdcutos[3].idTipo = 1003;
	strcpy(tipoProdcutos[0].tipoDescripcion, "iphone");
	strcpy(tipoProdcutos[1].tipoDescripcion, "ipad");
	strcpy(tipoProdcutos[2].tipoDescripcion, "Mac");
	strcpy(tipoProdcutos[3].tipoDescripcion, "Accesorios");
}
void eApple_Inicializar(eApple prodcutosApple[]) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			prodcutosApple[i].isEmpty = LIBRE;
		}
	}
}

int eApple_ObtenerIndexLibre(eApple productosApple[]) {
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

int eApple_ObtenerIndexOcupado(eApple productosApple[]) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (productosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "OCUPADO"
			if (productosApple[i].isEmpty == OCUPADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
eApple eApple_CargarDatos(void) {
	eApple auxiliar;
	int resultadoTipo;
	int retornoDescripcion;
	int retornoNacionalidad;
	int retornoPrecio;
	int retornoTipo;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	retornoDescripcion =	utn_getAlfaNumeric(auxiliar.descripcion, "\ningrese la descripcion\n", "ERROR", 1);
	retornoNacionalidad =	utn_getNumero(&auxiliar.nacionalidad, "\ningrerse la nacionalidad  1. EEUU - 2. CHINA - 3. OTRO", "ERROR", 1, 3, 1);
	retornoPrecio =	utn_getNumero(&auxiliar.precio, "\ningrese le precio\n", "ERROR", 0, 10000, 1);
	retornoTipo =	utn_getNumero(&resultadoTipo, "\ningrese el tipo 1. IPHONE 2. IPAD 3. MAC 4. ACCSESORIOS\n", "ERROR", 1, 4, 1);
	switch(resultadoTipo){
	case 1:
		auxiliar.tipo = 1000;
		break;
	case 2:
		auxiliar.tipo = 1001;
		break;
	case 3:
		auxiliar.tipo = 1002;
		break;
	case 4:
		auxiliar.tipo = 1003;
		break;
	}
	return auxiliar;

}

int eApple_Alta(eApple productosApple[]) {
	int rtn = 0;
	eApple auxProductosApple;

	//BUSCO ESPACIO EN ARRAY
	int index = eApple_ObtenerIndexLibre(productosApple);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxProductosApple = eApple_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxProductosApple.idProducto = eApple_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxProductosApple.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		productosApple[index] = auxProductosApple;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eApple_BuscarPorID(eApple prodcutosApple[],int idProdcuto) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (prodcutosApple[i].idProducto == idProdcuto && prodcutosApple[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eApple_MostrarUno(eApple productosApple) {
	//PRINTF DE UN SOLO Gen
	printf("ID prodcuto: %d\n", productosApple.idProducto);
	printf("descripcion: %s\n", productosApple.descripcion);
	printf("nacionalidad: %d\n", productosApple.nacionalidad);
	printf("precio: %d\n", productosApple.precio);
	printf("tipo: %d\n", productosApple.tipo);
}

int eApple_MostrarTodos(eApple prodcutosApple[]) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO prodcutos Apple");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (prodcutosApple[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				eApple_MostrarUno(prodcutosApple[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


int eApple_Baja(eApple productosApple[]) {
	int rtn = 0;
	int idProdcuto;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (eApple_MostrarTodos(productosApple)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero(&idProdcuto, "\ningrese el ID que quiere dar de baja\n", "ERROR", 1000, 2000, 1);

		//BUSCO INDEX POR ID EN ARRAY
		while (eApple_BuscarPorID(productosApple, idProdcuto) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero(&idProdcuto, "\ningrese el ID que quiere dar de baja\n", "ERROR", 1000, 2000, 1);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eApple_BuscarPorID(productosApple, idProdcuto);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		productosApple[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}


eApple eApple_ModificarUno(eApple productosApple) {
	eApple auxiliar = productosApple;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	utn_getNumero(&auxiliar.precio, "\ningrese el nuevo valor del precio a modificar\n", "ERROR", 0, 10000, 1);
	return auxiliar;
}


int eApple_Modificacion(eApple prodcutosApple[]) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;
	eApple auxiliar;

	//LISTO TODOS LOS Gen
	if (eApple_MostrarTodos(prodcutosApple)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero(&idProducto, "\ningrese el ID del prodcuto que quiere modificar\n", "ERROR", 1000, 2000, 1);

		//BUSCO INDEX POR ID EN ARRAY
		while (eApple_BuscarPorID(prodcutosApple,idProducto) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero(&idProducto, "\ningrese el ID del prodcuto que quiere modificar\n", "ERROR", 1000, 2000, 1);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = eApple_BuscarPorID(prodcutosApple,idProducto);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eApple_ModificarUno(prodcutosApple[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		prodcutosApple[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}


//listado ordenado por precio
int eApple_SortPrecio(eApple prodcutosApple[], int criterio) {
	int rtn = 0;
	int i;
	int j;
	eApple aux;

	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (prodcutosApple[i].isEmpty == OCUPADO
							&& prodcutosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (prodcutosApple[i].precio > prodcutosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = prodcutosApple[i];
							prodcutosApple[i] = prodcutosApple[j];
							prodcutosApple[j] = aux;
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
					if (prodcutosApple[i].isEmpty == OCUPADO
							&& prodcutosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (prodcutosApple[i].precio < prodcutosApple[j].precio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = prodcutosApple[i];
							prodcutosApple[i] = prodcutosApple[j];
							prodcutosApple[j] = aux;
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

//listado ordenado por descripcion
int eApple_SortDescripcion(eApple prodcutosApple[], int criterio) {
	int rtn = 0;
	int i;
	int j;
	eApple aux;

	/** EJEMPLO DE SORT CON ID DE Gen
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (prodcutosApple[i].isEmpty == OCUPADO
							&& prodcutosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (prodcutosApple[i].descripcion[0] > prodcutosApple[j].descripcion[0]) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = prodcutosApple[i];
							prodcutosApple[i] = prodcutosApple[j];
							prodcutosApple[j] = aux;
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
					if (prodcutosApple[i].isEmpty == OCUPADO
							&& prodcutosApple[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (prodcutosApple[i].descripcion[0] < prodcutosApple[j].descripcion[0]) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = prodcutosApple[i];
							prodcutosApple[i] = prodcutosApple[j];
							prodcutosApple[j] = aux;
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


//El listado de todos los productos con la descripción del tipo.
void eApple_MostrarUnoConDescripcionDelTipo(eApple productosApple, eTipoProducto tipoProdcutos[]) {
	//PRINTF DE UN SOLO Gen
	printf("ID prodcuto: %d\n", productosApple.idProducto);
	printf("descripcion: %s\n", productosApple.descripcion);
	printf("nacionalidad: %d\n", productosApple.nacionalidad);
	printf("precio: %d\n", productosApple.precio);
	switch(productosApple.tipo){
	case 1000:
		printf("ID : %d\n", tipoProdcutos[0].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[0].tipoDescripcion);
		break;
	case 1001:
		printf("ID : %d\n", tipoProdcutos[1].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[1].tipoDescripcion);
		break;
	case 1002:
		printf("ID : %d\n", tipoProdcutos[2].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[2].tipoDescripcion);
		break;
	case 1003:
		printf("ID : %d\n", tipoProdcutos[3].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[3].tipoDescripcion);
		break;
	}
}

int eApple_MostrarTodosConDescripcionDelTipo(eApple prodcutosApple[], eTipoProducto tipoProductos[]) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO prodcutos Apple");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (prodcutosApple[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				eApple_MostrarUnoConDescripcionDelTipo(prodcutosApple[i], tipoProductos);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

//listado de cada tipo
void eApple_MostrarUnoConCadaTipo(eApple productosApple, eTipoProducto tipoProdcutos[]) {
	//PRINTF DE UN SOLO Gen
	printf("ID prodcuto: %d\n", productosApple.idProducto);
	printf("descripcion: %s\n", productosApple.descripcion);
	printf("nacionalidad: %d\n", productosApple.nacionalidad);
	printf("precio: %d\n", productosApple.precio);
	switch(productosApple.tipo){
	case 1000:
		printf("ID : %d\n", tipoProdcutos[0].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[0].tipoDescripcion);
		break;
	case 1001:
		printf("ID : %d\n", tipoProdcutos[1].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[1].tipoDescripcion);
		break;
	case 1002:
		printf("ID : %d\n", tipoProdcutos[2].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[2].tipoDescripcion);
		break;
	case 1003:
		printf("ID : %d\n", tipoProdcutos[3].idTipo);
		printf("descripcion: %s\n", tipoProdcutos[3].tipoDescripcion);
		break;
	}
}

int eApple_MostrarTodosCadaTipo(eApple prodcutosApple[], eTipoProducto tipoProductos[], int idTipo) {
	int i;
	int rtn = 0;
	int cantidad = 0;
	int contadorIPHONE;
	int contadorIPAD;
	int contadorMAC;
	int contadorACCSESORIOS;
	//inicializar contadores
	contadorIPHONE = 0;
	contadorIPAD = 0;
	contadorMAC = 0;
	contadorACCSESORIOS = 0;
	//CABECERA
	puts("\n\t> LISTADO prodcutos Apple");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//contadores de cada tipo
	if(prodcutosApple != NULL && TAM > 0){
		for(i = 0; i < TAM ; i++){
			switch(prodcutosApple[i].tipo){
			case 1000:
				contadorIPHONE++;
				break;
			case 1001:
				contadorIPAD++;
				break;
			case 1002:
				contadorMAC++;
				break;
			case 1003:
				contadorACCSESORIOS++;
				break;
			}
		}
	}
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (prodcutosApple != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (prodcutosApple[i].isEmpty == OCUPADO && prodcutosApple[i].tipo == idTipo) {
				//MUESTRO UN SOLO Gen
				eApple_MostrarUnoConDescripcionDelTipo(prodcutosApple[i], tipoProductos);
				//CONTADOR DE Gen
				cantidad++;
				if(cantidad == contadorIPHONE){
					i = 6;
				}
			}
			if (prodcutosApple[i].isEmpty == OCUPADO && prodcutosApple[i].tipo == idTipo) {
				//MUESTRO UN SOLO Gen
				eApple_MostrarUnoConDescripcionDelTipo(prodcutosApple[i], tipoProductos);
				//CONTADOR DE Gen
				cantidad++;
				if(cantidad == contadorIPAD){
					i = 6;
				}
			}
			if (prodcutosApple[i].isEmpty == OCUPADO && prodcutosApple[i].tipo == idTipo) {
				//MUESTRO UN SOLO Gen
				eApple_MostrarUnoConDescripcionDelTipo(prodcutosApple[i], tipoProductos);
				//CONTADOR DE Gen
				cantidad++;
				if(cantidad == contadorMAC){
					i = 6;
				}
			}
			if (prodcutosApple[i].isEmpty == OCUPADO && prodcutosApple[i].tipo == idTipo) {
				//MUESTRO UN SOLO Gen
				eApple_MostrarUnoConDescripcionDelTipo(prodcutosApple[i], tipoProductos);
				//CONTADOR DE Gen
				cantidad++;
				if(cantidad == contadorACCSESORIOS){
					i = 6;
				}
				}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
