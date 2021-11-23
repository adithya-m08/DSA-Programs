#include"stack.h"
#include<stdio.h>

int main()
{
	int choice,ele;
	STACK s;
//	s.top=-1;
	initStack(&s);
	printf("1.Push 2.Pop 3.Display 4.IsEmpty 5.IsFull 6.Peek\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an ele\n");
					scanf("%d",&ele);
					if(push(&s,ele))
						printf("%d pushed successfully\n");
					else
						printf("Stack overflow\n");
					break;
			case 2:if(pop(&s,&ele))
						printf("Popped %d\n",ele);
					else
						printf("Stack underflow\n");
					break;
			case 3:display(&s);
					break;
			case 4:if(isEmpty(&s))
					printf("Stack is Empty\n");
					else
						printf("Stack is not empty\n");
					break;
			case 5:if(isFull(&s))
					printf("Stack is full\n");
				else
					printf("Stack can take elements\n");
				break;
			case 6:if(stackTop(&s,&ele))
					printf("Stack top is %d\n",ele);
				else
					printf("Stack is Empty\n");
				break;
		}
		printf("1.Push 2.Pop 3.Display 4.IsEmpty 5.IsFull 6.Peek\n");
		scanf("%d",&choice);
	}while(choice<7);
}