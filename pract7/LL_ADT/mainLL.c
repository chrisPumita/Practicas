 #include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 10

#include "LL_Int.h"


 /*-------------------------------------------------------------------
 * Driver program (cliente)
 *-----------------------------------------------------------------*/
 int main(void)
 {
	 LinkedList* miLista = LinkedList_Create ();
	 // crea un nuevo objeto de lista enlazada
	 if (IsEmpty(miLista) == TRUE)
	 {
	 	printf("La lista No tiene elementos\n");
	 }

	 if (LinkedList_Insert (miLista, 5) == FALSE) {
		 printf ("hubo un problema insertando\n");
	 }
	 else{
	 	printf("Se agrego Un nodo y su Informacion\n");
	 }

	 if (LinkedList_Insert (miLista, 6) == FALSE) {
		 printf ("hubo un problema insertando\n");
	 }
	 else{
	 	printf("Se agrego Un nodo y su Informacion\n");
	 }

	 if (IsEmpty(miLista)!= TRUE)
	 {
	 	printf("La lista ya tiene elementos\n");
	 }

	 if (LinkedList_Insert (miLista, 7) == FALSE) {
	 	printf ("hubo un problema insertando\n");
	 }
	 else{
	 	printf("Se agrego Un nodo y su Informacion\n");
	 }

	 if (LinkedList_FindIf (miLista, 6) == TRUE) {
	 		printf ("El valor 6 sí está en la lista\n");
	 	}
	else{
	 		printf ("El valor 6 no está en la lista\n");
	 	}

	 int elemento = 4;
	 if (LinkedList_Search (miLista, elemento) == FALSE) {
	 	printf ("No se encontro el elemento: %d\n",elemento);
	 }
	 else {
	 	printf ("Se ecnontro el nodo cuyo valor es: %d\n", elemento);
	 }

	 LinkedList_Destroy(miLista);
	 // destruye la lista enlazada miLista
	 return 0;
 }
 