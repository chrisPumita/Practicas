
#ifndef  RELOJ_INC
#define  RELOJ_INC

#include <stdio.h>
#include <stdlib.h>

#include "Bool.h"


// aquí van las DECLARACIONES del ADT Reloj, incluyendo la estructura, su typedef
// y las funciones

struct Reloj_Type
{
	int minutos;
	int horas;
};

typedef struct Reloj_Type Reloj;

void Reloj_Set (Reloj * this, int horas, int minutos);

void Reloj_IncHoras (Reloj * this);

void Reloj_IncMinutos (Reloj * this);

void Reloj_Print (Reloj * this);

void Reloj_Tick (Reloj * this);

Bool Reloj_IsEqual (Reloj * this, Reloj * other);

Bool Reloj_IsGreater (Reloj * this, Reloj * other);

Reloj * Reloj_New (int _horas, int _minutos);

void Reloj_Delete (Reloj * this);

int Reloj_Diff(Reloj *this, Reloj * other);

#endif   /* ----- #ifndef RELOJ_INC  ----- */
