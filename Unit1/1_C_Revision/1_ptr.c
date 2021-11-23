#include<stdio.h>

int main()
{
	int a=10;
	int *p=&a;
	
	int *q;
	q=&a;
	
	int **pp=&p;
	printf("%u %u\n",&a,p);
	printf("%d %d\n",*p,**pp);

	return 0;
}