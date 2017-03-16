
#include <stdio.h>
#include <assert.h>
#include "pila.c"
#define MAX_TAM 3

int main()
{
	Stack miPila;
	double arreglo[MAX_TAM];
	Stack_Ctor (&miPila, arreglo, MAX_TAM);
	Stack_Push (&miPila, 2.5);
	Stack_Push (&miPila, 3.5);
	Stack_Push (&miPila, 4.5);

	
	
	printf ("<%f>\n", Stack_Pop (&miPila));
	printf ("<%f>\n", Stack_Pop (&miPila));
	printf ("<%f>\n", Stack_Pop (&miPila));
	Stack otraPila;
	double arreglo2[100];
	Stack_Ctor (&otraPila, arreglo2, 100);
	// como los contenedores son arreglos locales a esta función, entonces NO es necesario liberar ninguna memoria.
	return 0;
}