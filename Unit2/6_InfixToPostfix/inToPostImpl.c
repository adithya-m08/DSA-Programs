#include"inToPost.h"
#include<ctype.h>
void initStack(STACK *ps)
{
	ps->top=-1;
}
void push(STACK *ps,int ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	//instead of 2 lines above : ps->s[++ps->top]=ele;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}
int pop(STACK *ps)
{
	int res=ps->s[ps->top];
	ps->top--;
	return res;
	//instead of 2 lines above : return ps->s[ps->top--];	
}
int stackTop(STACK *ps)
{
	return ps->s[ps->top];
}
int prcd(char st,char i)
{
	switch(i)
	{
		case '+':
		case '-':if(st=='(')
					return 0;
				return 1;
		case '*':
		case '/':if(st=='(' || st=='+' || st=='-')
					return 0;
				return 1;
		case '(':return 0;
		case ')':if(st=='(')
					return 0;
				return 1;
	}
}
void infixToPostfix(char* infix,char *postfix)
{
	STACK s;
	initStack(&s);
	char dummy;
	int k=0;
	for(int i=0;infix[i]!='\0';i++)
	{
		if(isdigit(infix[i]))
			postfix[k++]=infix[i];
		else
		{
			while(!isEmpty(&s) && prcd(stackTop(&s),infix[i]))
				postfix[k++]=pop(&s);
			if(infix[i]==')')
				dummy=pop(&s);
			else
				push(&s,infix[i]);
				
		}
	}
	while(!isEmpty(&s))
		postfix[k++]=pop(&s);
	postfix[k]='\0';
}