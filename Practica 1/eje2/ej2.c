#include <stdio.h>
#include <stdlib.h>

#define limCal 5

/*
ACCESO ALEATORIO. Escriba un programa que en un ciclo lea 5 calificaciones de tipo real
del teclado, y luego en otro ciclo le muestre al usuario la calificación que éste desee. Para
terminar el usuario deberá teclear -1.
*/

int main(void)
{
	double cal[limCal];
	int inKey=0;
	int i;
	for (i = 0; i < limCal; ++i){
		printf("Introdizca calificacion %d:\n",i+1);
		scanf("%lf",&cal[i]);
	}

	while(inKey != -1){
		printf("Escriba -1 para salir\nQue calificacion desea buscar? \n");
		scanf("%d", &inKey);
		printf("Tu calificacion %d es: %lf\n",inKey, cal[inKey-1] );
	}

	return 0;
}
