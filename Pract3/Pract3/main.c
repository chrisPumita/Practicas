#include <stdio.h>
#include <unistd.h>
// para la función sleep ()


enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;


/*-----------------------------------------------------------------------------
 *  Definición del ADT: reloj.h
 *-----------------------------------------------------------------------------*/
struct Reloj_Type
{
	int minutos;
	int horas;
};

typedef struct Reloj_Type Reloj;

/**
 * @brief Pone la hora en el reloj
 *
 * @param this Referencia a un objeto de tipo Reloj
 * @param horas Las horas
 * @param minutos Los minutos
 */
void Reloj_Set (Reloj * this, int horas, int minutos);

/**
 * @brief Incrementa las horas en una unidad
 *
 * @param this Referencia a un objeto de tipo Reloj
 */
void Reloj_IncHoras (Reloj * this);

/**
 * @brief Incrementa los minutos en una unidad
 *
 * @param this Referencia a un objeto de tipo Reloj
 */
void Reloj_IncMinutos (Reloj * this);

/**
 * @brief Imprime en la pantalla la hora actul
 *
 * @param this Referencia a un objeto de tipo Reloj
 */
void Reloj_Print (Reloj * this);

/**
 * @brief Incrementa la hora del reloj en un minuto. Aplica un roll-over sobre
 * los minutos y las horas
 *
 * @param this Referencia a un objeto de tipo Reloj
 */
void Reloj_Tick (Reloj * this);

/**
 * @brief Indica si son iguales o no la hora de dos relojes
 *
 * @param this Referencia a un objeto de tipo Reloj
 * @param other Referencia al segundo reloj
 *
 * @return TRUE si las horas son iguales, FALSE en cualquier otro caso
 */
Bool Reloj_IsEqual (Reloj * this, Reloj * other);

/**
 * @brief Indica si la hora de un reloj es mayor que la del otro
 *
 * @param this Referencia a un objeto de tipo Reloj
 * @param other Referencia al segundo reloj
 *
 * @return TRUE si la hora en this es mayor que la de la hora en other, FALSE en
 * cualquier otro caso
 */
Bool Reloj_IsGreater (Reloj * this, Reloj * other);

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

/*-----------------------------------------------------------------------------
 *                         menu ()
 *-----------------------------------------------------------------------------*/
int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Muestra la hora\n"
					"2 -- Incrementa las horas\n"
					"3 -- Incrementa los minutos\n"
					"4 -- Avanza al reloj 30 minutos\n"
					"5 -- Compara relojes CASIO Y iWatch\n"
					"0 -- Terminar\n"
					"Su opción> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 4);

	printf ("\n");
	return opcion;
}

/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
int main(int argc, const char *argv[])
{
	Reloj casio;
	Reloj iwatch;
	Reloj_Set (&casio, 20, 54);
	Reloj_Set (&iwatch, 20,52);

	//printf("Ver 1.0 \n\tSeleccione una opcion:\n");
	printf("La hora del Reloj 1 es %d:%d\n", casio.horas,casio.minutos);
	printf("La hora del Reloj 2 es %d:%d\n", iwatch.horas,iwatch.minutos);
	if(Reloj_IsEqual(&casio, &iwatch) == TRUE){
		printf("Los relojes Son iguales\n");
	}
	else{
		printf("Los Relojes No son iguales\n");
	}

	if(Reloj_IsGreater(&casio,&iwatch) == TRUE)
		printf("La hora del Reloj 1 es mayor a la del Reloj 2");
	else
		printf("El reloj 2 es mayor");




#if 0
	while (1)
	{
		int opcion = menu ();

		switch (opcion) {
			case 0:
				printf ("Terminando ...\n");
				return 0;

			case 1:
				printf ("Muestra la hora ... \n");
				Reloj_Print (&casio);
				break;

			case 2:
				printf ("Incrementa las horas ...\n");
				Reloj_IncHoras (&casio);
				break;

			case 3:
				printf ("Incrementa los minutos ...\n");
				Reloj_IncMinutos (&casio);
				break;

			case 4:
				printf ("Avanza la hora 30 minutos ...\n");

				for (int i = 0; i < 30; ++i) {
					Reloj_Tick (&casio);
					sleep (1);
					Reloj_Print (&casio);
				}
				break;

			case 5:
				if(Reloj_IsEqual(&casio, &iwatch) == TRUE){
					printf("Son iguales\n");
				}
				else{
					printf("No son iguales\n");
				}
				break;

			default:
				printf ("Operación no válida!\n");
				break;
		}
	}
#endif
	return 0;
}
