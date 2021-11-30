//Implementation of dictionary (Words with their meanings)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 25
#define MAX2 100

typedef struct node
{
	char key[MAX1], value[MAX2];
	struct node *left, *right;
} NODE;
typedef struct tree
{
	NODE *root;
} TREE;

void init(TREE *pt)
{
	pt->root = NULL;
}

NODE *createNode(char word[MAX1], char meaning[MAX2])
{
	NODE *temp = malloc(sizeof(NODE));
	strcpy(temp->key, word);
	strcpy(temp->value, meaning);
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//BST: Iterative insert
void insert(TREE *pt, char word[MAX1], char meaning[MAX2])
{
	NODE *temp = createNode(word, meaning);
	if (pt->root == NULL)
	{
		pt->root = temp;
		return;
	}
	NODE *p = pt->root;
	NODE *q = NULL;

	while (p != NULL)
	{
		q = p;
		if (strcmp(temp->key, p->key) < 0)
			p = p->left;
		else
			p = p->right;
	}
	if (strcmp(temp->key, q->key) < 0)
		q->left = temp;
	else
		q->right = temp;
}

//BST: Recursive Insert
NODE *rinsert(NODE *r, NODE *temp)
{
	if (r == NULL)
		return temp;
	if (strcmp(temp->key, r->key) < 0)
		r->left = rinsert(r->left, temp);
	else
		r->right = rinsert(r->right, temp);

	return r;
}

void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2])
{
	NODE *temp = createNode(word, meaning);
	pt->root = rinsert(pt->root, temp);
}

void inorder(NODE *r)
{
	if (r != NULL)
	{
		inorder(r->left);
		printf("%s,%s\n", r->key, r->value);
		inorder(r->right);
	}
}

NODE *delNode(NODE *r, char word[MAX1])
{
	NODE *temp = NULL, *p = NULL;
	if (r == NULL)
		return r;
	if (strcmp(word, r->key) < 0)
		r->left = delNode(r->left, word);
	else if (strcmp(word, r->key) > 0)
		r->right = delNode(r->right, word);
	else if (r->left == NULL)
	{
		temp = r->right;
		free(r);
		return temp;
	}
	else if (r->right == NULL)
	{
		temp = r->left;
		free(r);
		return temp;
	}
	else
	{
		p = r->right;
		while (p->left != NULL)
			p = p->left;
		strcpy(r->key, p->key);
		r->right = delNode(r->right, p->key);
	}
	return r;
}

//BST: Iterative search
int search(NODE *r, char word[MAX1], char meaning[MAX2])
{
	while (r != NULL)
	{
		if (strcmp(word, r->key) == 0)
		{
			strcpy(meaning, r->value);
			return 1;
		}
		else if (strcmp(word, r->key) < 0)
			r = r->left;
		else
			r = r->right;
	}
	return 0;
}

void destroyNode(NODE *r)
{
	if (r != NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		//		printf("\nFreeing %s",r->key);
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

int main()
{
	TREE tobj;
	init(&tobj);
	char word[MAX1], meaning[MAX2];
	int choice;
	do
	{
		printf("\n1.Insert 2.Delete 3.Display 4.Search\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the word and its meaning\n");
			scanf("%s", word);
			fflush(stdin);
			scanf("%[^\n]", meaning);
			//insert(&tobj,word,meaning);
			recInsert(&tobj, word, meaning);
			break;
		case 2:
			printf("enter the word to be deleted\n");
			scanf("%s", word);
			if (search(tobj.root, word, meaning))
			{
				tobj.root = delNode(tobj.root, word);
				printf("After deletion\n");
				inorder(tobj.root);
			}
			else
				printf("Word not present\n");
			break;
		case 3:
			inorder(tobj.root);
			break;
		case 4:
			printf("enter the word to be searched\n");
			scanf("%s", word);
			if (search(tobj.root, word, meaning))
				printf("%s found and its meaning is %s\n", word, meaning);
			else
				printf("%s not found\n", word);
			break;

		case 5:
			break;
		}
	} while (choice < 5);
	destroyTree(&tobj);
}