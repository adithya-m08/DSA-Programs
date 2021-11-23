/*Circular Queue: Linked list implementation*/
#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;

typedef struct queue
{
  struct node *front,*rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
int dequeue(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);

int main()
{
	int choice,ele;
	
	QUEUE qobj;
	initQueue(&qobj);
	
	printf("1.Enqueue 2.Dequeue 3.Display\n");
	scanf("%d",&choice);
	do{
		switch(choice)
		{
			case 1:printf("Enter an element\n");
					scanf("%d",&ele);
					enqueue(&qobj,ele);
					break;
			case 2: if(!isEmpty(&qobj))
						printf("Deleted element is %d\n",dequeue(&qobj));
					else
						printf("Q already empty\n");
					break;
			case 3:display(&qobj);
					break;
		}
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
	}while(choice<4);
		destroyQueue(&qobj);
}

void initQueue(QUEUE *pq)
{
	pq->front=pq->rear=NULL;
}
void enqueue(QUEUE *pq,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->next=NULL;
	
	if(pq->rear==NULL)
	{
		pq->rear=temp;
		pq->front=temp;
		temp->next=temp;
		return;
	}
	temp->next=pq->rear->next;
	pq->rear->next=temp;
	pq->rear=temp;
}

int dequeue(QUEUE *pq)
{
	int ele;
	
	if(pq->front==pq->rear)
	{
		ele=pq->front->data;
		free(pq->front);
		pq->front=pq->rear=NULL;
		return ele;
	}
	ele=pq->front->data;
	pq->rear->next=pq->front->next;
	free(pq->front);
	pq->front=pq->rear->next;	
	return ele;
}
int isEmpty(QUEUE *pq)
{
	return pq->front==NULL;
}
void display(QUEUE *pq)
{
	NODE *p=pq->front;
	if(p==NULL)
	{
		printf("Empty Queue\n");
		return;
	}
	
	while(p!=pq->rear)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
void destroyQueue(QUEUE *pq)
{
	if(pq->front==NULL)
		return;
	while(pq->front!=pq->rear)
	{
//		printf("%d ",pq->front->data);
		pq->rear->next=pq->front->next;
		free(pq->front);	
		pq->front=pq->rear->next;
	}
//	printf("%d ",pq->front->data);
	free(pq->front);
	pq->rear=pq->front=NULL;
}