//Chk if there exists a path from source to dest using BFS
//Adjacency Matrix representation
#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
int bfs(int a[MAX][MAX], int n, int visited[MAX], int source, int dest);

int main()
{
	int a[MAX][MAX], n, visited[MAX] = {0}, source, dest;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	printf("Enter the source and dest\n");
	scanf("%d%d", &source, &dest);

	if (bfs(a, n, visited, source, dest))
		printf("There exists path from %d to %d\n", source, dest);
	else
		printf("There exists no path from %d to %d\n", source, dest);
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}
int bfs(int a[MAX][MAX], int n, int visited[MAX], int source, int dest)
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
				if (dest == i)
					return 1;
				q[++r] = i;
				visited[i] = 1;
			}
		}
	}
	return 0;
}