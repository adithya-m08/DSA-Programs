typedef struct node
{
	int info;
	struct node *next;
}NODE;

struct node *insertBeg(NODE* head,int ele);
void display(NODE* head);
NODE* concat(NODE* head1,NODE* head2);
NODE* destroyList(NODE* head);