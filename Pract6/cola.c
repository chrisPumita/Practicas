#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cola.h"

Cola * Cola_Ctor (int max)
{
	Cola * newCola = (Cola *) malloc (sizeof (Cola));
	// crea a un nuevo objeto Cola en el heap
	assert (newCola);
	newCola->cola = (int *) malloc (max * sizeof (int));
	// crea a un nuevo contenedor (el arreglo) de int's en el heap
  	/*---> Inicializamos la cola con los valores por default al momento de crerarla  ->> Ver Estrcutura*/
	assert (newCola->cola);
	newCola->first = 0;
	newCola->max = max;
	newCola->cont = 0;
	newCola->filled = FALSE;
	newCola->empty = TRUE;
	return newCola;
}

Bool Cola_Insert (Cola * this, int newVal)
{
  if(Cola_IsEmpty(this) == TRUE)
  {
  	return FALSE;
  }
  else
  {
    this->cola[this->last] = newVal;
    ++this -> last;
    if(this -> last == this -> max)
    {
      this->last = 0;
    }
    ++this->cont;
    return TRUE;
  }
    
}
int Cola_Remove (Cola * this)
{
	if (Cola_IsFull == TRUE)
	{
		assert (0); 
	}
	else
	{
		int val = this->pila[this->first];
		--this -> first;
		if (this -> first == 0)
		{
			this -> first == 0;
		}
		--this->cont;
		return val;
	}
}

/*FUNCION IMPLEMNETADAS <---- */
Bool Cola_IsEmpty (Cola * this)
{
	if (this -> cont == 0)
		return TRUE
	else
		return FALSE;
}

Bool Cola_IsFull (Cola * this)
{
	if (this -> cont == this -> max )
		return TRUE;
	else
		return FALSE;
}
/*FUNCION IMPLEMNETADAS <---- */
void Cola_Dtor (Cola * this)
{
	assert (this);
	free (this->cola);
	// devuelve la memoria del arreglo
	free (this);
	// devuelve la memoria del objeto
	printf("Se Destruyo la COLA BYE\n");
}
