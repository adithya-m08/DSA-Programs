#include<stdio.h>
#include"queue_Array.h"

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