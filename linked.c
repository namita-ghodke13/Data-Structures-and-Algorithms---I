#include<stdio.h>
#include<malloc.h>
typedef struct node 
{
  int data;
  struct node *next;
}NODE;
NODE *create(NODE *head)
{
  NODE *newnode,*temp;
  int n,i;
  printf("Enter Limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=(NODE *)malloc(sizeof(NODE));
    printf("Enter value : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
       {
           head=newnode;
           temp=newnode;
       }
       else
       {
           temp->next=newnode;
           temp=newnode;
       }
   }
   return head ;
}void display(struct node *head)
{
   struct node *temp;
   for(temp=head;temp!=NULL;temp=temp->next)
   {
       printf("%d\t",temp->data);
   }
}
int main()
{
    int ch,num;
    struct node *head=NULL;
       head=create(head);            
        display(head);
}
         
        
