//static 

#include<stdio.h>
void fn();

int main()
{
	int a=10;
	printf("In main a=%d\n",a);
	fn();
	printf("In main a=%d\n",a);
	fn();
}

void fn()
{
	static int a=10;
	int b=20; b++;
	a++;
	printf("In fn a=%d b=%d\n",a,b);
}