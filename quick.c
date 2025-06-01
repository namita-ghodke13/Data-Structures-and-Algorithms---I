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
   printf("\nSorted Array:");
   for(i=0;i<n;i++)
     printf("%d\t",a[i]);
}
int quicksort(int a[50],int s,int e)
{
 int pivot,next,prev,t;
 pivot=a[s];
 next=s+1;
 prev=e;
 do
 {
   while((a[next]<pivot)&&(next<=e))
   {
    next++;
   }
   while((a[prev]>pivot)&&(prev>s))
   {
    prev--;
   }
   if(next<prev)
   {
     t=a[prev];
     a[prev]=a[next];
     a[next]=t;
   }
 } while(next<prev); 
 a[s]=a[prev];
 a[prev]=pivot;
  return prev;
}
void divide(int a[50],int s,int e)
{
 int p;
 if(s<e)
 {
  p=quicksort(a,s,e);
  divide(a,s,p-1);
  divide(a,p+1,s);
 }
}
int main()
{
 int a[50],n;
 printf("Enter Limit :");
 scanf("%d",&n);
 accept(a,n);
 divide(a,0,n-1);
 display(a,n);
}