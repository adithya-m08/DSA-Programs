#include<stdio.h>
#include"deq.h"

int main()
{
	struct deque dq;
	initQueue(&dq);
	
	int choice,ele;
		printf("\n1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.Display 6.EXIT");
		scanf("%d",&choice);
	do
	{

		
		switch(choice)
		{
			case 1:printf("Enter the element\n");
					scanf("%d",&ele);
					insertFront(&dq,ele);
					break;
			case 2:printf("Enter the value\n");
					scanf("%d",&ele);
					insertLast(&dq,ele);
					break;					
			case 3:if(!isEmpty(&dq))
						printf("Deleted element=%d\n",deleteFront(&dq));
					else
						printf("Empty Queue\n");
					break;
			case 4:if(!isEmpty(&dq))
						printf("Deleted element=%d\n",deleteLast(&dq));
					else
						printf("Empty Queue\n");
					break;
			case 5: display(&dq);
					break;
		}
		printf("\n1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.Display 6.EXIT");
		scanf("%d",&choice);
	}while(choice<6);
	destroyQueue(&dq);
	return 0;
}