//Determine if the digraph is strongly or weakly connected
//or not connected using BFS
//Adjacency Matrix representation
/*
Strongly conctd
0 1 1 0
1 0 0 0
0 0 0 1
1 0 0 0
Weakly conctd
0 1 0 0
0 0 0 0
0 0 0 1
1 0 0 0
Disconctd
0 0 1 0
0 0 0 0
0 0 0 1
1 0 0 0
*/
#define MAX 10
#include<stdio.h>

void readGraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);
int strongConnected(int a[MAX][MAX],int n);
int weakConnected(int a[MAX][MAX],int n);
void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n);
int main()
{
	int a[MAX][MAX],n;
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the values to adj matrix\n");
	readGraph(a,n);
	
	if(strongConnected(a,n))
		printf("Graph is strongly connected\n");
	else
	{
		int b[MAX][MAX]={0};
		removeEdgeDirection(a,b,n);
		if(weakConnected(b,n))
			printf("Graph is weakly connected\n");
		else
			printf("Graph is disconnected\n");
	}
}

void readGraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int q[n]; //Queue
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	
	int v;
	while(f<=r) //until q is not empty
	{
		v=q[f++];
//		printf("%d ",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
			}
		}
	}
}
int strongConnected(int a[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	for(int v=0;v<n;v++)
	{
		for(int j=0;j<n;j++)
			visited[j]=0;
		bfs(a,n,visited,v);
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
				b[i][j]=b[j][i]=1;
		}
	}
}
int weakConnected(int b[MAX][MAX],int n)
{
	int visited[MAX]={0};

	bfs(b,n,visited,0);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			return 0;
		}
	}
	return 1;
}