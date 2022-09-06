/*
 ============================================================================
 Name        : sabados3-9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 1:
 Crear una función que le solicite al usuario el ingreso de un numero y lo retorne.
 Ejercicio 2:
 Crear una función que reciba como parámetro dos números enteros, que realice el promedio de los números y que retorne dicho valor.
 Ejercicio 3:
 Crear una función que reciba como parámetro un número entero. La función retorna 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0. Realizar la prueba lógica de la función en el main.
 Ejercicio 4:
 Realizar un programa que permita el ingreso de 10 números enteros.
 Determinar:
 El promedio de los positivos
 La cantidad de ceros
 Del menor de los negativos la suma de los antecesores de ese valor (frenar en cero).
 Nota:
 Utilizar las funciones del punto anterior y desarrollar funciones para resolver los procesos que están resaltados.
 */
#include <stdio.h>
#include <stdlib.h>
//prototipo
int pedirUnNumero(void);
int promedioDosEnteros(int numero1, int numero2);
int numeroPositivoNegativo(int numeroPoN);
int ingresoDiezNumeros(void);
int main(void) {
	setbuf(stdout, NULL);
	/*
	int retornoDiezNumeros;
	 int retornoPedirNumero;
	 int numero1;
	 int numero2;
	 int promedio;
	 int numeroPoN;
	 int retornoPositivoNegativo;

	 retornoPedirNumero = pedirUnNumero();
	 printf("%d", retornoPedirNumero);

	 printf("ingrese un numero");
	 fflush(stdin);
	 scanf("%d", &numero1);
	 printf("ingrese un numero");
	 fflush(stdin);
	 scanf("%d", &numero2);
	 promedio = promedioDosEnteros(numero1,numero2);
	 printf("%d", promedio);

	 printf("ingrese un numero positivo o negativo");
	 fflush(stdin);
	 scanf("%d", &numeroPoN);

	 retornoPositivoNegativo = numeroPositivoNegativo(numeroPoN);
	 printf("%d", retornoPositivoNegativo);
	 */
	 ingresoDiezNumeros();

	return 0;
}

int pedirUnNumero(void) {
	int retorno;
	printf("ingrese un numero");
	scanf("%d", &retorno);
	return retorno;
}

int promedioDosEnteros(int numero1, int numero2) {
	int retorno;
	int suma;
	suma = numero1 + numero2;
	retorno = suma / 2;
	return retorno;
}

int numeroPositivoNegativo(int numeroPoN) {
	int retorno;
	if (numeroPoN >= 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}

int ingresoDiezNumeros(void) {
	int i;
	int numero;
	int contadorDeCeros;
	int contadorPositivos;
	int acumuladorPositivos;
	int promedioPositivos;
	int numeroMinimo;
	//inicializar
	contadorDeCeros = 0;
	contadorPositivos = 0;
	acumuladorPositivos = 0;
	for (i = 0; i < 3; i++) {
		printf("ingrese un numero para el loop");
		scanf("%d", &numero);

		if (numero == 0) {
			contadorDeCeros++;
		}

		if (numero > 0) {
			contadorPositivos++;
			acumuladorPositivos += numero;
		}

		if(i == 0){
			numeroMinimo = numero;
		} else{
			if(numero < numeroMinimo){
				numeroMinimo = numero;
			}
		}


	}

	promedioPositivos = acumuladorPositivos / contadorPositivos;

	printf("la cantidad de ceros es de: %d", contadorDeCeros);
	printf("el promedio de los positivos es: %d", promedioPositivos);
	printf("el menor de los negativos es: %d\n", numeroMinimo);
	for(i = numeroMinimo;numeroMinimo < 0; numeroMinimo++){
		printf("%d", numeroMinimo);
	}

	return numero;
}
