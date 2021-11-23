#include<stdio.h>

int fib(int);

int main()
{
	printf("%d\n",fib(5));
	return 0;
}

int fib(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	return fib(n-1)+fib(n-2);
}
