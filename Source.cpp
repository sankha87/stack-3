#include<stdio.h>
#include<conio.h>
#include<malloc.h>
static int capacity;
struct Node
{
	int data;
	struct Node *next;
};
void display(struct Node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}
bool isEmpty()
{
	if (capacity == 0)
		return true;
	else 
		return false;
}
Node* push(struct Node *head_ref, int data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = head_ref;
	head_ref = new_node;
	capacity++;
	return head_ref;
}
int return_top(struct Node *head_ref)
{
	return head_ref->data;
}
Node* pop(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	head_ref = head_ref->next;
	free(temp);
	capacity--;
	return head_ref;
}
void main()
{
	struct Node *top = NULL;
	if(isEmpty())
		printf("\n\n Stack is empty ");
	top = push(top, 50);
	if (isEmpty())
		printf("\n\n Stack is empty ");
	top = push(top, 40);
	top = push(top, 30);
	top = push(top, 20);
	top = push(top, 10);
	printf("\n\nAfter push operation, Stack is : ");
	display(top);
	printf("\n\nTop Of Stack is : ");
	printf(" %d ", return_top(top));
	top = pop(top);
	printf("\n\nAfter POP operation, The Stack is: ");
	display(top);
	if (isEmpty())
		printf("\n\n Stack is empty ");
	_getch();
}