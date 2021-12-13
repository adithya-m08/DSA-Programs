//creation of a dictionary using trie data structure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie
{
	int isLeaf;
	struct trie *child[26];
	char *synonym;
} TRIE;

TRIE *createNode();
void insert(TRIE *root, char *pattern, char *meaning);
int search(TRIE *root, char *pattern, char *meaning);

int main()
{
	TRIE *root = createNode();

	insert(root, "act", "pretend");

	char meaning[100];
	if (search(root, "act", meaning))
		printf("act is present and its meaning is %s\n", meaning);
	else
		printf("act is not present\n");
	if (search(root, "ac", meaning))
		printf("ac is present and its meaning is %s\n", meaning);
	else
		printf("ac is not present\n");
}

TRIE *createNode()
{
	TRIE *temp = malloc(sizeof(TRIE));
	temp->isLeaf = 0;
	for (int i = 0; i < 26; i++)
		temp->child[i] = NULL;

	return temp;
}

void insert(TRIE *root, char *pattern, char *meaning)
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
	cur->synonym = malloc(strlen(meaning) + 1);
	strcpy(cur->synonym, meaning);
}
int search(TRIE *root, char *pattern, char *meaning)
{
	TRIE *cur = root;

	while (*pattern)
	{
		if (cur->child[*pattern - 'a'] == NULL)
			return 0;
		cur = cur->child[*pattern - 'a'];
		pattern++;
	}
	if (cur->isLeaf)
	{
		strcpy(meaning, cur->synonym);
		return 1;
	}
	return 0;
}