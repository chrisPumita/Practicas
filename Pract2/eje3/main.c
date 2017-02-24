#include <stdio.h>
#include <math.h>
#define LIM_PROM 8
#define LIM_WORDS 5
/*
promedios. Escriba una función que reciba un arreglo de promedios y devuelva el promedio,
Promedio()(en la tabla m es el promedio, en la fórmula es x con barra). Escriba una función que reciba un
arreglo de promedios y devuelva la desviación típica, Sigma(). Escriba una función, Conv(), que reciba
un arreglo de promedios y asigne una calificación en formato de letra (como en el sistema norteamericano)
A, B, C, D y F, según la siguiente tabla:
*/

float media(const float *cal, size_t tamCal){
	float m;
	for (size_t i = 0; i < tamCal; ++i){
		m += cal[i];
	}
	m = m/tamCal;
	printf(" la media es %f\n",m);
	return m;
}

float sigma(const float *cal, int tamCal, float m){
	float s = 0.0;
	for (size_t i = 0; i < tamCal; ++i)
	{
		s = s + ((cal[i])-m)*((cal[i])-m);
	}
	s = s/(tamCal-1.0);
	s = sqrt(s);
	printf("El valor de Sigma es %f\n",s);
	return s;
}

float calculaPromedio(const float *cal, size_t tamCal){
	float pro =  0.0;
	for (size_t i = 0; i < tamCal; ++i)
	{
		pro += cal[i];
	}
	 pro = pro / tamCal;
	 printf("El promedio es %f\n",pro);
	 return pro;
}

void Conv (const float * Prom, char * final, int tamProm){
    float m = media(Prom, tamProm);
    float s = sigma(Prom, tamProm, m);

    int p;
    double A=0,B=0,C=0,D=0,F=0;

    F = m - (1.5*s);
    D = m - (0.5*s);
    C = m + (0.5*s);
    B = m + (0.6666*s);
    A = m + (1.5*s);

	printf("F= %f, D= %f, C= %f, B= %f, A= %f, \n",F,D,C,B,A);

	for (size_t i = 0; i < tamProm; ++i)
	{
		/* Recorriendo todo el arreglo asignando el promedio */
		p = Prom[i];
		printf("El alumno No %d, tiene de promedio: %f y su calificacion es: ",i,Prom[i]);

		if (p <= F)
			{
				printf("F\n");
			}
		else if (p > F && p <= D)
			{
				printf("D\n");
			}
		else if (p > D && p <= C)
			{
				printf("C\n");
			}
		else if (p > C && p <= B)
			{
				printf("B\n");
			}
		else if (p > B)
			{
				printf("A\n");
			}

	}
}

int main(){
    //Enviar las promedios en un array
	float promedios[LIM_PROM] = {9.1, 6.3, 5.5, 8.3, 9.9, 7.2, 8.6, 7.1};
	char letras[LIM_WORDS] = {'F','D','C','B','A'};
    Conv(promedios, letras, LIM_PROM);
    return 0;
}

