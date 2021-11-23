/* #include<stdio.h>
#define MAX 50
void topDownHeap(int h[MAX],int n);
int main()
{
	int h[MAX],n;
	
	printf("Enter the no. of elts\n");
	scanf("%d",&n);
	
	topDownHeap(h,n);
	printf("Top down heap:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",h[i]);
	}
}
void topDownHeap(int h[MAX],int n)
{
	int c,p,key;
	printf("Enter the elts\n");
	scanf("%d",&h[0]);
	
	for(int i=1;i<n;i++)
	{
		scanf("%d",&h[i]);
		c=i;
		p=(c-1)/2;
		key=h[c];
		while(c>0 && h[p]<key)
		{
			h[c]=h[p];
//			h[p]=key;
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
} */
#include<stdio.h>
#define MAX 50
void topDownHeap(int h[MAX],int n);
int main()
{
	int h[MAX],n;
	
	printf("Enter the no. of elts\n");
	scanf("%d",&n);

	printf("Enter the elts\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	topDownHeap(h,n);
	printf("Top down heap:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",h[i]);
	}
}
void topDownHeap(int h[MAX],int n)
{
	int c,p,key;

	for(int i=1;i<n;i++)
	{
		c=i;
		p=(c-1)/2;
		key=h[c];
		while(c>0 && h[p]<key)
		{
			h[c]=h[p];
//			h[p]=key;
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
}