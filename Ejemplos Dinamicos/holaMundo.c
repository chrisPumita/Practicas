#include <stdio.h>

void imprimeHola(int veces){
	int i;
	for (i = 0; i < veces; i++)
	{
		printf("%d - HOLA MUNDO :3\n",i);
	}
}

int main()
{
	printf("CUANTAS VECES QUIERES IMPRIMIR? :\n");
	int veces = 0;
	scanf("%d",&veces);
	imprimeHola(veces);
	return 0;
}
