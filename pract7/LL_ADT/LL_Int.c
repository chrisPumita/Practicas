 
	#include <stdio.h>
 	#include <stdlib.h>
	#include "LL_Int.h"


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