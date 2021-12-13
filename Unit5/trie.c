//TRIE data structure: prefix tree
//houses lower case english alphabets
#include <stdio.h>
#include <stdlib.h>

typedef struct trie
{
	int isLeaf;
	struct trie *child[26];
} TRIE;

TRIE *createNode();
void insert(TRIE *root, char *pattern);
int search(TRIE *root, char *pattern);
TRIE *destroy(TRIE *root);
void display(TRIE *root, char *str, int level);
void displayOfLen(TRIE *root, char *str, int level, int length);
int isEmpty(TRIE *root);
TRIE *delete (TRIE *root, char *str, int level, int length);
int main()
{
	TRIE *root = createNode();
	/* 	
	insert(root,"ant");
	insert(root,"antenna");
	
	if(search(root,"ant"))
		printf("ant is present\n");
	else
		printf("ant is not present\n");
	
	if(search(root,"antenna"))
		printf("antenna is present\n");
	else
		printf("antenna is not present\n");
	
	if(search(root,"ten"))
		printf("ten is present\n");
	else
		printf("ten is not present\n");
	
	if(search(root,"an"))
		printf("an is present\n");
	else
		printf("an is not present\n"); */

	insert(root, "app");
	insert(root, "apple");
	insert(root, "ant");

	char str[100];
	printf("Patterns present in TRIE\n");
	display(root, str, 0);
	printf("Patterns of length 2 in TRIE\n");
	displayOfLen(root, str, 0, 2);
	delete (root, "app", 0, 3);
	printf("Patterns present in TRIE\n");
	display(root, str, 0);
	destroy(root);
}

TRIE *createNode()
{
	TRIE *temp = malloc(sizeof(TRIE));
	temp->isLeaf = 0;
	for (int i = 0; i < 26; i++)
		temp->child[i] = NULL;

	return temp;
}

void insert(TRIE *root, char *pattern)
{
	TRIE *cur = root;

	while (*pattern)
	{
		if (cur->child[*pattern - 'a'] == NULL)
			cur->child[*pattern - 'a'] = createNode();
		cur = cur->child[*pattern - 'a'];
		pattern++;
	}
	cur->isLeaf = 1;
}
int search(TRIE *root, char *pattern)
{
	TRIE *cur = root;

	while (*pattern)
	{
		if (cur->child[*pattern - 'a'] == NULL)
			return 0;
		cur = cur->child[*pattern - 'a'];
		pattern++;
	}
	return cur->isLeaf;
}

TRIE *destroy(TRIE *root)
{
	for (int i = 0; i < 26; i++)
	{
		if (root->child[i] != NULL)
		{
			root->child[i] = destroy(root->child[i]);
			//			printf("%c is freed\n",i+'a');
			free(root->child[i]);
			root->child[i] = NULL;
		}
	}
	return root;
}

void display(TRIE *root, char *str, int level)
{
	if (root->isLeaf)
	{
		str[level] = '\0';
		printf("%s\n", str);
	}
	for (int i = 0; i < 26; i++)
	{
		if (root->child[i] != NULL)
		{
			str[level] = i + 'a';
			display(root->child[i], str, level + 1);
		}
	}
}
void displayOfLen(TRIE *root, char *str, int level, int length)
{
	if (root->isLeaf && level == length)
	{
		str[level] = '\0';
		printf("%s\n", str);
	}
	for (int i = 0; i < 26; i++)
	{
		if (root->child[i] != NULL)
		{
			str[level] = i + 'a';
			displayOfLen(root->child[i], str, level + 1, length);
		}
	}
}
int isEmpty(TRIE *root)
{
	for (int i = 0; i < 26; i++)
		if (root->child[i] != NULL)
			return 0;

	return 1;
}
TRIE *delete (TRIE *root, char *str, int level, int length)
{
	if (root == NULL)
		return NULL;

	if (length == level)
	{
		if (root->isLeaf)
			root->isLeaf = 0;
		if (isEmpty(root))
		{
			free(root);
			root = NULL; //return NULL;
		}
		return root;
	}

	int index = str[level] - 'a';

	root->child[index] = delete (root->child[index], str, level + 1, length);
	if (root->isLeaf == 0 && isEmpty(root))
	{
		free(root);
		root = NULL; //return NULL;
	}
	return root;
}