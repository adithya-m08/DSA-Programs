#include <stdio.h>
#include "exprTree.h"
#include <ctype.h>
#include <stdlib.h>

void initTree(TREE *pt)
{
	pt->root = NULL;
}
void initStack(STACK *ps)
{
	ps->top = -1;
}
void createTree(TREE *pt, char expr[MAX])
{
	STACK sobj;
	initStack(&sobj);

	for (int i = 0; expr[i] != '\0'; i++)
	{
		NODE *temp = malloc(sizeof(NODE));
		temp->info = expr[i];
		temp->left = temp->right = NULL;

		if (isdigit(expr[i]))
			push(&sobj, temp);
		else
		{
			temp->right = pop(&sobj);
			temp->left = pop(&sobj);
			push(&sobj, temp);
		}
	}
	pt->root = pop(&sobj);
}
void inord(NODE *r)
{
	if (r == NULL)
		return;
	inord(r->left);
	printf("%c ", r->info);
	inord(r->right);
}
void inorder(TREE *pt)
{
	inord(pt->root);
}
void preord(NODE *r)
{
	if (r != NULL)
	{
		printf("%c ", r->info);
		preord(r->left);
		preord(r->right);
	}
}
void preorder(TREE *pt)
{
	preord(pt->root);
}
void postord(NODE *r)
{
	if (r != NULL)
	{
		postord(r->left);
		postord(r->right);
		printf("%c ", r->info);
	}
}
void postorder(TREE *pt)
{
	postord(pt->root);
}
void destroyNode(NODE *r)
{
	if (r != NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		printf("\nFreeing%d", r->info);
		free(r);
	}
}
void destroyTree(TREE *pt)
{
	if (pt->root != NULL)
	{
		destroyNode(pt->root);
		pt->root = NULL;
	}
}
int eval(NODE *r)
{
	switch (r->info)
	{
	case '+':
		return eval(r->left) + eval(r->right);
		break;
	case '-':
		return eval(r->left) - eval(r->right);
		break;
	case '*':
		return eval(r->left) * eval(r->right);
		break;
	case '/':
		return eval(r->left) / eval(r->right);
		break;
	default:
		return r->info - '0';
	}
}
int evalExprTree(TREE *pt)
{
	return eval(pt->root);
}

void push(STACK *ps, NODE *ele)
{
	ps->top++;
	ps->s[ps->top] = ele;
}
NODE *pop(STACK *ps)
{
	NODE *ele = ps->s[ps->top];
	ps->top--;
	return ele;
}