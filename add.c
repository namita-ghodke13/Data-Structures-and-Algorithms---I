#include<stdio.h>
void disp(int a[20],int n)
{
  int i;
  printf("Array Elements are =");
  for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
int check(int a[20],int n)
{
  int i,num,f=0;
  printf("\nEnter Number to Search :");
  scanf("%d",&num);
  for(i=0;i<n;i++)
  {
       if(a[i]==num)
       {
           f=1;
           return i;
       }
  }
  return -1;
}
int main()
{
     int i,a[20],n,num,pos;
     printf("Enter Limit :");
     scanf("%d",&n);
     printf("Enter n Numbers :");
     for(i=0;i<n;i++)
           scanf("%d",&a[i]);
     disp(a,n);
     pos=check(a,n);
     if(pos==-1)
         printf("\nNumber not Found");
     else
         printf("\nNumber Found at Position=%d",pos);
}