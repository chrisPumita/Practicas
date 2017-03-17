#ifndef  LISTA_INC
#define  LISTA_INC

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

struct ListD_Type
{
	double * lista;
	int front;
	int rear;
	int max;
	int cont;
};

typedef struct Cola_Type Lista;

Lista * Lista_Ctor (int max);

Bool Lista_Insert (Lista * this, int newVal);

int Lista_Remove (Lista * this);

Bool Lista_InsertBack (Lista * this, int newVal);

int Lista_RemoveBack (Lista * this);

Bool Lista_IsEmpty (Lista * this);

Bool Lista_IsFull (Lista * this);

void Lista_Dtor (Lista * this);

#endif   /* ----- #ifndef LISTA_INC  ----- */