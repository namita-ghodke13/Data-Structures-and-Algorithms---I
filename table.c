#include<stdio.h>
int main()
{
  int n,i;
  printf("Enter Numbers :");
  scanf("%d",&n);
  printf("Table =\n",n);
  for(i=1;i<=10;i++)
  {
     printf("%d\n",n*i);
  }
}