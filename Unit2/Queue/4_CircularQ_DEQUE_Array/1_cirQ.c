//Circular Queue: Array Implmntn, front and rear set to -1
#include<stdio.h>
#define MAX 5
typedef struct queue
{
	int q[MAX];
	int front,rear;	
}QUEUE;

void initQueue(QUEUE *pq)
{
	pq->front=pq->rear=-1;
}

int isFull(QUEUE *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}

int isEmpty(QUEUE *pq)
{
	return pq->rear==-1;	//pq->front=-1
}

void enqueue(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[pq->rear]=ele;
		return;
	}
	pq->rear=(pq->rear+1)%MAX;
	pq->q[pq->rear]=ele;
}
int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	if(pq->front==pq->rear)
		initQueue(pq);
	else
		pq->front=(pq->front+1)%MAX;
	return ele;
}

void display(QUEUE *pq)
{
	if(isEmpty(pq))
	{
		printf("Queue is empty\n");
		return;
	}
	
	int i=(pq->front)%MAX;
	while(i!=pq->rear)
	{
		printf("%d ",pq->q[i]);
		i=(i+1)%MAX;
	}
	printf("%d\n",pq->q[i]);
}

int main()
{
	QUEUE q;

	initQueue(&q);
	
	int choice,ele;
	
	printf("1.Enq 2.Deq 3.IsFull 4.IsEmpty 5.Display\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an ele\n");
					scanf("%d",&ele);
					if(isFull(&q))
						printf("Queue is already full\n");
					else
						enqueue(&q,ele);
					break;
			case 2:if(isEmpty(&q))
						printf("Queue is already empty\n");
					else
						printf("deqd %d\n",dequeue(&q));
					break;
			case 3:if(isFull(&q))
						printf("Queue Full\n");
					else
						printf("Queue can take ele's\n");
					break;
			case 4:if(isEmpty(&q))
						printf("Queue Empty\n");
					else
						printf("Queue is not empty\n");
					break;
			case 5:display(&q);
					break;
		}
		printf("1.Enq 2.Deq 3.IsFull 4.IsEmpty 5.Display\n");
		scanf("%d",&choice);	
	}while(choice<6);
}