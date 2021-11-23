#include<stdio.h>
#include"exprTree.h"

int main()
{
	TREE tobj;
	initTree(&tobj);

	char expr[MAX];
	printf("Enter a valid postfix expression\n");
	scanf("%s",expr);
	
	createTree(&tobj,expr);
	printf("\nInorder:");
	inorder(&tobj);
	printf("\nPreorder:");
	preorder(&tobj);
	printf("\nPostorder:");
	postorder(&tobj);
	
	printf("\nResult=%d\n",evalExprTree(&tobj));
}