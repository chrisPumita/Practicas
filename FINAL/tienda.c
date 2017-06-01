#include <stdio.h>
#include "lldblc.h"
#include "bool.h"
#define clear() printf("\033[H\033[J") 
// Para limpiar pantalla


int menu()
{
	printf("\tPUNTO DE VENTA\n");
		Bool bandera == FALSE;
		while(opcion!= 0 ||){
			printf("\n");
			printf("+------------+--------+\n");
			printf("|NUEVA VENTA:| SALIR  |\n");
			printf("|     [1]    |  [0]   |\n");
			printf("+------------+--------+\n");
			printf("Elija una opcion: ");
			scanf ("%d", &opcion);
		}
		printf("\n");
		return opcion;
}

 

int main()
{
	clear();
	LinkedList* ticket = LinkedList_Create ();
	int IDProducto = 1;
	LinkedList_Insert(ticket,IDProducto,"4352",  "COCACOLA",2, 10.0, 20.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"54353", "SABRITAS",1,  8.0,  8.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"643634","PALETA",  5,  2.0,  10.0);
	IDProducto ++;
	int focus = 1;
	GeneraVenta(ticket,focus);
	return 0;
	
}
