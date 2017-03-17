#ifndef  COLA_INC
#define  COLA_INC

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

struct Cola_Type
{
	double * cola;
	int first;
	int last;
	int max;
	int cont;
	Bool filled;
	Bool empty;
};

typedef struct Cola_Type Cola;

//void Cola_Ctor (Cola * this, double * stack, int max);

Bool Cola_Insert (Cola * this, double newVal);

double Cola_Pop (Cola * this);

Bool Cola_IsEmpty (Cola * this);

Bool Cola_IsFull (Cola * this);

Cola * Cola_Ctor (int max);

void Cola_Dtor (Cola * this);

/*-- Implementacion de la funcion StacjPeek()*/
double Cola_Peek(Cola * this);

void Cola_Show(Cola * this);

#endif   /* ----- #ifndef COLA_INC  ----- */