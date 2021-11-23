#include<stdio.h>

struct demo
{
	int a;
	double b;
};
typedef struct demo DEMO;
DEMO* f1(DEMO *d);
DEMO f2(DEMO d);
int main()
{
	DEMO d={1,2.5};
/* 	DEMO *d2=f1(&d);
	printf("%d %lf\n",d.a,d.b);
	printf("%d %lf\n",d2->a,d2->b); */
	DEMO d3=f2(d);
	printf("%d %lf\n",d.a,d.b);
	printf("%d %lf\n",d3.a,d3.b);
	return 0;
}
DEMO* f1(DEMO *d)
{
	d->a=10;
	return d;
}
DEMO f2(DEMO d)
{
	d.a=100;
	return d;
}