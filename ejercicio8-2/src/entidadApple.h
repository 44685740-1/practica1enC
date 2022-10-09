/*
 * entidadApple.h
 *
 *  Created on: 7 oct. 2022
 *      Author: ahuit
 */

#ifndef ENTIDADAPPLE_H_
#define ENTIDADAPPLE_H_
typedef struct{
	int productoID;
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


#endif /* ENTIDADAPPLE_H_ */
