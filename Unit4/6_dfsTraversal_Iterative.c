//Pgm1
//DFS (Iterative): print all vertices reachable from source
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

	printf("DFS traversal:Vertices reachable from %d\n", source);
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
	int s[n];	  //stack created
	int top = -1; //init stack

	int flag = 0, i;
	s[++top] = source;
	visited[source] = 1;
	printf("%d ", source);

	while (top != -1) //until stack is not empty
	{
		flag = 0;
		source = s[top]; //stacktop or peek opn
		for (i = 0; i < n; i++)
		{
			if (a[source][i] && !visited[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			s[++top] = i;
			visited[i] = 1;
			printf("%d ", i);
		}
		else
			top--;
	}
}

//Pgm2
//print all vertices in the graph using DFS traversal (Iterative)
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
	int s[n];	  //stack created
	int top = -1; //init stack

	int flag = 0, i;
	s[++top] = source;
	visited[source] = 1;
	printf("%d ", source);

	while (top != -1) //until stack is not empty
	{
		flag = 0;
		source = s[top]; //stacktop or peek opn
		for (i = 0; i < n; i++)
		{
			if (a[source][i] && !visited[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			s[++top] = i;
			visited[i] = 1;
			printf("%d ", i);
		}
		else
			top--;
	}
}