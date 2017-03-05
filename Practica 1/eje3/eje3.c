#include <stdio.h>
#include <stdlib.h>
#define limPromedios 5
#define limRegistro 5
#define limEscala 7
#define Version 6
/*
TABLA DE CONVERSIÓN. Escriba un programa que en un ciclo lea 5 calificaciones de tipo
real del teclado, y utilizando una tabla de conversión con la escala de nuestro grupo para
registrar calificaciones, guarde en un arreglo la calificación final correspondiente.

*/
int main()
{
  printf("Ejercicio 3, Ver.%d \n",Version );
    double pro[limPromedios];
    int reg[limRegistro];
    double esc[limEscala] = {0.0,5.99,6.5,7.5,8.5,9.5,10};
    /*double esc[limEscala] = {8.7, 8.5, 7.8, 6.5, 5.99};*/
    int pos = 0;
    int i, j, k;
	  for (i = 0; i < limPromedios; ++i){
		    printf("Introduzca promedio de Alumno %d:\n",i+1);
		    scanf("%lf",&pro[i]);
        /* COMPARANDO PROMEDIO CON ARREGLO LIM*/
        for (j = 0; j < limEscala-1; j++) {
          if (pro[i] > esc[j] && pro[i] <= esc[j+1]){
                pos = j;
            switch (pos) {
              case 0:
              reg[i] = 5;
              break;
              case 1:
              reg[i] = 6;
              break;
              case 2:
              reg[i] = 7;
              break;
              case 3:
              reg[i] = 8;
              break;
              case 4:
              reg[i] = 9;
              break;
              case 5:
                reg[i] = 10;
            }
          }
      }
  }
      printf("Alumno:\tCal\t\tCal Altas\n");
	for (k = 0; k < limRegistro; ++k){
    printf("  %d:\t[%lf]\t[%d]\n",k+1, pro[k], reg[k]);
	}
    return 0;
}
