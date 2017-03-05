#include <stdio.h>
#include <unistd.h>
//para la funcion sleep()

#include <stdlib.h>
//Para malloc() y compañia

#include "Bool.h"
#include "Reloj.h"
// MIS LIBRERIAS


/*DRIVER PROGRAM*/

int main(int argc, char const *argv[])
{
	Reloj *casio = Reloj_New(12,00);
	Reloj_Print(casio);
	Reloj_Delete(casio);


	/*
	Reloj casio;
	Reloj iwatch;
	Reloj_Set (&casio, 20, 54);
	Reloj_Set (&iwatch, 20,52);

	//printf("Ver 1.0 \n\tSeleccione una opcion:\n");
	printf("La hora del Reloj 1 es %d:%d\n", casio.horas,casio.minutos);
	printf("La hora del Reloj 2 es %d:%d\n", iwatch.horas,iwatch.minutos);
	if(Reloj_IsEqual(&casio, &iwatch) == TRUE){
		printf("Los relojes Son iguales\n");
	}
	else{
		printf("Los Relojes No son iguales\n");
	}

	if(Reloj_IsGreater(&casio,&iwatch) == TRUE)
		printf("La hora del Reloj 1 es mayor a la del Reloj 2");
	else
		printf("El reloj 2 es mayor");
	*/


	return 0;
}
