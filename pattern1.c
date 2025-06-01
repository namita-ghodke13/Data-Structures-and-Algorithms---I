#include<stdio.h>

void main()
{
  int row,col;
  printf("Enter the number of row and col value : \n");
  scanf("%d%d\n",&row,&col);

  int i,j;
  for(i = 1; i <= row; i++)
  {
    for(j = 1; j <= col; j++)
    {
        if(i == j)
        {
          printf("@\t");
        }
        else{
          printf("#\t");
        }
    }
    printf("\n");
  }
}