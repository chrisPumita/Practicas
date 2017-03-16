#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TAM 5

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;


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


int main()
{
	Stack * miPila = Stack_Ctor (MAX_TAM);
	int valor;
	int OpcionMenu;
		
	do
	{
		printf("\nOpciones:\n1 Agregar nuevo elemento\n2 Quitar un elemento\n3 Mostrar Ultimo \n4Salir \nDame una opcion: ");
		scanf("%d",&OpcionMenu);

		if(OpcionMenu==1)
		{
			printf ("Nuevo valor: ");
			scanf ("%d", &valor);
			Stack_Push (miPila, valor);
		}

		if(OpcionMenu==2)
		{
			printf ("<Se obtuvo elemento %d>\n", Stack_Pop (miPila));
		}

		if(OpcionMenu==3)
		{
			printf ("Ultimo Elemento <%d>\n", Stack_Peek(miPila));
		}
		printf("PILA:\n");
		Stack_Show(miPila);
			
	}
		while(OpcionMenu==1 || OpcionMenu==2 || OpcionMenu==3); 

				Stack_Dtor (miPila);
return 0;
}


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
		printf("\nPila vacia\n");
	}

	else
	{
		for (size_t i = 0; i < this -> top; ++i)
		{
			printf(">%d<\n\b",this->stack[i]);
		}
	}
}