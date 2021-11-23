#include<stdio.h>
#include"inToPost.h"

int main()
{
	char infix[MAX],postfix[MAX];
	printf("Enter a valid infix expression\n");
	scanf("%s",infix);
	
	infixToPostfix(infix,postfix);
	printf("%s\n",postfix);
}