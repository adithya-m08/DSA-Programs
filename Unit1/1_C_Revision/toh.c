#include<stdio.h>

void ToH(int n,char source,char temp,char dest);

int main()
{
	int n;
	printf("Enter the no. of discs\n");
	scanf("%d",&n);
	ToH(n,'A','B','C');
	return 0;
}


void ToH(int n,char source,char temp,char dest)
{
	if(n==1)
	{
		printf("Move disc %d from %c to %c\n",n,source,dest);
		return;
	}
	ToH(n-1,source,dest,temp);
	printf("Move disc %d from %c to %c\n",n,source,dest);
	ToH(n-1,temp,source,dest);
}