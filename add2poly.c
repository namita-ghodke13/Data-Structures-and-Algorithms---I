#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define memory (NODE *)malloc(sizeof(NODE))
typedef struct node
{
  int coef,pow;
  struct node *next;
}NODE;
void create(NODE *head)
{
  NODE *temp=head,*new;
  int i,n;
  printf("\nEnter the no of terms :");
  scanf("%d",&n);
  printf("\nEnter the terms in descending order of power");
  for(i=1;i<=n;i++)
  {
    new=memory;
    new->next=NULL;
    printf("\nEnter Coefficient and power :");
    scanf("%d%d",&new->coef,&new->pow);
      temp->next=new;
      temp=new;
  }
}
void display(NODE *head)
{
  NODE *temp;
  for(temp=head->next;temp!=NULL;temp=temp->next)
  {
    printf("%dx^%d+",temp->coef,temp->pow);
  }
}
NODE *addpoly(NODE *head1,NODE *head2,NODE *head3)
{
  NODE *temp1=head1->next,*temp2=head2->next,*temp3=head3,*new;
  int i;
  while((temp1!=NULL)&&(temp2!=NULL))
  {
    new=memory;
    new->next=NULL;
    if(temp1->pow>temp2->pow)
    {
      new->pow=temp1->pow;
      new->coef=temp1->coef;
      temp1=temp1->next;
    }
    else if(temp1->pow<temp2->pow)
    {
      new->pow=temp2->pow;
      new->coef=temp2->coef;
      temp2=temp2->next;
    }
    else
    {
      new->pow=temp1->pow;
      new->coef=temp1->coef+temp2->coef;
      temp1=temp1->next;
      temp2=temp2->next;
    }
    temp3->next=new;
    temp3=new;
  }
  while(temp1)
  {
    new=memory;
    new->next=NULL;
    new->pow=temp1->pow;
    new->coef=temp1->coef;
    temp3->next=new;
    temp3=new;
    temp1=temp1->next;
  }
  while(temp2)
  {
    new=memory;
    new->next=NULL;
    new->pow=temp2->pow;
    new->coef=temp2->coef;
    temp3->next=new;
    temp3=new;
    temp2=temp2->next;
  }
}
void main()
{
  NODE *head1,*head2,*head3;
  head1=memory;
  head1->next=NULL;
  head2=memory;
  head2->next=NULL;
  head3=memory;
  head3->next=NULL;
  create(head1);
  display(head1);
  create(head2);
  display(head2);
  addpoly(head1,head2,head3);
  printf("\nThe Addition is :");
  display(head3);
}