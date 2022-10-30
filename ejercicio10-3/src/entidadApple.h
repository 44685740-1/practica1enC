/*
 * entidadApple.h
 *
 *  Created on: 16 oct. 2022
 *      Author: ahuit
 */

#ifndef ENTIDADAPPLE_H_
#define ENTIDADAPPLE_H_

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TAM 5
typedef struct{
	int idTipo;
	char tipoDescripcion[1000];
}eTipoProducto;

typedef struct{
	int idProducto;
	char descripcion[1000];
	int nacionalidad;
	int tipo;
	int precio;
	int isEmpty;
}eApple;

//hardcodeo de tipo
void hardcodeoTipoProdcuto(eTipoProducto tipoProdcutos[]);

//obtener index ocupado para validacion de alta en el menu del main
int eApple_ObtenerIndexOcupado(eApple productosApple[]);


//alta producto Apple
void eApple_Inicializar(eApple prodcutosApple[]);
int eApple_ObtenerIndexLibre(eApple productosApple[]);
eApple eApple_CargarDatos(void);
int eApple_Alta(eApple productosApple[]);


//baja prodcuto apple
void eApple_MostrarUno(eApple productosApple);
int eApple_MostrarTodos(eApple prodcutosApple[]);
int eApple_Baja(eApple productosApple[]);

//modificacion prodcuto apple
eApple eApple_ModificarUno(eApple productosApple);
int eApple_Modificacion(eApple prodcutosApple[]);


//ordenamiento por precio
int eApple_SortPrecio(eApple prodcutosApple[], int criterio);


//ordenamiemto por descripcion
int eApple_SortDescripcion(eApple prodcutosApple[], int criterio);


//El listado de todos los productos con la descripción del tipo
void eApple_MostrarUnoConDescripcionDelTipo(eApple productosApple, eTipoProducto tipoProdcutos[]);
int eApple_MostrarTodosConDescripcionDelTipo(eApple prodcutosApple[], eTipoProducto tipoProductos[]);

//listar cada tipo
void eApple_MostrarUnoConCadaTipo(eApple productosApple, eTipoProducto tipoProdcutos[]);
int eApple_MostrarTodosCadaTipo(eApple prodcutosApple[], eTipoProducto tipoProductos[], int idTipo);
#endif /* ENTIDADAPPLE_H_ */
