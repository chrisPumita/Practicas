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

	int no_relojes;

	printf("¿Cuantos Relojes deseeas?\n");
	scanf("%d",&no_relojes);

	Reloj *p = (Reloj * ) malloc(no_relojes * sizeof(Reloj));

	if (p == NULL){
		printf("TUVIMOS UN PROBLEMA\n");
		return 1;
	}
	int i;
	for (i = 0; i < no_relojes; ++i){
		Reloj_Set(&p[i],01,30);
	}
	for (i = 0; i < no_relojes; ++i){
		Reloj_Print(&p[i]);
	}

	free(p);
	return 0;
}
