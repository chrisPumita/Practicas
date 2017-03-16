#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pila.h"

/*
void Stack_Ctor (Stack * this, double * stack, int max)
{
	this->stack = stack;
	this->max = max;
	this->top = 0;
}
*/


Stack * Stack_Ctor (int max)
{
	Stack * newStack = (Stack *) malloc (sizeof (Stack));
	// crea a un nuevo objeto Stack en el heap
	assert (newStack);
	newStack->stack = (double *) malloc (max * sizeof (double));
	// crea a un nuevo contenedor (el arreglo) de double's en el heap
	assert (newStack->stack);
	newStack->top = 0;
	newStack->max = max;
	return newStack;
}

void Stack_Push (Stack * this, double newVal)
{
	if (this->top >= this->max) 
		{
			assert (0); 
		}
	this->stack[this->top] = newVal;
	++this->top;
}
double Stack_Pop (Stack * this)
{
	if (this->top == 0) { 
		assert (0); 
	}
	--this->top;
	return this->stack[this->top];
}

Bool Stack_IsEmpty (Stack * this)
{
	return (this->top == 0);
}
Bool Stack_IsFull (Stack * this)
{
	return (this->top >= this->max);
}

void Stack_Dtor (Stack * this)
{
	assert (this);
	free (this->stack);
	// devuelve la memoria del arreglo
	free (this);
	// devuelve la memoria del objeto
	printf("Se Destruyo la PILA BYE\n");
}

double Stack_Peek(Stack * this){
	return this->stack[this->top-1];
}

void Stack_Show(Stack * this)
{	
	if(Stack_IsEmpty(this)== TRUE)
	{
		printf("\nPila vacia\n");
	}

	else
	{
		for (size_t i = 0; i < this -> top; ++i)
		{
			printf(">%lf<\n",this->stack[i]);
		}
	}
}