//register
#include<stdio.h>
//register int a=100;
int main()
{
	register int a=100;
//	int *p=&a;	//Error
	printf("%d\n",a);
	return 0;
}