 #include <stdlib.h>
 #include <stdio.h>

void Print(int **m, int filas, int cols)
{
	int i, j;
	for (i = 0; i < filas; i++) 
	{
		for (j = 0; j < cols; j++) 
		{
			printf(" %d\t", m[i][j]);
		}
		printf("\n");
	}
}

void destruye_Matriz(int **m){
	
	free(m);
	printf("La matriz fue destruida\n");
}

int** Crea_Matriz(int f,int c)
{
	int **mat;
	int i, j;
	mat = (int **) malloc(f * sizeof(int **));
	for (i = 0; i < f; i++) 
	{
		mat[i] = (int *) malloc(c * sizeof(int));
	}
	for (i = 0; i < f; i++) 
	{
		for (j = 0; j < c; j++) 
		{
			mat[i][j] = 0;
			return mat;
		}
	}
 }

int main()
{
	int filas, columnas;
	int **mat;
	printf("Inglese el numero de columnas\n");
	scanf("%d",&columnas);
	printf("Inglese el numero de filas\n");
	scanf("%d",&filas);
	mat = Crea_Matriz(filas,columnas);

	Print(mat, filas, columnas);

	destruye_Matriz(mat);
	return 0;
}