#include<stdio.h>
void insertion(int a[100],int n)
{
     int i,j,t,num;
     for(i=1;i<n;i++)
     {
          num=a[i];
          for(j=i-1;j>=0&&num<a[j];j--)
          {
               t=a[j+1];
               a[j+1]=a[j];
               a[j]=t;
          }
     }
     printf("\nSorted Numbers:");
     for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
     int a[100],i,n;
     printf("Enter Limit :");
     scanf("%d",&n);
     printf("Enter n Numbers :");
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     insertion(a,n);
}
