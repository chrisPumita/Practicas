#ifndef  LL_INC
#define  LL_INC

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

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


//-----------------FUNCIONES PROVADAS--------------*/

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

 /*---------------- FUNCIONES PUBLCIAS-----------------*/

 LinkedList* LinkedList_Create ();

 void LinkedList_Destroy (LinkedList* this);

 Bool LinkedList_Insert (LinkedList* this, int val);

 Bool LinkedList_Remove (LinkedList* this, int *val);

 Bool LinkedList_FindIf (LinkedList* this, int val);

Node* LinkedList_Search(LinkedList* this, int val);

Bool IsEmpty(LinkedList* this);

#endif   /* ----- #ifndef LL_INC  ----- */