#include<stdio.h>
#pragma pack(8) //n= 2^0, 2^1, 2^2, 2^3
struct test
{
	char b; //1 byte
	//3 bytes padding
	int a; //4 bytes
};

int main()
{
	printf("%lu\n",sizeof(struct test));
	return 0;
}