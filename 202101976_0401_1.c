#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Listnode {
	element data;
	struct Listnode* link;
}Listnode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

Listnode* insert_first(Listnode* head, int value)
{
	Listnode* p = (Listnode *)malloc(sizeof(Listnode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

Listnode* insert(Listnode *head, Listnode *pre, element value)
{
	Listnode* p = (Listnode *)malloc(sizeof(Listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;

}

Listnode* delete_first(Listnode* head)
{
	Listnode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

Listnode* delete(Listnode *head, Listnode *pre)
{
	Listnode* removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}



void print_list(Listnode* head)
{
	for (Listnode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main(void)
{
	Listnode* head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}

	for (int i = 0; i < 5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}