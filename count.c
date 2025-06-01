#include<stdio.h>
void countsort(int a[],int k,int n)
{
 int i,c[50]={0},b[20];
 for(i=0;i<n;i++)
   c[a[i]]=c[a[i]]+1;
 for(i=1;i<=k;i++)
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
 int a[10],i,k,n;
 printf("Enter Limit :");
 scanf("%d",&n);
 printf("\nEnter Range :");
 scanf("%d",&k);
 printf("\nEnter n Elements :");
 for(i=0;i<n;i++)
   scanf("%d",&a[i]);
 countsort(a,k,n);
}