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
  Node *new,*temp;
  int n,i,value;
  printf("Enter Limit :");
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
  {
    new=memory;
    printf("Enter Element for %d node:" ,i+1);
    scanf("%d",&value);
    new->data=value;
    if(head==NULL)
    {
      head=temp=new;
    }
    else
    {
      new->next=head;
      temp->next=new;
      temp=new;
    }
  }
  return head;
}
void display(Node *head)
{
  Node *temp;
  printf("\nLinked List is -\n");
  for(temp=head;temp->next!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
void insertbypos(Node *head,int num,int pos)
{
 Node *new,*temp,*temp1;
 int i;
 for(temp=head,i=1;(temp->next!=head)&&(i<pos-1);i++)
    temp=temp->next;
 if(i<pos-1)
 {
   printf("\nPosition is out of Range");
   return;
 }
 new=memory;
 new->data=num;
 temp1=temp->next;
 new->next=temp1;
 temp->next=new;
}
void search(Node *head)
{
  Node *temp;
  int f=0,n;
  printf("\nEnter Number to Search :");
  scanf("%d",&n);
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    if(temp->data==n)
    {
      f=1;
      break;
    }
  }
  if(f==1)
     printf("Number is Found");
  else
     printf("Number is not Found");
}
void delbypos(Node *head,int pos)
{
  int i;
  Node *temp1,*temp;
  for(temp=head,i=1;(temp->next!=head)&&(i<pos-1);i++)
     temp=temp->next;
  if(i<pos-1)
  {
        printf("\nPosition is out of Range");
        return;
  }
  temp1=temp->next;
  temp->next=temp1->next;
  free(temp1);
}
void delbyvalue(Node *head,int num)
{
  Node *temp,*temp1;
  for(temp=head;temp->next!=head;temp=temp->next)
  {
    if(temp->next->data==num)
    {
      temp1=temp->next;
      temp->next=temp1->next;
      free(temp1);
      return;
    }
  }
  printf("Element not Found");
}
void main()
{
 int ch,num,pos;
 Node *head=NULL;
 head=createlist(head);
 do
 {
   printf("\n------MENU------");
   printf("\n1-Insert by Position");
   printf("\n2-Search");
   printf("\n3-Delete by Position");
   printf("\n4-Delete by Value");
   printf("\n5-DISPLAY");
   printf("\nEnter Your Choice :");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1: printf("\nEnter ELement to insert :");
             scanf("%d",&num);
             printf("\nEnter Position :");
             scanf("%d",&pos);
             insertbypos(head,num,pos);
             break; 
     case 2: search(head);
             break;
     case 3: printf("Enter Position to delete :");
             scanf("%d",&pos);
             delbypos(head,pos);
             break;
     case 4: printf("Enter Number to delete :");
             scanf("%d",&num);
             delbyvalue(head,num);
             break;
     case 5: display(head);
             break;
     default:printf("INVALID CHOICE...");
             break;
   }
 }while(ch<6);
}
