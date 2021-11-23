/* 
//Pgm1
//Visits all the vertices from the source in a connected graph using BFS
//i.e., print all vertices reachable from the given source
//Adjacency Matrix representation
#define MAX 10
#include<stdio.h>

void readGraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source;
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the values to adj matrix\n");
	readGraph(a,n);
	
	printf("Enter the source\n");
	scanf("%d",&source);
	
	printf("BFS traversal or vertices reachable from %d\n",source);
	bfs(a,n,visited,source);
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
	
	q[++r]=source;			//enqueue source
	visited[source]=1;		//mark source visited
	
	int v;
	while(f<=r) //until q is not empty
	{
		v=q[f++];  //dequeue
		printf("%d ",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;		//enqueue ith vertex
				visited[i]=1;	//mark ith vertex visited
			}
		}
	}
} 
*/
 
/*  
//Pgm2: same as Pgm1, but queue is part of a structure
//Visits all the vertices from the source in a connected graph using BFS
//i.e., print all vertices reachable from the given source
//Adjacency Matrix representation
#define MAX 10
#include<stdio.h>
typedef struct queue
{
	int q[MAX];
	int f,r;
}QUEUE;
void readGraph(int a[MAX][MAX],int n);
void initQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
int dequeue(QUEUE *pq);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source;
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the values to adj matrix\n");
	readGraph(a,n);
	
	printf("Enter the source\n");
	scanf("%d",&source);
	
	printf("BFS traversal or vertices reachable from %d\n",source);
	bfs(a,n,visited,source);
}

void readGraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}
void initQueue(QUEUE *pq)
{
	pq->f=0;
	pq->r=-1;
}
int isEmpty(QUEUE *pq)
{
	return pq->f > pq->r;
}
void enqueue(QUEUE *pq,int ele)
{
	pq->r++;
	pq->q[pq->r]=ele;
}

int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->f];
	pq->f++;
	return ele;
}
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	QUEUE q;	//queue
	initQueue(&q);
	
	enqueue(&q,source);			//enqueue source
	visited[source]=1;		//mark source visited
	
	int v;
	while(!isEmpty(&q)) //until q is not empty
	{
		v=dequeue(&q);  //dequeue
		printf("%d ",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				enqueue(&q,i);		//enqueue ith vertex
				visited[i]=1;	//mark ith vertex visited
			}
		}
	}
} 
*/


/*  
//Pgm3
//If the graph is disconnected
//start the bfs traversal from one of the unvisited vertices
#define MAX 10
#include<stdio.h>

void readGraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source;
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the values to adj matrix\n");
	readGraph(a,n);
	
	printf("Enter the source\n");
	scanf("%d",&source);
	
	printf("BFS traversal\n");
	bfs(a,n,visited,source);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n");
			bfs(a,n,visited,i);
		}
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
		printf("%d ",v);
		
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
*/


/* 
//Pgm4
//Visits all the vertices from the source in a connected graph using BFS
//i.e., print all vertices reachable from the given source
//adjacency list representation
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node
{
	int info;
	struct node *next;
}NODE;

void createAdjList(NODE *V[MAX]);
void append(NODE *V[MAX],int source,int dest);
void bfs(NODE* V[MAX],int n,int visited[MAX],int source);
void destroyList(NODE *V[MAX],int n);

int main()
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%d",&n);
	
	NODE *V[MAX]={NULL};
	createAdjList(V);
	
	int src,visited[MAX]={0};
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS Traversal: Nodes reachable from %d\n",src);
	bfs(V,n,visited,src);
	destroyList(V,n);
}

void bfs(NODE* V[MAX],int n,int visited[MAX],int source)
{
	int q[n];		//Queue
	int f=0,r=-1;	//InitQueue
	q[++r]=source;
	visited[source]=1;
	int v;
	while(f<=r)
	{
		v=q[f++];
		printf("%d ",v);
		
		NODE *p=V[v];
		while(p!=NULL)
		{
			if(!visited[p->info])
			{
				q[++r]=p->info;
				visited[p->info]=1;
			}
			p=p->next;
		}
	}
}
void createAdjList(NODE *V[MAX])
{
	int choice;
	int source,dest;
	do{
		printf("Enter the source and dest vertex of the edge to be added\n");
		scanf("%d%d",&source,&dest);
		append(V,source,dest);
		append(V,dest,source); //undirected graph
		
		printf("Do you want to add one more edge\n");
		scanf("%d",&choice);
	}while(choice);
}
void append(NODE *V[MAX],int source,int dest)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=dest;
	temp->next=NULL;

//insert Last		
	if(V[source]==NULL)
	{
		V[source]=temp;
		return;
	}

	NODE *p=V[source];
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
//insertLast ends here	

//insert node at front
//		temp->next=V[source];
//		V[source]=temp;	
//insertFront ends here
}

void destroyList(NODE *V[MAX],int n)
{
	NODE *p,*q;
	for(int i=0;i<n;i++)
	{
		p=V[i];
		while(p!=NULL)
		{
			q=p;
			p=p->next;
//			printf("Freeing %d\n",q->info);
			free(q);
		}
		V[i]=NULL;
	}
} 
*/

