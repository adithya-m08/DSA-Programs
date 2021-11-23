#include<stdio.h>
#include"stack.h"

void initStack(STACK *ps)
{
	ps->top=-1;
}
int isFull(STACK *ps)
{
	return ps->top==MAX-1;
}
int push(STACK *ps,int ele)
{
	if(isFull(ps))
		return 0;
	//Next two lines: or ps->s[++ps->top]=ele
	ps->top++;					
	ps->s[ps->top]=ele;
	return 1;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}

int stackTop(STACK *ps,int *pe)
{
	if(isEmpty(ps))
		return 0;
	*pe=ps->s[ps->top];
	return 1;
}

int pop(STACK *ps,int *pe)
{
	if(isEmpty(ps))
		return 0;
	*pe=ps->s[ps->top--];
	
/* above line or below 2 lines
	*pe=ps->s[ps->top];
	ps->top--;
*/
	return 1;
}
void display(STACK *ps)
{
	if(isEmpty(ps))
	{
		printf("Stack is Empty\n");
		return;
	}
	for(int i=ps->top;i>=0;i--)
		printf("%d ",ps->s[i]);
	printf("\n");
}