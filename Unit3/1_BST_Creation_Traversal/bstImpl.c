#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void initTree(TREE *pt)
{
	pt->root = NULL;
}

void createTree(TREE *pt)
{
	int choice;
	NODE *temp = malloc(sizeof(NODE));
	temp->left = temp->right = NULL;

	printf("Enter root info\n");
	scanf("%d", &temp->info);

	pt->root = temp;

	printf("Do you want to add one more node\n");
	scanf("%d", &choice);
	while (choice)
	{
		temp = malloc(sizeof(NODE));
		temp->left = temp->right = NULL;

		printf("Enter node info\n");
		scanf("%d", &temp->info);

		NODE *p = pt->root;
		NODE *q = NULL;
		while (p != NULL)
		{
			if (temp->info <= p->info)
			{
				q = p;
				p = p->left;
			}
			else
			{
				q = p;
				p = p->right;
			}
		}
		if (temp->info <= q->info)
			q->left = temp;
		else
			q->right = temp;
		printf("Do you want to add one more node\n");
		scanf("%d", &choice);
	}
}
void inord(NODE *r)
{
	if (r == NULL)
		return;
	inord(r->left);
	printf("%d ", r->info);
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
		printf("%d ", r->info);
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
		printf("%d ", r->info);
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
		//		printf("\nFreeing%d",r->info);
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