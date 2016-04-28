#include <stdio.h>
#define SIZE 1447

int m[SIZE][SIZE];

int main()
{
  int i,j;
 
  for (i=0;i<SIZE;i++)
    {
      for (j=0;j<SIZE;j++)
	{
	  m[i][j]=i+j;
	}
    }
  printf("%d\n", (SIZE*SIZE*sizeof(int)));
}
