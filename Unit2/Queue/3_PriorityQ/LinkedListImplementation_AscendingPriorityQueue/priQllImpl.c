#include<stdio.h>
#include"priQLL.h"
#include<stdlib.h>

void initQueue(PRIQ* pq)
{
	pq->head=NULL;
}
void pqInsert(PRIQ* pq,int ele,int pri)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->pri=pri;
	temp->next=NULL;
	
	NODE *p=pq->head,*q=NULL;
	
	while(p!=NULL && temp->pri>p->pri)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)  //or if(p==pq->head)
	{
		temp->next=pq->head;
		pq->head=temp;
		return;
	}
	temp->next=p;
	q->next=temp;
}

int isEmpty(PRIQ* pq)
{
	return pq->head==NULL;
}
int minDelete(PRIQ* pq)
{
	NODE *p=pq->head;
	int ele=pq->head->info;
	
	pq->head=pq->head->next;
	free(p);
	return ele;
}
void display(PRIQ* pq)
{
	NODE *p=pq->head;
	if(p==NULL)
	{
		printf("Queue is Empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d %d |",p->info,p->pri);
		p=p->next;
	}	
	printf("\n");
}

void destroyQueue(PRIQ* pq)
{
	NODE *p=pq->head;

	while(p!=NULL)
	{
		pq->head=pq->head->next;
		free(p);
		p=pq->head;
	}
}