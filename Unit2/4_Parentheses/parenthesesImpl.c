#include"parentheses.h"
void initStack(STACK *ps)
{
	ps->top=-1;
}

int isFull(STACK *ps)
{
	return ps->top==MAX-1;
}
void push(STACK *ps,char ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	//instead of 2 lines above : ps->s[++ps->top]=ele;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}
char pop(STACK *ps)
{
	char res=ps->s[ps->top];
	ps->top--;
	return res;
	//instead of 2 lines above : return ps->s[ps->top--];	
}
int parenthesesMatch(char *str)
{
	STACK s;
	initStack(&s);
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			push(&s,str[i]);
		else if(str[i]==')' || str[i]==']' || str[i]=='}')
		{
			if(isEmpty(&s))
				return 0;
			switch(str[i])
			{
				case ')':if(pop(&s)!='(')
							return 0;
						break;
				case ']':if(pop(&s)!='[')
							return 0;
						break;
				case '}':if(pop(&s)!='{')
							return 0;
						break;
			}
		}
	}
	return isEmpty(&s);
}