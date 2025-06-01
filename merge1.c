#include<stdio.h>
#include<stdlib.h>
#define memory (node *)malloc(sizeof(node))
 typedef struct node
 {
   int data;
   struct node *next;
 }node;

 node * create(node *head)
 {  int n,num,i;
   node *newnode,*temp;
  printf("enter limit of nodes::");
  scanf("%d",&n); 
  for(i=0;i<n;i++)
  {
    newnode=memory;
    printf("enter values of node::");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
  }
  if(head==NULL)
  temp=head=newnode;
  else
   {
   temp->next=newnode;
   temp=newnode;
   }
   return head;
}
 
 void disp(node *head)
{
  node *temp;
  printf("\n linked list::\n");
  for(temp=head;temp!=NULL;temp=temp->next)
  {
   printf("%d\t",temp->data);
  }
}

 
void mergelist(node *head1,node *head2,node *head3)
{
  node *temp1=head1;
  node *temp2=head2,*temp3,*newnode;
  while(temp1!=NULL&&temp2!=NULL)
  {
    newnode=memory;
    newnode->next=NULL;
    if(temp1->data<temp2->data)
    {
      newnode->data=temp1->data;
      temp1=temp1->next;
    }
    else
    {
      newnode->data=temp2->data;
      temp2=temp2->next;
    }
    if(head3==NULL)
     head3=temp3=newnode;
       temp3->next=newnode;
       temp3=newnode;
  }
   while(temp1!=NULL)
    {
      newnode=memory;
      newnode->next=NULL;
      newnode->data=temp1->data;
      temp1=temp1->next;
      temp3->next=newnode;
      temp3=newnode;
    }
    while(temp2!=NULL)
    {
      newnode=memory;
      newnode->next=NULL;
      newnode->data=temp2->data;
      temp2=temp2->next;
      temp3->next=newnode;
      temp3=newnode;
    }
}
 
int main()
{
  node *head1=NULL,*head2=NULL,*head3=NULL;
  head1=create(head1);
  disp(head1);
  head2=create(head2);
  disp(head2);
  printf("\nMerge list :");
  mergelist(head1,head2,head3);
  disp(head3);
}