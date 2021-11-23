#include<stdio.h>

struct student
{
	int rollNo;
	char name[20];
	int marks;	
};
typedef struct student student_t;

void display(const struct student *s); //struct student *s=&s1;
int main()
{
	struct student s1={1,"abc",20},s2;
	struct student s3={.name="def",.rollNo=2,.marks=20};
	s2=s1;
	display(&s1);
	display(&s3);
	return 0;
}

void display(const struct student *s)
{
	printf("%d %s %d\n",(*s).rollNo,s->name,s->marks);
}