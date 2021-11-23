//DEQUE using circular array
#include<stdio.h>
#define MAX 5

typedef struct DEQUE
{
    int  q[MAX];
    int  front;
    int  rear;
}DEQUE;

void initDeque(DEQUE* pq)
{
	pq->front = -1;
	pq->rear = -1;
}
 
int isFull(DEQUE *pq)
{
	return (pq->rear+1)%pq->size==pq->front;
}
 
int isEmpty(DEQUE *pq)
{
    return (pq->front == -1); // or return pq->rear==-1;
}

void insertFront(DEQUE *pq,int ele)
{
    if (pq->front == -1) 
    {
		pq->front = 0;
		pq->rear = 0;
	}
    else if (pq->front == 0)
		pq->front = MAX - 1 ;
    else 				
		pq->front = pq->front-1;

    pq->q[pq->front] = ele;
}

void insertRear(DEQUE *pq,int ele)
{
	if (pq->front == -1)
	{
		pq->front = 0;
		pq->rear = 0;
	}
	else if (pq->rear==MAX-1)
		pq->rear = 0;
	else
		pq->rear = pq->rear+1;

	pq->q[pq->rear] = ele ;
}

int deleteFront(DEQUE *pq)
{
	int ele=pq->q[pq->front];
	if (pq->front==pq->rear)
	{
		pq->front = -1;
		pq->rear = -1;
	}
	else if (pq->front == MAX -1)
		pq->front = 0;
	else 
		pq->front = pq->front+1;
	return ele;
}
 
int deleteRear(DEQUE *pq)
{
	int ele=pq->q[pq->rear];
	if (pq->front==pq->rear)
	{
		pq->front = -1;
		pq->rear = -1;
	}
    else if (pq->rear == 0)
		pq->rear = MAX-1;
	else
		pq->rear = pq->rear-1;
	return ele;
}

void display(DEQUE *pq)
{
	if(isEmpty(pq))
	{
		printf("Queue is Empty\n");
		return;
	}
	int i;
	for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
		printf("%d ",pq->q[i]);
	printf("%d\n",pq->q[i]);
}

int main()
{
	DEQUE dq;
	int choice,ele;
	
	initDeque(&dq);
	printf("1.insFront 2.insRear 3.delFront 4.delRear 5.Display\n");
	scanf("%d",&choice);
	do{
		switch(choice)
		{
			case 1:if(!isFull(&dq))
					{
						printf("Enter an ele\n");
						scanf("%d",&ele);
						insertFront(&dq,ele);
					}
					else
						printf("Queue is already full\n");
					break;
			case 2:if(!isFull(&dq))
					{
						printf("Enter an ele\n");
						scanf("%d",&ele);
						insertRear(&dq,ele);
					}
					else
						printf("Queue is already full\n");
					break;
			case 3:if(!isEmpty(&dq))
						printf("%d deqd\n",deleteFront(&dq));
					else
						printf("Queue is already empty\n");
					break;	
			case 4:if(!isEmpty(&dq))
						printf("%d deqd\n",deleteRear(&dq));
					else
						printf("Queue is already empty\n");
					break;	
			case 5:display(&dq);break;
		}
		printf("1.insFront 2.insRear 3.delFront 4.delRear 5.Display\n");
		scanf("%d",&choice);		
	}while(choice<6);

    return 0;
}