/*
 ============================================================================
 Name        : sabados27-08.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : sabados27-08
 ============================================================================
 */
/*
1.  Se ingresan 5 importes,
y pais de origen ('C' para China, 'U' para Uruguay o 'P' para Paraguay).
Calcular y mostrar:
a.  M?nimo importe con su pais
c.  Promedio importe
d.  Cantidad de productos de China (c)
e.  Sobre el m?nimo encontrado aplicar un descuento del 10% a dicho importe.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int importe;
	char paisDeOrigen;
	int i;//la usamos como contador
	int promedio;
	int acumuladorImporte;
	int contadorChina;
	int minimoImporte;
	int minimoImporteConDescuento;
	char paisMinimoImporte;
	//inicializar
	acumuladorImporte = 0;
	contadorChina = 0;

	for (i = 0; i < 2; i++) {
		printf("ingrese el importe\n");
		scanf("%d", &importe);
		acumuladorImporte += importe;
		printf("ingres el pais de origen\n");
		fflush(stdin); //importante si no anda
		scanf("%c", &paisDeOrigen);

		if(paisDeOrigen == 'c'){
			contadorChina++;
		}

		if(i==0){
			minimoImporte = importe;
			paisMinimoImporte = paisDeOrigen;
		} else{
			if(importe < minimoImporte){
				minimoImporte = importe;
				paisMinimoImporte = paisDeOrigen;
			}
		}
	}

	promedio = acumuladorImporte / i;
	minimoImporteConDescuento = minimoImporte * 0.9;
	printf("el promedio de importe es de: %d", promedio);
	printf("la cantidad de productos de china es de: %d", contadorChina);
	printf("el minimo importe fue de %d y fue del pais %c", minimoImporte , paisMinimoImporte);
	printf("el minimo importe con descuento fue de: %d", minimoImporteConDescuento);


	return 0;
}
