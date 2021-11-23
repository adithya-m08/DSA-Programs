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
void push(STACK *ps,int ele)
{
	//Next two lines: or ps->s[++ps->top]=ele
	ps->top++;					
	ps->s[ps->top]=ele;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}

int stackTop(STACK *ps)
{
	return ps->s[ps->top];

}

int pop(STACK *ps)
{
	return ps->s[ps->top--];
	
/* above line or below 2 lines
	*pe=ps->s[ps->top];
	ps->top--;
*/
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