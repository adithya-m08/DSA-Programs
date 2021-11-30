//Pgm1
//Determine if the undirected graph is connected or not using BFS
//Adjacency Matrix representation
#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source);
int connected(int a[MAX][MAX], int n);
int main()
{
	int a[MAX][MAX], n;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	if (connected(a, n))
		printf("Graph is connected\n");
	else
		printf("Graph is disconnected\n");
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
	int q[n]; //Queue
	int f = 0, r = -1;

	q[++r] = source;
	visited[source] = 1;

	int v;
	while (f <= r) //until q is not empty
	{
		v = q[f++];
		//		printf("%d ",v);

		for (int i = 0; i < n; i++)
		{
			if (a[v][i] && visited[i] == 0)
			{
				q[++r] = i;
				visited[i] = 1;
			}
		}
	}
}
int connected(int a[MAX][MAX], int n)
{
	int visited[MAX] = {0}, source = 0;
	bfs(a, n, visited, source);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}

//Pgm2
//Print the no. of connected components
#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source);
int connected(int a[MAX][MAX], int n);
int main()
{
	int a[MAX][MAX], n;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	int res = connected(a, n);
	printf("No.of connected components is %d\n", res);
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
	int q[n]; //Queue
	int f = 0, r = -1;

	q[++r] = source;
	visited[source] = 1;

	int v;
	while (f <= r) //until q is not empty
	{
		v = q[f++];
		//		printf("%d ",v);

		for (int i = 0; i < n; i++)
		{
			if (a[v][i] && visited[i] == 0)
			{
				q[++r] = i;
				visited[i] = 1;
			}
		}
	}
}
int connected(int a[MAX][MAX], int n)
{
	int visited[MAX] = {0};
	int con = 1;
	bfs(a, n, visited, 0);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			printf("\n");
			con++;
			bfs(a, n, visited, i);
		}
	}
	return con;
}