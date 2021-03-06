
#include "Reloj.h"


/*-----------------------------------------------------------------------------
 *  Implementación del ADT reloj: reloj.c
 *-----------------------------------------------------------------------------*/
void Reloj_Set (Reloj * this, int horas, int minutos)
{
	this->minutos = minutos;
	this->horas = horas;
}

void Reloj_IncHoras (Reloj * this)
{
	++this->horas;
	if (this->horas > 23 ) {
		this->horas = 0;
	}
}

void Reloj_IncMinutos (Reloj * this)
{
	++this->minutos;
	if (this->minutos > 59 ) {
		this->minutos = 0;
	}
}

void Reloj_Print (Reloj * this)
{
	printf ("%02d : %02d\n", this->horas, this->minutos);
}

void Reloj_Tick (Reloj * this)
{
	++this->minutos;
	if (this->minutos > 59) {
		this->minutos = 0;

		++this->horas;
		if (this->horas > 23) {
			this->horas = 0;
		}
	}
}

Bool Reloj_IsEqual (Reloj * this, Reloj * other)
{
	// Agregue el código necesario para determinar si las horas son iguales o no
	int regreso = 0;
	if (this->horas == other->horas)
	{
		regreso = 1;
		if (this-> minutos == other->minutos)
				regreso = 1;
		else
			regreso = 0;
	}
	return regreso;
}

Bool Reloj_IsGreater (Reloj * this, Reloj * other)
{
	// Agregue el código necesario para determinar si la hora en this es mayor
	// que la hora en other
	int regreso = 0;
	if (this-> minutos > other->minutos)
	{
		if (this -> horas >= other -> horas )
		{
					regreso = 1;
		}
	}

	 else if (this -> horas > other -> horas)
	{
		regreso = 1;
	}
	return regreso;
}


Reloj * Reloj_New (int _horas, int _minutos){
	if (_horas >23){ _horas = 0; }
	if (_horas <0){ _horas = 0; }

	if (_minutos >23){ _minutos = 0; }
	if (_minutos <0){ _minutos = 0; }


	Reloj *p = (Reloj *)malloc(sizeof (Reloj));
	if (p != NULL)
	{
		p -> horas   = _horas;
		p -> minutos = _minutos;
	}
	return p;
}

void Reloj_Delete (Reloj * this){
	if (this != NULL)
	{
		free(this);
		this = NULL;
		printf("ELEMENTO ELIMINADO\n");
	}
}

int DifHoras(int H, int M){
	if (M > 12)
	{
		/* Se han excedido los Minuto */
		M += (H)*60;
	}
	return M;
}

