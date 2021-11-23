#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"llist.h"

void insertLast(NODE** phead,int cf,int px)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->coeff=cf;
	temp->powx=px;
	temp->next=NULL;
	
	NODE *p=*phead;
	//Empty Case
	if(*phead==NULL)
	{
		*phead=temp;
		return;
	}
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}
void createPoly(NODE** phead)
{
	int choice,cf,px;
	while(1)
	{
		printf("Enter the coeff and pow\n");
		scanf("%d %d",&cf,&px);
		insertLast(phead,cf,px);
		printf("Do you want to enter a term\n");
		scanf("%d",&choice);
		if(choice==0)
			break;
	}
}
void addPoly(NODE* head1,NODE* head2,NODE** head3)
{
	NODE *p=head1, *q=head2;
	int px,cf;
	while(p!=NULL && q!=NULL)
	{
		if(p->powx == q->powx)
		{
			cf=p->coeff+q->coeff;
			px=p->powx;
			p=p->next;
			q=q->next;
		}
		else if(p->powx > q->powx)
		{
			cf=p->coeff;
			px=p->powx;
			p=p->next;
		}
		else
		{
			cf=q->coeff;
			px=q->powx;
			q=q->next;
		}
		insertLast(head3,cf,px);
	}
	while(p!=NULL)
	{
		cf=p->coeff;
		px=p->powx;
		p=p->next;
		insertLast(head3,cf,px);
	}
	while(q!=NULL)
	{
		cf=q->coeff;
		px=q->powx;
		q=q->next;
		insertLast(head3,cf,px);
	}
}
void display(NODE* phead)
{
	NODE* p=phead;
	while(p->next!=NULL)
	{
		printf("(%dx^%d)+",p->coeff,p->powx);
		p=p->next;
	}
	printf("(%dx^%d)\n",p->coeff,p->powx);
}
void destroyList(NODE** phead)
{
	NODE *p=*phead,*q=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*phead=NULL;
}

int evalPoly(NODE* phead,int x)
{
	int sum=0;
	NODE *p=phead;
	while(p!=NULL)
	{
		sum=sum+p->coeff*pow(x,p->powx);
		p=p->next;
	}
	return sum;
}