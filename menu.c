#include<stdio.h>
int linearsearch(int a[100],int n,int key)
{
  int i;
  printf("\nEnter Key :");
  scanf("%d",&key);
  for(i=0;i<n;i++)
  {
       if(a[i]==key)
       {
           return i;
       }
  }
  return -1;
}
void  sentinelsearch(int a[100],int n)
{
        int key,i=0;
        printf("\nEnter Key :");
        scanf("%d",&key);  
        a[n]=key;
        while(a[i]!=key)
        {
             i++;
        }
        if(i==n)
             printf("\nNumber not Found");
        else
             printf("\nNumber Found at Position=%d",i);
}
int binarysearch(int a[100],int n)
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
     int n,a[100],i,ch,key,pos;
     printf("Enter Limit :");
     scanf("%d",&n);
     printf("Enter n Numbers :");
     for(i=0;i<n;i++)
          scanf("%d",&a[i]);
     do
     {
          printf("\nMENU-\n");
          printf("\n1-Linear Search \n2-Sentinel Search \n3-Binary Search");
          printf("\nEnter Your Choice :");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:pos=linearsearch(a,n,key);
                      if(pos==-1)
                         printf("\nNumber not Found");
                      else
                         printf("\nNumber Found at Position=%d",pos);
                      break;
               case 2:sentinelsearch(a,n);
                            break;
               case 3:pos=binarysearch(a,n);
                      if(pos==-1)
                         printf("\nNumber not Found");
                      else
                         printf("\nNumber Found at Position=%d",pos); 
                      break;
             default :printf("\nInvalid Choice...");
                      break;                                                          
          }
     } while (ch<4);
}