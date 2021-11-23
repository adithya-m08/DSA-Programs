//const and ptr

#include<stdio.h>

int main()
{
/* 	int const p=10;
//	const int q=20;
//	p=10;
	int const q=20;
	int const *const ptr=&p;
//	p++; //Error
	ptr=&q;
 */	
/* 	const int r=11;
	int *z=&r;
//	r++;	//Error
	int s=++*z;
	printf("%d %d\n",*z,r);
	printf("%d %d\n",++*z,r); */

	int a=10;
	const int const *p=&a;
	printf("%d",*p);
	return 0;
}