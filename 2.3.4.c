#define MAX_TAM 5

#include <stdio.h>
#include <assert.h>
#include "pila.c"

int main()
{
	Stack * miPila = Stack_Ctor (MAX_TAM);
	double valor;
	int OpcionMenu;
		
	do
	{
		printf("\nOpciones:\n1 Agregar nuevo elemento\n2 Quitar un elemento\n3 Mostrar Ultimo \n4Salir \nDame una opcion: ");
		scanf("%i",&OpcionMenu);

		if(OpcionMenu==1)
		{
			printf ("Nuevo valor: ");
			scanf ("%lf", &valor);
			Stack_Push (miPila, valor);
		}

		if(OpcionMenu==2)
		{
			printf ("<Se obtuvo elemento %lf>\n", Stack_Pop (miPila));
		}

		if(OpcionMenu==3)
		{
			printf ("Ultimo Elemento<%lf>\n", Stack_Peek(miPila));
		}
		printf("PILA:\n");
		Stack_Show(miPila);
			
	}
		while(OpcionMenu==1 || OpcionMenu==2 || OpcionMenu==3); 

				Stack_Dtor (miPila);
return 0;
}
