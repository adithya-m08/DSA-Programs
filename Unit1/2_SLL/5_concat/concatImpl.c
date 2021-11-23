#include<stdio.h>
#include"llist.h"
#include<stdlib.h>

struct node *insertBeg(NODE* head,int ele)
{
	NODE*temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	
	temp->next=head;
	head=temp; return head;
//	return temp;
}

void display(NODE* head)
{
	NODE* p=head;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}	
	printf("\n");
}

NODE* concat(NODE* head1,NODE* head2)
{
	if(head2==NULL)
		return head1;
	if(head1==NULL)
		return head2;
	NODE *p=head1;
	while(p->next!=NULL)
		p=p->next;
	p->next=head2;
	return head1;
}

NODE* destroyList(NODE* phead)
{
	NODE *p=phead,*q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	phead=NULL;
	return phead;
}

