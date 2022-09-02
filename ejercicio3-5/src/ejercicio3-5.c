/*
 ============================================================================
 Name        : ejercicio3-5.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio3-5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int* pc, c;

	   c = 22;
	   printf("Address of c: %p\n", &c);
	   printf("Value of c: %d\n\n", c);  // 22

	   pc = &c;
	   printf("Address of pointer pc: %p\n", pc);
	   printf("Content of pointer pc: %d\n\n", *pc); // 22

	   c = 11;
	   printf("Address of pointer pc: %p\n", pc);
	   printf("Content of pointer pc: %d\n\n", *pc); // 11

	   *pc = 2;
	   printf("Address of c: %p\n", &c);
	   printf("Value of c: %d\n\n", c); // 2
	   return 0;
	return 0;
}

