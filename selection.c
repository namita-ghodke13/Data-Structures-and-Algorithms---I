#include<stdio.h>
void selectionsort(int a[100],int n)
{
    int i,j,t,min,pos;
    for(i=0;i<n;i++)
    {
          min=a[i];
          pos=i;
          for(j=i+1;j<n;j++)
          {
                if(a[j]<min)
                {
                      min=a[j];
                      pos=j;
                }
          }
          t=a[i];
          a[i]=a[pos];
          a[pos]=t;
    }
    printf("\nArray Elements are :");
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
     selectionsort(a,n);
}