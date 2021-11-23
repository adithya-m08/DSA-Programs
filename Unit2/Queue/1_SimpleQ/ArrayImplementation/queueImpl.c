#include"queue_Array.h"
#include<stdio.h>

void initQueue(QUEUE *pq)
{
	pq->front=0;
	pq->rear=-1;
}

void enqueue(QUEUE *pq,int ele)
{
	pq->rear++;
	pq->q[pq->rear]=ele;
}

int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	pq->front++;
	
	if(pq->front>pq->rear)
	{
		pq->front=0;
		pq->rear=-1;
	}
	return ele;
}

int isFull(QUEUE *pq)
{
	return pq->rear==MAX-1;
}
int isEmpty(QUEUE *pq)
{
	return pq->front>pq->rear;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
	{
		printf("Empty Queue\n");
		return;
	}
	
	for(int i=pq->front;i<=pq->rear;i++)
		printf("%d ",pq->q[i]);
	printf("\n");
}