#include<stdio.h>
int binary_search(int a[100],int n)
{
   int key,top,bottom,mid;
   printf("Enter Key to Search :");
	  scanf("%d",&key);
   top=0;
   bottom=n-1;
   while(top<=bottom)
    {
    	mid=(top+bottom)/2;
    	if(a[mid]==key)
    	      	return mid;
		   if(key>a[mid])
		        top=mid+1;
		   else 
		        bottom=mid-1;
	   }
    return -1;
}
int main()
{
	int a[100],n,i,pos;
	printf("Enter limit :");
	scanf("%d",&n);
	printf("Enter n Numbers  :");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
    pos=binary_search(a,n);
   	if(pos==-1)
       printf("\nNumber not Found..");
    else
       printf("\nNumber Found at Position=%d",pos);
}