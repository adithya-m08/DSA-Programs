#include<stdio.h>

long int fact(int);

int main()
{
	printf("%ld\n",fact(5));
	return 0;
}

long int fact(int n)
{
	if(n==0)
		return 1;
	return n*fact(n-1);	
}