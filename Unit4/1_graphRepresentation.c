//Graph Representation: Adjacency Matrix
#include <stdio.h>
#define MAX 5
void readGraph(int a[MAX][MAX], int n);
void printGraph(int a[MAX][MAX], int n);
int main()
{
	int a[MAX][MAX], n;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);
	printf("Graph displayed as adj matrix\n");
	printGraph(a, n);
}
void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}
void printGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//Graph Representation: Adjacency Matrix
#include <stdio.h>
#define MAX 5
void readGraph(int a[MAX][MAX]);
void printGraph(int a[MAX][MAX], int n);
int main()
{
	int a[MAX][MAX] = {0}; //initialize all entries in adj matrix to zero
	int n;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a);

	printGraph(a, n);
}
void readGraph(int a[MAX][MAX])
{
	int s, d;
	printf("Enter -1 -1 to stop adding edges\n");
	while (1)
	{
		printf("Enter the source and dest vertex for the edge to be added\n");
		scanf("%d%d", &s, &d);
		if (s == -1 && d == -1)
			break;
		a[s][d] = 1;
	}
}
void printGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//Graph Representation: Adjacency List
#include <stdio.h>
#define MAX 10
#include <stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
} NODE;

void createAdjList(NODE *V[MAX]);
void append(NODE *V[MAX], int source, int dest);
void display(NODE *V[MAX], int n);

int main()
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%d", &n);

	NODE *V[MAX] = {NULL};
	createAdjList(V);
	display(V, n);
}
void createAdjList(NODE *V[MAX])
{
	int choice;
	int source, dest;
	do
	{
		printf("Enter the source and dest vertex of the edge to be added\n");
		scanf("%d%d", &source, &dest);
		append(V, source, dest);
		append(V, dest, source); //for undirected graph

		printf("Do you want to add one more edge\n");
		scanf("%d", &choice);
	} while (choice);
}
void append(NODE *V[MAX], int source, int dest)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = dest;
	temp->next = NULL;

	//for insert Last
	if (V[source] == NULL)
	{
		V[source] = temp;
		return;
	}

	NODE *p = V[source];
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	//insertLast ends here

	//insert node at front
	//		temp->next=V[source];
	//		V[source]=temp;
	//insertFront ends here
}
void display(NODE *V[MAX], int n)
{
	NODE *p;
	for (int i = 0; i < n; i++)
	{
		p = V[i];
		printf("V[%d]->", i);
		while (p != NULL)
		{
			printf("%d->", p->info);
			p = p->next;
		}
		printf("NULL\n");
	}
}
void destroyList(NODE *V[MAX], int n)
{
	NODE *p, *q;
	for (int i = 0; i < n; i++)
	{
		p = V[i];
		while (p != NULL)
		{
			q = p;
			p = p->next;
			free(q);
		}
		V[i] = NULL;
	}
}