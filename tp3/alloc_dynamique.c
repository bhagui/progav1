#include <stdio.h>
#include <stdlib.h>
#define SIZE 5000


int main ()
{
  int i;
  int **mat;
  mat=(int**)malloc(SIZE*sizeof(int*));
  int *v;
  for (i=0;i<SIZE;i++)
    {
      mat[i] = (int*)malloc(SIZE*sizeof(int));
      printf("done");
    }
for (i=0;i<SIZE;i++)
  {
    free(mat[i]);
  }
  free(v);
}
