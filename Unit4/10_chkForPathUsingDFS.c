//Chk if there exists a path from source to dest using DFS
//Adjacency Matrix representation
#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
int dfs(int a[MAX][MAX], int n, int visited[MAX], int source, int dest);

int main()
{
	int a[MAX][MAX], n, visited[MAX] = {0}, source, dest;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	printf("Enter the source and dest\n");
	scanf("%d%d", &source, &dest);

	if (dfs(a, n, visited, source, dest))
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

int dfs(int a[MAX][MAX], int n, int visited[MAX], int source, int dest)
{
	visited[source] = 1;
	//	printf("%d ",source);

	for (int i = 0; i < n; i++)
	{
		if (a[source][i] && visited[i] == 0)
		{
			if (dest == i || dfs(a, n, visited, i, dest))
				return 1;
		}
	}
	return 0;
}