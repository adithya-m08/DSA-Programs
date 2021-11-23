#include"stack.h"
#include<stdio.h>

int main()
{
	int choice,ele;
	STACK s;
//	s.top=-1;
	initStack(&s);
	
	if(isEmpty(&s))
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");
	push(&s,10);
	if(isFull(&s))
		printf("Stack is full\n");
	else
		printf("Stack is not full\n");	
	push(&s,20);
	if(isFull(&s))
		printf("Stack is full\n");
	else
		printf("Stack is not full\n");
	printf("Popped ele is %d\n",pop(&s));
	display(&s);
	printf("Popped ele is %d\n",pop(&s));
	if(isEmpty(&s))
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");
}