/*  
//Pgm5
//If the graph is disconnected
//start the bfs traversal from one of the unvisited vertices
//adjacency list representation
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node
{
	int info;
	struct node *next;
}NODE;

void createAdjList(NODE *V[MAX]);
void append(NODE *V[MAX],int source,int dest);
void bfs(NODE* V[MAX],int n,int visited[MAX],int source);
void destroyList(NODE *V[MAX],int n);

int main()
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%d",&n);
	
	NODE *V[MAX]={NULL};
	createAdjList(V);
	
	int src,visited[MAX]={0};
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS Traversal\n");
	bfs(V,n,visited,src);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n");
			bfs(V,n,visited,i);
		}
	}
	destroyList(V,n);
}

void bfs(NODE* V[MAX],int n,int visited[MAX],int source)
{
	int q[n];		//Queue
	int f=0,r=-1;	//InitQueue
	q[++r]=source;
	visited[source]=1;
	int v;
	while(f<=r)
	{
		v=q[f++];
		printf("%d ",v);
		
		NODE *p=V[v];
		while(p!=NULL)
		{
			if(!visited[p->info])
			{
				q[++r]=p->info;
				visited[p->info]=1;
			}
			p=p->next;
		}
	}
}
void createAdjList(NODE *V[MAX])
{
	int choice;
	int source,dest;
	do{
		printf("Enter the source and dest vertex of the edge to be added\n");
		scanf("%d%d",&source,&dest);
		append(V,source,dest);
		append(V,dest,source); //undirected graph
		
		printf("Do you want to add one more edge\n");
		scanf("%d",&choice);
	}while(choice);
}
void append(NODE *V[MAX],int source,int dest)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=dest;
	temp->next=NULL;

//insert Last		
	if(V[source]==NULL)
	{
		V[source]=temp;
		return;
	}

	NODE *p=V[source];
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
//insertLast ends here	

//insert node at front
//		temp->next=V[source];
//		V[source]=temp;	
//insertFront ends here
}

void destroyList(NODE *V[MAX],int n)
{
	NODE *p,*q;
	for(int i=0;i<n;i++)
	{
		p=V[i];
		while(p!=NULL)
		{
			q=p;
			p=p->next;
//			printf("Freeing %d\n",q->info);
			free(q);
		}
		V[i]=NULL;
	}
} 
*/

/* 
//Pgm6: same as Pgm5, but queue is part of a structure
//If the graph is disconnected
//start the bfs traversal from one of the unvisited vertices
//adjacency list representation
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct queue
{
	int q[MAX];
	int f,r;
}QUEUE;

void initQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
int dequeue(QUEUE *pq);
void createAdjList(NODE *V[MAX]);
void append(NODE *V[MAX],int source,int dest);
void bfs(NODE* V[MAX],int visited[MAX],int source);
void destroyList(NODE *V[MAX],int n);

int main()
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%d",&n);
	
	NODE *V[MAX]={NULL};
	createAdjList(V);
	
	int src,visited[MAX]={0};
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS Traversal\n");
	bfs(V,visited,src);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n");
			bfs(V,visited,i);
		}
	}
	destroyList(V,n);
}
void initQueue(QUEUE *pq)
{
	pq->f=0;
	pq->r=-1;
}
int isEmpty(QUEUE *pq)
{
	return pq->f > pq->r;
}
void enqueue(QUEUE *pq,int ele)
{
	pq->r++;
	pq->q[pq->r]=ele;
}

int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->f];
	pq->f++;
	return ele;
}

void bfs(NODE* V[MAX],int visited[MAX],int source)
{
	QUEUE q;		//Queue
	initQueue(&q);	//InitQueue
	
	enqueue(&q,source);
	visited[source]=1;
	int v;
	while(!isEmpty(&q))
	{
		v=dequeue(&q);
		printf("%d ",v);
		
		NODE *p=V[v];
		while(p!=NULL)
		{
			if(!visited[p->info])
			{
				enqueue(&q,p->info);
				visited[p->info]=1;
			}
			p=p->next;
		}
	}
}
void createAdjList(NODE *V[MAX])
{
	int choice;
	int source,dest;
	do{
		printf("Enter the source and dest vertex of the edge to be added\n");
		scanf("%d%d",&source,&dest);
		append(V,source,dest);
		append(V,dest,source); //undirected graph
		
		printf("Do you want to add one more edge\n");
		scanf("%d",&choice);
	}while(choice);
}
void append(NODE *V[MAX],int source,int dest)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=dest;
	temp->next=NULL;

//insert Last		
	if(V[source]==NULL)
	{
		V[source]=temp;
		return;
	}

	NODE *p=V[source];
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
//insertLast ends here	

//insert node at front
//		temp->next=V[source];
//		V[source]=temp;	
//insertFront ends here
}

void destroyList(NODE *V[MAX],int n)
{
	NODE *p,*q;
	for(int i=0;i<n;i++)
	{
		p=V[i];
		while(p!=NULL)
		{
			q=p;
			p=p->next;
//			printf("Freeing %d\n",q->info);
			free(q);
		}
		V[i]=NULL;
	}
} 
*/