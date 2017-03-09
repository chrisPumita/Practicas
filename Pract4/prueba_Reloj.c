#include "Reloj.c"

/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
int main(int argc, const char *argv[])
{
	Reloj casio;
	Reloj iwatch;

	Reloj_Set (&iwatch, 9,45);
	Reloj_Set (&casio, 11, 45);
	printf("DIFERENCIA EN MIN: %d\n",Reloj_Diff(&iwatch,&casio));

	return 0;
}