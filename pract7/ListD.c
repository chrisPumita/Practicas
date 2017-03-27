#include <stdio.h>
#include <stdlib.h>

/*Inicializacion del tipo Bool TRUE or FALSE*/
enum{FALSE =0; TRUE = !=0}
typedef unsigned int Bool;

/*Estructuras del ADT Nodo*/

struct Node_Type
{
	int info;
  //Datos
  struct Node_Type* next;
  //Apuntador al siguiente nodo
}
/* Estructura de la L.E. */

struct LinkedList_Type
{
	Node * first;
  // apuntador al primer nodo
    Node * last;
  //apuntador al ultimo nodo
}
typedef struct LinkedList_Type LinkedList;
  
  /*-------------->  F U N C I O N ES   <---------------*/
  /*******INICIO FUNCIONES PRIVADAS**********/
  static Node* newNode(int val){
	//static: puedes usarlo pero el cliente no (privado)
  Node* n= (Node *)malloc(sizeof (Node));
  if (n) { 
/* Si no se encontró memoria n tomara evalor de NULL o 0, 
lo que regresa seria FALSE en caso contrario se inicializa el nodo*/
    n->info = val;
    n->next = NULL;
  }
  return n;
}

static void deleteNode(Node * n){
  if(n){
  	free(n);
  }
}
  /*******FIN FUNCIONES PRIVADAS**********/

LinkedList *LinkedList_Create()
{
  //No requiere tamaño porque se pueden crear nodos infinitos* [HASTA QUE SE ACABE LA MEMORIA RAM]*
  LinkedList * n = (LinkedList *) malloc (sizeof(LinkedList)); 
  //Creamos en memoria un ATD de lista enlazada
    if (n){
    n->first= NULL;
    n->last=NULL;
  }
  return n;
}

Bool LinkedList_Insert(LinkedList * this, int val){
  Node* n = newNode(val);
  
  if (!n){return FALSE;}
  // Si es NULL devuelve FALSE
  //Existen nodos en la lista, La lista NO esta vacia
  if (this-> first != NULL){
  	this -> last ->next = n;
    //n->next=NULL;
    //no es necesario next ya que vale NULL desde que el nodo es creado
    this -> last = n;
  }
  //La lista está vacía Por lo tanto crea el primer nodo
 else{
  	this->first = n;
    //n->next=NULL;
    //no es necesario next ya que vale NULL desde que el nodo es creado
   	this->last  = n;
  }
  return TRUE;
 }

Bool LinkedListRemove(LinkedList * this, int *val){
  if (this -> first == NULL){ return FALSE;  }
  //la lista está vacía
  
  //la lista tiene un y sólo un nodo
  else if(this -> first == first -> last){
  	*val =this->first->info;
    deleteNode(this-> first);
    this->first =this->last= NULL;
    return TRUE;
  }
  //la lista tiene dos o más nodos
  else{
  	*val = this -> first -> info;
    Node * tmp = this -> first -> next;
    deleteNode (this->first);
  	this -> first = tmp;
    return TRUE;
  }
}

/*DRIVER PROGRAM*/
int main(void){
  LinkedList * miLista = LinkedList_Create();
  //Creamos un nuevo obj de Lista Enlazada
  if(LinkedList_Insert (miLista,5)== FALSE){
  	printf("Hubo un problema en insertado \n");
  }
	return 0;
}
