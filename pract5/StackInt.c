#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "StackInt.h"

Stack * Stack_Ctor (int max)
{
	Stack * newStack = (Stack *) malloc (sizeof (Stack));
	// crea a un nuevo objeto Stack en el heap
	assert (newStack);
	newStack->stack = (int *) malloc (max * sizeof (int));
	// crea a un nuevo contenedor (el arreglo) de int's en el heap
	assert (newStack->stack);
	newStack->top = 0;
	newStack->max = max;
	return newStack;
}

void Stack_Push (Stack * this, int newVal)
{
	if (this->top >= this->max) 
		{
			assert (0); 
		}
	this->stack[this->top] = newVal;
	++this->top;
}
int Stack_Pop (Stack * this)
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

int Stack_Peek(Stack * this){
	return this->stack[this->top-1];
}

void Stack_Show(Stack * this)
{	
	if(Stack_IsEmpty(this)== TRUE)
	{
		printf("\n\n\bPila vacia\n");
	}

	else
	{
				printf("-------- PILA ------\n");
		for (size_t i = 0; i < this -> top; ++i)
		{
			printf(">%d<\n",this->stack[i]);
		}
				printf("-------- PILA ------\n");
	}
}