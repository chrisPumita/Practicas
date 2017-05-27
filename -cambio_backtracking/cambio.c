

#include <stdlib.h>
#include <stdio.h>

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

Bool EsFactible (int c, int p, int acum)
{
	if ((c+acum) <= p) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Bool EsSolucion (int p, int acum)
{
	if (acum == p) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}



Bool bt (int c[], int i, int j, int s[], int* s_idx, int p, int* acum)
{
	Bool success = FALSE;
	// termina cuando encuentre una solución

	for (int x = i; x < j; ++x) {

		if (success == TRUE) { return TRUE; }
		// ya no revisa los candidatos restantes una vez que se obtuvo una
		// solución

		printf ("\nProbando al candidato <%d>\n", c[x]);

		if (EsFactible (c[x], p, *acum)) {

			// registra al candidato:
			int cand = c[x];
			s[*s_idx] = cand;
			++*s_idx;
			*acum += cand;

			printf ("Registrando al candidato <%d>\n", cand);

			if (!EsSolucion (p, *acum)) {
				success = bt (	c, x+1, j, 
								s, s_idx,
								p, acum);

				if (success == FALSE) {

					// cancela el registro:
					--*s_idx;
					*acum -= cand;

					printf ("Borrando al candidato <%d>\n", cand);
				}
			}
			else {
				printf ("Se encontró una solución!!\n");
				return TRUE;
			}
		}
		else {
			printf ("El candidato <%d> no es factible\n", c[x]);
		}
	}

	printf ("Se terminaron los candidatos\n");
	return FALSE;
}



/*--------------------------------------------------------------------------*/
/**
 * @brief Función de activación
 *
 * @param c[] Conjunto de candidatos
 * @param tam_c Número de candidatos
 * @param s[] Conjunto solución
 * @param tam_s Número máximo de elementos en el conjunto solución
 * @param p Instancia particular del problema
 *
 * @return El tamaño del conjunto solución; si es cero, entonces no se encontró
 * ninguna solución
 */
/*--------------------------------------------------------------------------*/
int Cambio (int c[], int tam_c, int s[], int tam_s, int p)
{
	int acum = 0;
	int s_idx = 0;

	Bool res = bt (	c, 0, tam_c, // envía al conjunto de candidatos completo
					s, &s_idx,	// conjunto solución
					p,			// instancia particular del problema
					&acum);		// acumulador

	return s_idx;
}


int main(void)
{
	int candidatos[5] = {1, 2, 5, 5, 3};
	
	int solucion[5] = {};
	// a lo más, habrá 5 monedas
	
	int p = 15;

	int res = Cambio (candidatos, 5, solucion, 5, p);

	if (res > 0) {
		printf ("La solución es: \n");
		for (int i = 0; i < res; ++i) {
			printf ("%d\n", solucion[i]);
		}
	}
	else {
		printf ("No se encontró una solución\n");
	}
	
	return 0;
}

