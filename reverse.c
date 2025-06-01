#include<stdio.h>
#include"doublylist.h"
void revlist(Node *head)
{
  Node *temp=head,*n,*prev=NULL;
  while(temp!=NULL)
  {
     n=temp->next;
     temp->next=temp->prev;
     temp->prev=n;
     temp=n;
  }
  n=head;
  head=prev;
  prev=n
}
int main()
{
  Node *head;
  head=createlist(head);
  revlist(head);
}