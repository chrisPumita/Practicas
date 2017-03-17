#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "listaD.h"

Lista * Lista_Ctor (int max)
{
	Lista * newLista = (Lista *) malloc (sizeof (Lista));
	// crea a un nuevo objeto Lista en el heap
	assert (newLista);
	newLista->lista = (int *) malloc (max * sizeof (int));
	// crea a un nuevo contenedor (el arreglo) de int's en el heap
  	/*---> Inicializamos la lista con los valores por default al momento de crerarla  ->> Ver Estrcutura*/
	assert (newLista->lista);
	newLista->front = 0;
	newLista->rear = 0;
	newLista->cont = 0;
	newLista->max = max;
	return newLista;
}

Bool Lista_Insert (Lista * this, int newVal)
{
  if(Lista_IsEmpty(this) == TRUE)
  {
  	return FALSE;
  }
  else
  {
    this->lista[this->rear] = newVal;
    ++this -> rear;
    if(this -> rear == this -> max)
    {
      this->rear = 0;
    }
    ++this->cont;
    return TRUE;
  }
    
}
int Lista_Remove (Lista * this)
{
	if (Lista_IsFull == TRUE)
	{
		assert (0); 
	}
	else
	{
		int val = this->lista[this->front];
		++this -> front;
		if (this -> front == 0)
		{
			this -> front == 0;
		}
		--this->cont;
		return val;
	}
}

/*
FUNCIONES BACK
*/
Bool Lista_InsertBack (Lista * this, int newVal)
{
  if(Lista_IsEmpty(this) == TRUE)
  {
  	return FALSE;
  }
  else
  {
    this->lista[this->front] = newVal;
    ++this -> front;
    if(this -> front == this -> max)
    {
      this->front = 0;
    }
    ++this->cont;
    return TRUE;
  }
    
}
int Lista_RemoveBack (Lista * this)
{
	if (Lista_IsFull == TRUE)
	{
		assert (0); 
	}
	else
	{
		int val = this->lista[this->rear];
		++this -> rear;
		if (this -> rear == 0)
		{
			this -> rear == 0;
		}
		--this->cont;
		return val;
	}
}


/*FUNCION IMPLEMNETADAS <---- */
Bool Lista_IsEmpty (Lista * this)
{
	if (this -> cont == 0)
		return TRUE
	else
		return FALSE;
}

Bool Lista_IsFull (Lista * this)
{
	if (this -> cont == this -> max )
		return TRUE;
	else
		return FALSE;
}
/*FUNCION IMPLEMNETADAS <---- */
void Lista_Dtor (Lista * this)
{
	assert (this);
	free (this->lista);
	// devuelve la memoria del arreglo
	free (this);
	// devuelve la memoria del objeto
	printf("Se Destruyo la COLA BYE\n");
}
