 
#include<stdio.h>
#include<stdlib.h>
struct complejo
{
int real;
int ima;
};
struct complejo **creaMatriz(int n, int m);
void llenaMatriz( struct complejo **ap,int n, int m);
void sumaMatriz(struct complejo **ap1, struct complejo **ap2, struct complejo **apc, int n, int m);
void ImprimeMatriz( struct complejo **ap,int n, int m);
void liberaMatriz( struct complejo **ap,int n);

int main(){
struct complejo **A,**B,**C;
int n=2,m=2;
A=creaMatriz(n,m);
B=creaMatriz(n,m);
C=creaMatriz(n,m);
printf("\n >>> Matriz 1\n");
llenaMatriz(A,n,m);
printf("\n >>> Matriz 2\n");
llenaMatriz(B,n,m);
sumaMatriz(A,B,C,n,m);
ImprimeMatriz(C,n,m);
//liberaMatriz( struct complejo **ap,int n)
return 0;
}

struct complejo **creaMatriz(int n,int m)
{
    int i;
    struct complejo **ap;
    ap=(struct complejo **)malloc(n*sizeof(struct complejo *));
    for(i=0;i<n;i++)
    {
        *(ap+i)=(struct complejo*)malloc(n*sizeof(struct complejo));
    }
    return ap;}

void llenaMatriz( struct complejo **ap,int n, int m)
{
    int i,j;
    for (i=0;i<n;i++){

      for(j=0;j<n;j++)
      {
          printf("Introduce parte real e \nimaginaria separadas por un espacio \n");
          scanf("%d %d",&(*(ap+i)+j)->real,&(*(ap+i)+j)->ima);
          printf("\n%d + ",(*(ap+i)+j)->real);
          printf("%di",(*(ap+i)+j)->ima);
          printf("\n");
      }
    }
}

void sumaMatriz(struct complejo **ap1, struct complejo **ap2, struct complejo **apc, int n, int m)
{  int i,j;
   for(i=0;i<n;i++){
      for(j=0;j<m;j++)
     {
         ((*(apc+i)+j)->real)=((*(ap1+i)+j)->real)+((*(ap2+i)+j)->real);
         ((*(apc+i)+j)->ima)=((*(ap1+i)+j)->ima)+((*(ap2+i)+j)->ima);
     }
   }

}

void ImprimeMatriz( struct complejo **ap,int n, int m)
{
  int i,j;
  printf("\nLA NUEVA MATRIZ ES: \n");
  for (i=0;i<n;i++){
    for(j=0;j<m;j++)
    {
        printf("%d + ",ap[i][j].real);
        printf("%di",ap[i][j].ima);
        printf("\t");
    }
       printf("\n");
  }
}

