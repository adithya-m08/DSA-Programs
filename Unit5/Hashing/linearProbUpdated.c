//Closed Hashing (Open addressing)
//Hash function: rNo%tableSize
//Collision Resolution: Linear Probing
#include <stdio.h>
#define SIZE 7
#include <string.h>
typedef struct stud
{
	int rNo;
	char name[30];
	int mark; //indicates if record exists or not
} NODE;

void initTable(NODE ht[SIZE], int *n);
int insert(NODE ht[SIZE], int rNo, char name[30], int *n);
int delete (NODE ht[SIZE], int rNo, int *n);
int search(NODE ht[SIZE], int rNo, char name[30], int n);
void display(NODE ht[SIZE], int n);

int main()
{
	int n = 0;
	NODE ht[SIZE];	   //create hashtable
	initTable(ht, &n); //initialize hashtable

	int choice, rNo;
	char name[30];
	printf("1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
	scanf("%d", &choice);
	do
	{
		switch (choice)
		{
		case 1:
			printf("Enter the rNo\n");
			scanf("%d", &rNo);
			printf("Enter the name\n");
			scanf("%s", name);
			if (!insert(ht, rNo, name, &n))
				printf("Table already full, cannot insert\n");
			break;
		case 2:
			printf("Enter the rNo\n");
			scanf("%d", &rNo);
			if (delete (ht, rNo, &n))
				printf("Record with rNo %d deleted\n", rNo);
			else
				printf("Record not found\n");
			break;
		case 3:
			printf("Enter the rNo\n");
			scanf("%d", &rNo);

			if (search(ht, rNo, name, n))
				printf("Record found: Details %d,%s\n", rNo, name);
			else
				printf("Record not found\n");
			break;
		case 4:
			display(ht, n);
			break;
		case 5:
			return 0;
		}
		printf("1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
		scanf("%d", &choice);
	} while (choice < 6);
}

void initTable(NODE ht[SIZE], int *n)
{
	for (int i = 0; i < SIZE; i++)
		ht[i].mark = -1;
	(*n) = 0;
}
int insert(NODE ht[SIZE], int rNo, char name[30], int *n)
{
	if (*n == SIZE)
		return 0;

	int index = rNo % SIZE; //hash fn

	while (ht[index].mark != -1)
		index = (index + 1) % SIZE;

	ht[index].rNo = rNo;
	strcpy(ht[index].name, name);
	ht[index].mark = 1;
	(*n)++;
	return 1;
}
int delete (NODE ht[SIZE], int rNo, int *n)
{
	if (*n == 0)
		return 0;

	int index = rNo % SIZE; //hash fn

	int i = 0;
	while (ht[index].rNo != rNo && i < *n)
	{
		index = (index + 1) % SIZE;
		if (ht[index].mark == 1)
			i++;
	}
	if (ht[index].rNo == rNo && ht[index].mark == 1)
	{
		ht[index].mark = -1;
		(*n)--;
		return 1;
	}
	return 0;
}
int search(NODE ht[SIZE], int rNo, char name[30], int n)
{
	if (n == 0)
		return 0;

	int index = rNo % SIZE; //hash fn

	int i = 0;
	while (ht[index].rNo != rNo && i < n)
	{
		index = (index + 1) % SIZE;
		if (ht[index].mark == 1)
			i++;
	}
	if (ht[index].rNo == rNo && ht[index].mark == 1)
	{
		strcpy(ht[index].name, name);
		return 1;
	}
	return 0;
}
void display(NODE ht[SIZE], int n)
{
	if (n == 0)
	{
		printf("Empty hash table\n");
		return;
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (ht[i].mark == 1)
			printf("h[%d]: %d, %s\n", i, ht[i].rNo, ht[i].name);
		else
			printf("h[%d]\n", i);
	}
}