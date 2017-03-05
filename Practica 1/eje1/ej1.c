#include <stdio.h>
#include <stdlib.h>
#define limCal 5

/* ACCESO SECUENCIAL. Escriba un programa que en un ciclo lea 5 calificaciones de tipo real
del teclado, y luego en otro ciclo calcule el promedio. Finalmente, muestre el resultado en la
pantalla.*/

void main(void)
{
	double cal[limCal];
	double promedio = 0.0;
	int i;
	for (i = 0; i < limCal; ++i){
		printf("Introdizca calificacion %d:\n",i);
		scanf("%lf",&cal[i]);
	}

	for (i = 0; i < limCal; ++i){
		promedio += cal[i];
	}
	promedio = promedio/limCal;
	printf("TU primedio es: %lf \n",promedio);
	return 0;
}
