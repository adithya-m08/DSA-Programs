#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void initStack(STACK *ps,int n)
{
	ps->s=malloc(sizeof(int)*n);
	ps->top=-1;
	ps->maxSize=n;
}
void destroyStack(STACK *ps)
{
	printf("Going to free %d bytes\n",sizeof(int)*ps->maxSize);
	free(ps->s);
}
int isFull(STACK *ps)
{
	return ps->top==ps->maxSize-1;
}
void stackDouble(STACK *ps)
{
	if(ps->maxSize==0)
		ps->maxSize=1;
	else
		ps->maxSize=ps->maxSize*2;
	ps->s=realloc(ps->s,sizeof(int)*ps->maxSize);
}
int push(STACK *ps,int ele)
{
	if(isFull(ps))
		stackDouble(ps);
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