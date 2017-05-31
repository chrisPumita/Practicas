#include <stdio.h>
#include "lldblc.h"
#define clear() printf("\033[H\033[J") 
// Para limpiar pantalla



int menu()
{
	printf("\tPUNTO DE VENTA\n");
		int opcion = 0;
		do
		{
			printf("\n");
			printf("+------------+--------+\n");
			printf("|NUEVA VENTA:| SALIR  |\n");
			printf("|     [1]    |  [0]   |\n");
			printf("+------------+--------+\n");
			printf("Elija una opcion: ");
			scanf ("%d", &opcion);
		} while (opcion<0 || opcion >2);
		printf("\n");
		return opcion;
}

 

int main()
{
	clear();
	LinkedList* ticket = LinkedList_Create ();
	int IDProducto = 1;
	LinkedList_Insert(ticket,IDProducto,"COCACOLA",2,10.0,20.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"SABRITAS",1,8.0,8.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"PALETA",5,2.0,10.0);
	IDProducto ++;
	int focus = 1;
	GeneraVenta(ticket,focus);
	return 0;
	
}

