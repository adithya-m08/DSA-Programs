#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"llist.h"

void initList(LLIST* pl)
{
		pl->head=NULL;
		pl->tail=NULL;
}
void insertLast(LLIST* pl,int cf,int px)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->coeff=cf;
	temp->powx=px;
	temp->next=NULL;
	
	NODE *p=pl->head;
	//Empty Case
	if(pl->head==NULL)
	{
		pl->head=temp;
		pl->tail=temp;
		return;
	}
	pl->tail->next=temp;
	pl->tail=temp;
}
void createPoly(LLIST* pl)
{
	int choice,cf,px;
	while(1)
	{
		printf("Enter the coeff and pow\n");
		scanf("%d %d",&cf,&px);
		insertLast(pl,cf,px);
		printf("Do you want to enter a term\n");
		scanf("%d",&choice);
		if(choice==0)
			break;
	}
}
void addPoly(LLIST* pl1,LLIST* pl2,LLIST* pl3)
{
	NODE *p=pl1->head, *q=pl2->head;
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
		insertLast(pl3,cf,px);
	}
	while(p!=NULL)
	{
		cf=p->coeff;
		px=p->powx;
		p=p->next;
		insertLast(pl3,cf,px);
	}
	while(q!=NULL)
	{
		cf=q->coeff;
		px=q->powx;
		q=q->next;
		insertLast(pl3,cf,px);
	}
}
void display(LLIST* pl)
{
	NODE* p=pl->head;
	while(p->next!=NULL)
	{
		printf("(%dx^%d)+",p->coeff,p->powx);
		p=p->next;
	}
	printf("(%dx^%d)\n",p->coeff,p->powx);
}
void destroyList(LLIST *pl)
{
	NODE *p=pl->head,*q=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	pl->head=NULL;
	pl->tail=NULL;
}
/* 
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
} */