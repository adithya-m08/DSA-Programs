//Binary Tree, Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *left, *right;
} NODE;

typedef struct tree
{
	NODE *root;
} TREE;
void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);
void postorder1(NODE *r);
void destroyTree(TREE *pt);

int main()
{
	TREE tobj;
	initTree(&tobj);

	createTree(&tobj);
	printf("Inorder BT traversal\n");
	inorder(&tobj);
	printf("\nPreorder BT traversal\n");
	preorder(&tobj);
	printf("\nPostorder BT traversal\n");
	postorder(&tobj);
	printf("\nPostorder BT traversal\n");
	postorder1(tobj.root);

	destroyTree(&tobj);

	return 0;
}

void initTree(TREE *pt)
{
	pt->root = NULL;
}
NODE *create()
{
	int ele;
	printf("Enter info (-1 for No node)\n");
	scanf("%d", &ele);

	if (ele == -1)
		return NULL;

	NODE *temp = malloc(sizeof(NODE));
	temp->info = ele;

	printf("Enter left child of %d\n", ele);
	temp->left = create();

	printf("Enter right child of %d\n", ele);
	temp->right = create();

	return temp;
}
void createTree(TREE *pt)
{
	pt->root = create();
}

void in(NODE *r)
{
	if (r != NULL)
	{
		in(r->left);
		printf("%d ", r->info);
		in(r->right);
	}
}
void inorder(TREE *pt)
{
	in(pt->root);
}

void pre(NODE *r)
{
	if (r != NULL)
	{
		printf("%d ", r->info);
		pre(r->left);
		pre(r->right);
	}
}
void preorder(TREE *pt)
{
	pre(pt->root);
}
void post(NODE *r)
{
	if (r != NULL)
	{
		post(r->left);
		post(r->right);
		printf("%d ", r->info);
	}
}
void postorder(TREE *pt)
{
	post(pt->root);
}

void postorder1(NODE *r)
{
	if (r != NULL)
	{
		postorder1(r->left);
		postorder1(r->right);
		printf("%d ", r->info);
	}
}
void destroyNode(NODE *r)
{
	if (r != NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		//		printf("\nFreeing %d",r->info);
		free(r);
	}
}
void destroyTree(TREE *pt)
{
	if (pt->root)
	{
		destroyNode(pt->root);
		pt->root = NULL;
	}
}