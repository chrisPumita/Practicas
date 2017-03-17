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

Cola * Cola_Ctor (int max);

Bool Cola_Insert (Cola * this, int newVal);

int Cola_Remove (Cola * this);

Bool Cola_IsEmpty (Cola * this);

Bool Cola_IsFull (Cola * this);

void Cola_Dtor (Cola * this);

#endif   /* ----- #ifndef COLA_INC  ----- */