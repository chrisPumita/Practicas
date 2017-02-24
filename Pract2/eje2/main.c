#include <stdio.h>
#define LimPalabra1 10
#define LimPalabra2 10
/*CADENAS. Escribirá su propia versión de la función strcpy() y la nombrará miStrCpy(). La firma de la
función será:
int miStrCpy (char * destino, const char * fuente);
En este ejercicio Ud. utilizará la aritmética de apuntadores, en especial el operador de pre-incremento, ++, y un
ciclo while; NO use ciclos for. El valor devuelto es la cantidad de caracteres copiados desde fuente hacia
destino, sin incluir el nulo, \0. Pruebe la función en su driver program.*/

int miStrCpy(char *destino, const char *fuente){
	int cont = 0;

	while(*fuente != '\0'){
		++cont;
		*destino = *fuente;
		++fuente;
		++destino;
	}
	*destino = '\0';
	return cont;
	/*Comparacion final de cadena '\0' */
}

int main()
{
    char destino[80];
    char fuente[80] = "HolaMundo";
    int contador = miStrCpy(destino, fuente);
    printf("Se agregaron %d y la palabra es: %s\n",contador,destino);
    return 0;
}
