/*
 ============================================================================
 Name        : 15-5.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : 15-5.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ordenarDosNumeros(int numero1, int numero2);
int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	printf("ingrese un primer numero");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero");
	scanf("%d", &numero2);
	ordenarDosNumeros(numero1, numero2);
	return 0;
}

void ordenarDosNumeros(int numero1, int numero2){
	int buffer;
	if(numero1 > numero2){
		printf("ordenado mayor a menor: %d, %d", numero1, numero2);
	} else{
		buffer = numero2;
		numero2 = numero1;
		numero1 = buffer;
		printf("ordenado mmayor a menor: %d, %d", numero1, numero2);
	}


}
