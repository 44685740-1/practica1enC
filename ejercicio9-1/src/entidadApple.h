/*
 * entidadApple.h
 *
 *  Created on: 11 oct. 2022
 *      Author: ahuit
 */

#ifndef ENTIDADAPPLE_H_
#define ENTIDADAPPLE_H_

typedef struct{
	int idproducto;
	char descripcion[1000];
	int nacionalidad;
	int tipo;
	int precio;
	int isEmpty;
}productoApple;

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


//alta
void apple_Inicializar(productoApple productosApple[], int TAM);
int apple_ObtenerIndexLibre(productoApple productosApple[], int TAM);
productoApple apple_CargarDatos(void);
int apple_Alta(productoApple productosApple[], int TAM);

//baja
int apple_BuscarPorID(productoApple productosApple[], int TAM, int ID);
productoApple apple_ModificarUno(productoApple productosApple);
void apple_MostrarUno(productoApple productosApple);
int apple_MostrarTodos(productoApple productosApple[], int TAM);
int apple_Baja(productoApple productosApple[], int TAM);

//modificar
productoApple eGen_ModificarUno(productoApple prodcuctosApple);
int apple_Modificacion(productoApple productosApple[], int TAM);

//ordenamiento precio
int apple_SortPrecio(productoApple productosApple[], int TAM, int criterio);
//imprimis llamando a mostrar todos

//ordenamiento descripcion
int apple_SortDescripcion(productoApple productosApple[], int TAM, int criterio);
//imprimis llamando a mostrar todos

//mostar prodcuto mas caro
int apple_MostrarMasCaro(productoApple productosApple[], int TAM, int criterio);
int apple_MostrarTodosCaros(productoApple productosApple[], int TAM);

//mostar producto precio 700
int apple_MostrarPrecioSetecientos(productoApple productosApple[], int TAM);

//mostrar promedio de precio segun tipo
int apple_MostrarPromedioTipoPrecio(productoApple productosApple[], int TAM);

//de los IPHONE el mas barato
int apple_SortPrecioIPHONE(productoApple productosApple[], int TAM, int criterio);
int apple_MostrarBaratoIPHONE(productoApple productosApple[], int TAM);

//MADE IN CHINA
int apple_MostrarMadeInCHINA(productoApple productosApple[], int TAM);

//MAC precio mayor a 700
int apple_MostrarMayorSetecientosMAC(productoApple productosApple[], int TAM);
#endif /* ENTIDADAPPLE_H_ */
