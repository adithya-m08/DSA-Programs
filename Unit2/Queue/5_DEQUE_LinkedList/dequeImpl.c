#include"deq.h"
#include<stdio.h>
#include<stdlib.h>

void initQueue(DEQUE* pq)
{
	pq->front=pq->rear=NULL;
}

void insertFront(DEQUE* pq,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->prev=NULL;
	temp->next=NULL;

	if(isEmpty(pq))
	{
		pq->front=pq->rear=temp;
		return;
	}	
	temp->next=pq->front;
	pq->front->prev=temp;
	pq->front=temp;
}
void insertLast(DEQUE* pq,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=pq->rear=temp;
		return;
	}
	temp->prev=pq->rear;
	pq->rear->next=temp;
	pq->rear=temp;
}
int isEmpty(DEQUE* pq)
{
	return pq->front==NULL;
}
int deleteFront(DEQUE* pq)
{
	int ele=pq->front->info;
	if(pq->front==pq->rear)
	{
		free(pq->front);
		pq->front=pq->rear=NULL;
		return ele;
	}
	pq->front=pq->front->next;
	free(pq->front->prev);
	pq->front->prev=NULL;
	return ele;
}
int deleteLast(DEQUE* pq)
{
	int ele=pq->rear->info;
	if(pq->front==pq->rear)
	{
		free(pq->rear);
		pq->front=pq->rear=NULL;
		return ele;
	}
	pq->rear=pq->rear->prev;
	free(pq->rear->next);
	pq->rear->next=NULL;
	return ele;
}

void display(DEQUE* pq)
{
	NODE *p=pq->front;
	
	if(pq->front==NULL)
	{
		printf("Empty List\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}
void destroyQueue(DEQUE* pq)
{
	NODE *p=pq->front,*q=NULL;
	/* while(p!=NULL)
	{
		q=p;		//printf("%d ",p->info);
		p=p->next;
		free(q);
	}
	pdl->head=NULL; */
	if(p==NULL)
		return;
	while(p->next!=NULL)
	{
//		printf("%d ",p->info);
		p=p->next;
		free(p->prev);
	}
//	printf("%d ",p->info);
	free(p);
	pq->front=pq->rear=NULL;
}