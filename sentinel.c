#include<stdio.h>
void disp(int a[20],int n)
{
  int i;
  printf("Array Elements are :");
  for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
void  check(int a[20],int n)
{
  int i=0,num;
  printf("\nEnter Number to Search :");
  scanf("%d",&num);  
  a[n]=num;
  while(a[i]!=num)
  {
         i++;
  }
  if(i==n)
      printf("\nNumber not Found");
  else
      printf("\nNumber Found at Position=%d",i);
}
int main()
{
     int i,a[100],n,num;
     printf("Enter Limit :");
     scanf("%d",&n);
     printf("Enter n Numbers :");
     for(i=0;i<n;i++)
           scanf("%d",&a[i]);
     disp(a,n);
     check(a,n);
}