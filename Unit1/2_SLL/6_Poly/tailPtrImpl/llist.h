typedef struct polynomial
{
	int coeff;
	int powx;
	struct polynomial *next;
}NODE;

typedef struct list
{
	NODE *head;
	NODE *tail;
}LLIST;

void initList(LLIST*);
void createPoly(LLIST*);
void addPoly(LLIST*,LLIST*,LLIST*);
void display(LLIST*);
void insertLast(LLIST*,int,int);
void destroyList(LLIST*);