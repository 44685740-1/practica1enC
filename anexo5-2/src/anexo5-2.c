/*
 ============================================================================
 Name        : anexo5-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main(void) {
	setbuf(stdout, NULL);
	//muestro el menu por medio de una funcion es un void void
	menuDeOpciones();
	return 0;
}
