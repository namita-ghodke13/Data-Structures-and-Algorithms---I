#include<stdio.h>
void accept(int a[50],int n)
{
   int i;
   printf("Enter n Numbers :");
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
}
void display(int a[50],int n)
{
   int i;
   printf("\nSorted Order:");
   for(i=0;i<n;i++)
     printf("%d\t",a[i]);
}
void conquer(int a[50],int s,int mid,int e)
{
 int i,j,k,b[20];
 i=s;
 j=mid+1;
 k=0;
 while((i<=mid)&&(j<=e))
 {
  if(a[i]<a[j])
      b[k++]=a[i++];
  else
      b[k++]=a[j++];
 }
 while(i<=mid)
 {
  b[k++]=a[i++];
 }
 while(j<=e)
 {
  b[k++]=a[j++];
 }
 for(i=s,k=0;i<=e;i++,k++)
 {
  a[i]=b[k];
 }
}
void divide(int a[50],int s,int e)
{
   int mid;
   if(s<e)
   {
    mid=(s+e)/2;
    divide(a,s,mid);
    divide(a,mid+1,e);
    conquer(a,s,mid,e);
   }
}
int main()
{
  int n,a[50];
  printf("Enter Limit :");
  scanf("%d",&n);
  accept(a,n);
  divide(a,0,n-1);
  display(a,n);
}
