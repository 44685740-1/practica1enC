/*
 * validacionesInput.h
 *
 *  Created on: 11 oct. 2022
 *      Author: ahuit
 */

#ifndef VALIDACIONESINPUT_H_
#define VALIDACIONESINPUT_H_


// utn get numero int

 int esNumerica(char *cadena);
int getInt(int *pResultado);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

// utn get float
int esNumeroflotante(char *valorReemplazoResultado);
int getFloat(float *pResultado);
int get_UTN_ValidacionNumeroflotante(float *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones);



 //utn get string, pasar pResult como un array sin los corchetes
int getString(char *string, int len);
int isAlfaNumeric(char *string, int len);
int getAlfaNumeric(char *pResult, int len);
int utn_getAlfaNumeric(char *pResult, char *message, char *ErrorMessage,
		int retry);


//utn get char
int utnGetChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);



/*
  //id incremental funcion estatica, incrementa el id cada vez que se llama a la funcion
int productoObtenerID(void);
void prueba(void);
*/


#endif /* VALIDACIONESINPUT_H_ */
