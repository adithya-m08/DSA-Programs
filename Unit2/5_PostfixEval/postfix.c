#include<stdio.h>
#include"postfix.h"

int main()
{
	char postfix[MAX];
	
	printf("Enter a valid postfix expression\n");
	scanf("%s",postfix);
	
	printf("Result=%f\n",postfixEval(postfix));
	return 0;
}