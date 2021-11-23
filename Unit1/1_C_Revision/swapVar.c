#include<stdio.h>

void swap1(int,int);
void swap2(int*,int*);

int main()
{
	int a=2,b=3;
	
	printf("Before swapping a=%d b=%d\n",a,b);
	swap1(a,b);
	printf("After swapping a=%d b=%d\n",a,b);

	printf("Before swapping a=%d b=%d\n",a,b);
	swap2(&a,&b);
	printf("After swapping a=%d b=%d\n",a,b);	
	return 0;
}

void swap1(int m,int n)	//int m=a, int n=b
{
	int temp;
	temp=m;
	m=n;
	n=temp;
}

void swap2(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}