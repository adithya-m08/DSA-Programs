#include<stdio.h>

int* f1(int *);
int* f2(int a[]);
void f3(int *);

int main()
{
	int a[]={1,2,3};
/* 	int *ptr=a;
	
	printf("%d\n",f1(ptr)==f1(a));
	printf("sizeof(a)=%lu sizeof(ptr)=%lu\n",sizeof(a),sizeof(ptr));
	printf("%d\n",sizeof(a)==sizeof(ptr));
 */
/*	a++;*/

	printf("%d %d %d\n",a[0],a[1],a[2]);	
	int *ptr=f2(a);
	printf("%d %d %d\n",a[0],a[1],a[2]);
	f3(ptr);
	printf("%d %d %d\n",a[0],a[1],a[2]);
	
	return 0;
}

/* int* f1(int *a)
{
	return a;
}
 */
int* f2(int a[])
{
	a++;
	*a=100;
	return a;
}

void f3(int *a)
{
	a++;
	*a=200;
}