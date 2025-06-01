#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
typedef struct node
{
  int data;
  struct node *next;
}Node;
Node *createlist(Node *head)
{
  int n,i,value;
  Node *new,*temp;
  printf("Enter Limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=memory;
    printf("Enter Value :");
    scanf("%d",&value);
    new->data=value;
    if(head==NULL)
    {
      head=temp=new;
      new->next=head;
    }
    else
    {
      temp->next=new;
      new->next=head;
      temp=new;
    }
  }
  return head;
}
void display(Node *head)
{
  Node *temp=head;
  do
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  } while(temp!=head);
}
void search(Node *head,int num)
{
  Node *temp;
  int f=0,i;
  for(temp=head->next,i=1;temp!=head;temp=temp->next,i++)
  {      
       if(temp->data==num)
       {
             f=1;
             break;
       }
  }
  if(f==1)
     printf("Data Found at Position =%d",i);
  else
     printf("Data not Found");
}
void insert(Node *head,int num,int pos)
{
  Node *new,*temp;
  int i;
  new=memory;
  new->data=num;
  for(i=1,temp=head;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
  new->next=temp->next;
  temp->next=new;
}
void deletepos(Node *head,int pos)
{
  Node *temp,*temp1;
  int i;
  for(temp=head,i=1;(temp->next!=head)&&(i<pos-1);i++,temp=temp->next);
  temp1=temp->next;
  temp->next=temp1->next;
  free(temp1);
}
void deletevalue(Node *head,int num)
{
  Node *temp,*temp1;
  for(temp=head;temp->next!=head;temp=temp->next)
  if(temp->next->data==num)
  {
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return;
  }
  printf("\nElement not Found");
}
int main()
{
  Node *head=NULL;
  int pos,num,ch;
  head=createlist(head);
  display(head);
  do
  {
   printf("\nMENU-");
   printf("\n1-Search");
   printf("\n2-Insert");
   printf("\n3-Delete by Position");
   printf("\n4-Delete by Value");
   printf("\n5-Display");
   printf("\nEnter Your Choice :");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:printf("\nEnter Number to Search :");
           scanf("%d",&num);
           search(head,num);
           break;
    case 2:printf("\nEnter Number to Insert :");
           scanf("%d",&num);
           printf("Enter Position :");
           scanf("%d",&pos);
           insert(head,num,pos);
           printf("\nNode Inserted Successfully");
           break;
    case 3:printf("\nEnter Position to Delete :");
           scanf("%d",&pos);
           deletepos(head,pos);
           printf("\nNode Deleted Successfully");
           break;
    case 4:printf("\nEnter Number to Delete :");
           scanf("%d",&num);
           deletevalue(head,num);
           printf("\nNode Deleted Successfully");
           break;
    case 5:display(head);
           break;
    default :printf("\nInvalid Choice...");
             break;
   }
  }while(ch<6);
}