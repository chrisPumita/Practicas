#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 10

#include "StackInt.h"


int opera(int a, int b, char operador);

int main()
{
	Stack * miPila = Stack_Ctor (MAX_TAM);
	char ecuacion[MAX_TAM] = "512+4*+3+";
	char var;
	int value;
	int a, b;
	int i = 0;

while(ecuacion[i] != '\0'){
		var = ecuacion[i];
		printf("___________\n");
		if ((var >= 0x30) && (var <= 0x39))
		{

			/*Encontro un valor numerico que guardarà en la pila*/
			value = var - 0x30;
			printf("Encontro Numero: %d\n",value);
			Stack_Push(miPila, value);
		}
		else{
			/* Encontro un operador, por lo tanto sacarà con POP
			los dos ultimos elementos para operarlos, en la funcion 
			opera decidira que hara: +, - *. /
			*/
			a = Stack_Pop(miPila);
			b = Stack_Pop(miPila);
			printf("Encontro Operador: %c\n",var);
			value = opera(a,b,ecuacion[i]);
			Stack_Push(miPila,value);
		}

		Stack_Show(miPila);
	i++;
}

	printf("El resultado es: %d \n",Stack_Pop(miPila));
	Stack_Dtor(miPila);
return 0;
}

int opera(int a, int b, char operador){
	int c;
	if(operador == '+')
		c = a+b;
	else if(operador == '-')
		c = a-b;
	else if(operador == '*')
		c = a*b;
	else
		c = a/b;
	return c;
}