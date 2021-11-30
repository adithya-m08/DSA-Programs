//Pgm1
//DFS (Recursive): print all vertices reachable from source
//Adjacency Matrix representation

#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
void dfs(int a[MAX][MAX], int n, int visited[MAX], int source);

int main()
{
	int a[MAX][MAX], n, visited[MAX] = {0}, source;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	printf("Enter the source\n");
	scanf("%d", &source);

	printf("DFS traversal\n");
	dfs(a, n, visited, source);
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

void dfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
	visited[source] = 1;
	printf("%d ", source);

	for (int i = 0; i < n; i++)
	{
		if (a[source][i] && visited[i] == 0)
			dfs(a, n, visited, i);
	}
}

//Pgm2
//DFS (Recursive): print all vertices in the graph using DFS traversal
//Adjacency Matrix representation

#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
void dfs(int a[MAX][MAX], int n, int visited[MAX], int source);

int main()
{
	int a[MAX][MAX], n, visited[MAX] = {0}, source;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	printf("Enter the source\n");
	scanf("%d", &source);

	printf("DFS traversal\n");
	dfs(a, n, visited, source);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			printf("\n");
			dfs(a, n, visited, i);
		}
	}
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

void dfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
	visited[source] = 1;
	printf("%d ", source);

	for (int i = 0; i < n; i++)
	{
		if (a[source][i] && visited[i] == 0)
			dfs(a, n, visited, i);
	}
}

//Pgm3
//print all vertices reachable from the given source using DFS
//adjacency list representation
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node
{
	int info;
	struct node *next;
} NODE;
void createAdjList(NODE *V[MAX]);
void append(NODE *V[MAX], int source, int dest);
void dfs(NODE *V[MAX], int visited[MAX], int source);
void destroyList(NODE *V[MAX], int n);

int main()
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%d", &n);

	NODE *V[MAX] = {NULL};
	createAdjList(V);

	int src, visited[MAX] = {0};
	printf("Enter the source vertex\n");
	scanf("%d", &src);

	printf("DFS Traversal: Nodes reachable from %d\n", src);
	dfs(V, visited, src);
	destroyList(V, n);
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
		append(V, dest, source); //undirected graph

		printf("Do you want to add one more edge\n");
		scanf("%d", &choice);
	} while (choice);
}
void append(NODE *V[MAX], int source, int dest)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = dest;
	temp->next = NULL;

	//insert Last
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

void dfs(NODE *V[MAX], int visited[MAX], int cv)
{
	visited[cv] = 1;
	printf("%d ", cv);
	NODE *p = V[cv];
	while (p != NULL)
	{
		if (visited[p->info] == 0)
			dfs(V, visited, p->info);
		p = p->next;
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
			//			printf("Freeing %d\n",q->info);
			free(q);
		}
		V[i] = NULL;
	}
}

//Pgm4
//print all vertices in the graph using DFS
//adjacency list representation
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node
{
	int info;
	struct node *next;
} NODE;
void createAdjList(NODE *V[MAX]);
void append(NODE *V[MAX], int source, int dest);
void dfs(NODE *V[MAX], int visited[MAX], int source);
void destroyList(NODE *V[MAX], int n);

int main()
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%d", &n);

	NODE *V[MAX] = {NULL};
	createAdjList(V);

	int src, visited[MAX] = {0};
	printf("Enter the source vertex\n");
	scanf("%d", &src);

	printf("DFS Traversal\n");
	dfs(V, visited, src);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			printf("\n");
			dfs(V, visited, i);
		}
	}
	destroyList(V, n);
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
		append(V, dest, source); //undirected graph

		printf("Do you want to add one more edge\n");
		scanf("%d", &choice);
	} while (choice);
}
void append(NODE *V[MAX], int source, int dest)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = dest;
	temp->next = NULL;

	//insert Last
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

void dfs(NODE *V[MAX], int visited[MAX], int cv)
{
	visited[cv] = 1;
	printf("%d ", cv);
	NODE *p = V[cv];
	while (p != NULL)
	{
		if (visited[p->info] == 0)
			dfs(V, visited, p->info);
		p = p->next;
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
			//			printf("Freeing %d\n",q->info);
			free(q);
		}
		V[i] = NULL;
	}
}