#include <stdio.h>
#define MAX 50

typedef struct node
{
	int info;
	int used;
} NODE;

void initTree(NODE bt[MAX]);
void createTree(NODE bt[MAX], int i);
void levelorder(NODE bt[MAX]);
void inorder(NODE bt[MAX], int i);
void preorder(NODE bt[MAX], int i);
void postorder(NODE bt[MAX], int i);

int main()
{
	NODE bt[MAX];

	initTree(bt);
	createTree(bt, 0);

	printf("Tree in Level order Traversal\n");
	levelorder(bt);

	printf("\nInorder Traversal\n");
	inorder(bt, 0);

	printf("\nPreorder Traversal\n");
	preorder(bt, 0);

	printf("\nPostorder Traversal\n");
	postorder(bt, 0);
}

void initTree(NODE bt[MAX])
{
	for (int i = 0; i < MAX; i++)
		bt[i].used = 0;
}

void createTree(NODE bt[MAX], int i)
{
	int ele;
	printf("Enter data(-1 for no data):");
	scanf("%d", &ele);

	if (ele == -1 || i >= MAX)
	{
		//		if(i>=MAX)
		//			printf("Outside array bound\n");
		return;
	}

	bt[i].info = ele;
	bt[i].used = 1;

	printf("Enter left child of %d:\n", ele);
	createTree(bt, 2 * i + 1);

	printf("Enter right child of %d:\n", ele);
	createTree(bt, 2 * i + 2);
}

void levelorder(NODE bt[MAX])
{
	for (int i = 0; i < MAX; i++)
		if (bt[i].used)
			printf("%d ", bt[i].info);
}

void inorder(NODE bt[MAX], int i)
{
	if (i < MAX && bt[i].used)
	{
		inorder(bt, 2 * i + 1);
		printf("%d ", bt[i].info);
		inorder(bt, 2 * i + 2);
	}
}
void preorder(NODE bt[MAX], int i)
{
	if (i < MAX && bt[i].used)
	{
		printf("%d ", bt[i].info);
		preorder(bt, 2 * i + 1);
		preorder(bt, 2 * i + 2);
	}
}
void postorder(NODE bt[MAX], int i)
{
	if (i < MAX && bt[i].used)
	{
		postorder(bt, 2 * i + 1);
		postorder(bt, 2 * i + 2);
		printf("%d ", bt[i].info);
	}
}