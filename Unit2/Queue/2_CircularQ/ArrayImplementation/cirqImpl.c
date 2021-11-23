#include"cirq.h"
#include<stdio.h>

void initQueue(QUEUE *pq)
{
	pq->front=pq->rear=MAX-1;
}
void enqueue(QUEUE *pq,int ele)
{
	pq->rear=(pq->rear+1)%MAX;
	pq->q[pq->rear]=ele;
}
int dequeue(QUEUE *pq)
{
	pq->front=(pq->front+1)%MAX;
	return pq->q[pq->front];
}

int isFull(QUEUE *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}
int isEmpty(QUEUE *pq)
{
	return pq->rear==pq->front;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
	{
		printf("Queue is empty\n");
		return;
	}
	
	int i=(pq->front+1)%MAX;
	while(i!=pq->rear)
	{
		printf("%d ",pq->q[i]);
		i=(i+1)%MAX;
	}
	printf("%d\n",pq->q[i]);
}