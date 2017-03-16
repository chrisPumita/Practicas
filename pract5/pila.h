#ifndef  PILA_INC
#define  PILA_INC

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

struct Stack_Type
{
	double * stack;
	int top;
	int max;
};

typedef struct Stack_Type Stack;

//void Stack_Ctor (Stack * this, double * stack, int max);

void Stack_Push (Stack * this, double newVal);

double Stack_Pop (Stack * this);

Bool Stack_IsEmpty (Stack * this);

Bool Stack_IsFull (Stack * this);

Stack * Stack_Ctor (int max);

void Stack_Dtor (Stack * this);

/*-- Implementacion de la funcion StacjPeek()*/
double Stack_Peek(Stack * this);

void Stack_Show(Stack * this);

#endif   /* ----- #ifndef PILA_INC  ----- */