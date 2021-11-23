#include"postfix.h"
#include<ctype.h>

void initStack(STACK *ps)
{
	ps->top=-1;
}

void push(STACK *ps,float ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	//instead of 2 lines above : ps->s[++ps->top]=ele;
}

float pop(STACK *ps)
{
	float res=ps->s[ps->top];
	ps->top--;
	return res;
	//instead of 2 lines above : return ps->s[ps->top--];	
}
float postfixEval(char* pfix)
{
	STACK s;
	initStack(&s);
	
	float op1,op2,res;
	for(int i=0;pfix[i]!='\0';i++)
	{
		if(isdigit(pfix[i]))
			push(&s,pfix[i]-'0');
		else
		{
			op2=pop(&s);
			op1=pop(&s);
			
			switch(pfix[i])
			{
				case '+':res=op1+op2;
							break;
				case '-':res=op1-op2;
							break;
				case '*':res=op1*op2;
							break;
				case '/':res=op1/op2;
							break;
			}
			push(&s,res);
		}
	}
	return pop(&s);
}