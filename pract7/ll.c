
	#include <stdio.h>
 	#include <stdlib.h>

 	enum {FALSE = 0, TRUE = !0};
 	typedef unsigned int Bool;


/*--------- Estructura del NODO ------------*/
 struct Node_Type
 {
 	int info;
 // datos
 	struct Node_Type* next;
 // apuntador al siguiente nodo
 };
 typedef struct Node_Type Node;

 struct LinkedList_Type
 {
	 Node* first;
 // apuntador al primer nodo
 	Node* last;
 // apuntador al último nodo
 };
 typedef struct LinkedList_Type LinkedList;


 /*-------------------------------------------------------------------
 * funciones privadas!!
 *-----------------------------------------------------------------*/

 static Node* newNode (int val)
 {
 	Node* n = (Node *)malloc (sizeof (Node));
 	if (n) {
		 n->info = val;
		 n->next = NULL;
	 }
 	return n;
 }

 static void deleteNode (Node* n)
 {
	 if (n) {
		 free (n);
	 }
 }

 /*-------------------------------------------------------------------
 * Operaciones públicas!!
 *-----------------------------------------------------------------*/
 	
 	/* Funciones de la Listas */

 LinkedList* LinkedList_Create ()
 {
 	LinkedList* n = (LinkedList *)malloc (sizeof (LinkedList));
	 if (n) {
		 n->first = NULL;
		 n->last = NULL;
	 }
	 return n;
 }

 void LinkedList_Destroy (LinkedList* this)
 {
	 // devuelve los nodos existentes antes de destruir al objeto lista
	 while (this->first != NULL) {
		 Node* tmp = this->first->next;
		 deleteNode (this->first);
		 this->first = tmp;
	 }
	 free (this);
 // devuelve la memoria asignada a la lista
 }

 Bool LinkedList_Insert (LinkedList* this, int val)
 {
	 Node* n = newNode (val);
	 if (!n) { return FALSE; }
	 // si es NULL devuelve FALSE
	 // ya hay nodos en la lista, es decir, la lista NO está vacía
	 if (this->first != NULL) {
		 this->last->next = n;
		 // n->next = NULL;
		 // no es necesario, next ya vale NULL desde que el nodo es creado
		 this->last = n;
	 }
	 // la lista está vacía
	 else {
	 	this->first = n;
	 // n->next = NULL;
	 // no es necesario, next ya vale NULL desde que el nodo es creado
	 this->last = n;
	 }
	 return TRUE;
 }

 Bool LinkedList_Remove (LinkedList* this, int *val)
 {
	 if (this->first == NULL) { return FALSE;}
	 // la lista está vacía

	 // la lista tiene un y sólo un nodo
	 else if (this->first == this->last) {
		 *val = this->first->info;
		 deleteNode (this->first);
		 this->first = this->last = NULL;
		 return TRUE;
	 }

	 // la lista tiene dos o más nodos
	 else {
		 *val = this->first->info;
		 Node* tmp = this->first->next;
		 deleteNode (this->first);
		 this->first = tmp;
		 return TRUE;
	 }
 }


 Bool LinkedList_FindIf (LinkedList* this, int val)
 {
	 Node* it = this->first;

	 while (it != NULL) {
		 if (it->info == val) { return TRUE; }
		 it = it->next;
	 }
	 return FALSE;
 }

Node* LinkedList_Search(LinkedList* this, int val){
 	Node * it = this -> first;
 	//Devuelve la direccion del primer nodo

 	while(it != NULL)
 	{
 		if (it->info == val)
 		{
 			//Encontró el valor buscado
 			return it;
 		}
 		it = it -> next;
 		//Se pasa al siguiente nodo
 	}
 	return NULL; // NO Encontro el elemento, por lo tanto es NULL;
 }

Bool IsEmpty(LinkedList* this){
		 if (this->first == NULL) { 
		 	return TRUE;
		 }
		 else{
		 	return FALSE;
		 }
	 // la lista está vacía
}

/*
*/

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
 