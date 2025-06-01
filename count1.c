#include<stdio.h>
void accept(int a[20],int n)
{
   int i;
   printf("Enter n Numbers :");
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
}
void display(int a[20],int n)
{
   int i;
   printf("\nSorted Order:");
   for(i=0;i<n;i++)
     printf("%d\t",a[i]);
}
void count(int a[],int n,int r)
{
 int c[20]={0},i,b[20];
 for(i=0;i<n;i++)
   c[a[i]]=c[a[i]]+1;
 for(i=1;i<=r;i++)
   c[i]=c[i]+c[i-1];
 for(i=n-1;i>=0;i--)
 {
  b[c[a[i]]-1]=a[i];
  c[a[i]]--;
 }
 printf("\nSorted Array :");
 for(i=0;i<n;i++)
   printf("%d\t",b[i]);
}
int main()
{
 int a[20],n,r,i;
 printf("Enter Limit :");
 scanf("%d",&n);
 printf("\nEnter Array Range :");
 scanf("%d",&r);
 accept(a,n);
 count(a,n,r);
}