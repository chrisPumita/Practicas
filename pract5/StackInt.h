#ifndef  PILA_INT
#define  PILA_INT

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

struct Stack_Type
{
	int * stack;
	int top;
	int max;
};

typedef struct Stack_Type Stack;

void Stack_Push (Stack * this, int newVal);

int Stack_Pop (Stack * this);

Bool Stack_IsEmpty (Stack * this);

Bool Stack_IsFull (Stack * this);

Stack * Stack_Ctor (int max);

void Stack_Dtor (Stack * this);

/*-- Implementacion de la funcion StacjPeek()*/
int Stack_Peek(Stack * this);

void Stack_Show(Stack * this);
/* NUEVAS FUNCIONES*/


#endif   /* ----- #ifndef PILA_INT  ----- */
