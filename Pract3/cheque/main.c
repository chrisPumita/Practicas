#include <stdio.h>
#include <stdlib.h>
#define LIM_NAME 80

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

/*Modelo de la estructura basica del Cheque*/
struct cheque_T
{
	char *e_Name;
	float cantidad;
	int dd, mm, yy;
};

typedef struct cheque_T cheque;

/*Firma de funciones y/o operaciones que realiza Cheque*/
int menu();
void llenar_Cheque(cheque * this, char *nom, float cant, int day, int month, int year);
void imprimir(cheque * this);
//Bool guardar(cheque *this);
void editar(cheque * this, char *nom, float cant, int day, int month, int year);
void ver(cheque * this);

/*Implementacion de los ADTs*/
void llenar_Cheque(cheque * this, char *nom, float cant, int day, int month, int year)
{
	this -> e_Name = (char *)nom;
	this -> cantidad = cant;
	this -> dd = day;
	this -> mm = month;
	this -> yy = year;
}
void imprimir(cheque *this){
	printf("---------------------------------------------\n");
	printf("\tBANCO DE MEXICO\n CHEQUE\n");
	printf("Paguese a: %s la cantidad de $%f M.N.\n",this -> e_Name, this -> cantidad);
	printf("Espedido en la CDMX a %02d / %02d / %02d\n", this -> dd, this -> mm, this -> yy );
	printf("---------------------------------------------\n");
}

void editar(cheque *this, char *nom, float cant, int day, int month, int year){
	this -> e_Name = (char *)nom;
	this -> cantidad = cant;
	this -> dd = day;
	this -> mm = month;
	this -> yy = year;
}

void ver(cheque *this){
	printf("\tBANCO DE MEXICO\nINFORMACION DE CHEQUE\n");
	printf("Cliente: %s  \nMonto: $%f M.N.\n", this -> e_Name, this -> cantidad);
	printf("Fecha de Expedicion: %02d / %02d / %02d\n", this -> dd, this -> mm, this -> yy );
}
/*-----------------------------------------------------------------------------
 *                         menu ()
 *-----------------------------------------------------------------------------*/
int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- LLenar Cheque\n"
					"2 -- Imprimir Cheque\n"
					"3 -- Editar Cheque\n"
					"4 -- Ver Cheque\n"
					"0 -- Terminar\n"
					"Su opción> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 4);

	printf ("\n");
	return opcion;
}

int main()
{
	cheque chequeBanamex;
	char name[LIM_NAME] = "LUIS";
	llenar_Cheque(&chequeBanamex,&name, 150.50, 01, 03, 2017);
	imprimir(&chequeBanamex);
	ver(&chequeBanamex);
	editar(&chequeBanamex, "PEDRO", 300.50, 05, 06, 2016);
	imprimir(&chequeBanamex);
	ver(&chequeBanamex);
    return 0;
}
