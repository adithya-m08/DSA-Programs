typedef struct polynomial
{
	int coeff;
	int powx;
	struct polynomial *next;
}NODE;

void createPoly(NODE**);
void addPoly(NODE*,NODE*,NODE**);
void display(NODE*);
void insertLast(NODE**,int,int);
void destroyList(NODE**);
int evalPoly(NODE*,int);