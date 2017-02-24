#include <stdio.h>
#define TAM_MAX 5
/*BÚSQUEDA LINEAL. Escriba una función Buscar() que reciba un arreglo de enteros y un valor a buscar
dentro de dicho arreglo. La función devolverá el índice del elemento donde hubiera encontrado la coincidencia,
ó -1 en caso de no haberla encontrado. En el caso de múltiples coincidencias, únicamente devolverá el índice de
la primera encontrada. La firma de la función será:
int Buscar (const int * arreglo, int tam);
Dentro de la función Ud. deberá utilizar notación de apuntadores, y en especial la de “dirección base +
desplazamiento”. Pruebe la función en su driver program.*/

//int Buscar(const int *arreglo, int tam, int clave);
int Buscar(const int *arreglo, int tam, int clave){
	int indice = -1;
	for (size_t i = 0; i < tam; ++i)
	{
		if (*(arreglo+i)==clave)
		{
			indice = i;
		}
	}
	return indice;
}
int main()
{
	int lista[TAM_MAX] = {6,8,2,0,9};
	int numBusq = 6;
	int valorIndice = Buscar(lista, TAM_MAX, numBusq);
	if (valorIndice > -1)
		printf("El numero %d esta en el indice: %d\n",numBusq, valorIndice);
	else
		printf("No se existe el numero en el arreglo\n");
}
