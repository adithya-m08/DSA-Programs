#include<stdio.h>

int main()
{
	int a[]={10,20,30};
	int *ptr=a;
//	a++;
	int q=*ptr++; //int q; q=ptr++; *ptr;
//	int r=*++ptr;
//	int s=++*ptr;
	
	printf("%d %d\n",q,*ptr);
	return 0;
}