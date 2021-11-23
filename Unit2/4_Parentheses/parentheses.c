#include<stdio.h>
#include"parentheses.h"

int main()
{
	char input[MAX];
	printf("Enter a parenthesized expression\n");
	scanf("%s",input);
	if(parenthesesMatch(input))
		printf("Valid\n");
	else
		printf("Invalid\n");
	return 0;
}