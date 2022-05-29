#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkedQueueType;

void init(LinkedQueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(LinkedQueueType *q)
{
	return (q->front == NULL);
}

int is_full(LinkedQueueType *q)
{
	return 0;
}

void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	tmp->data = data;
	tmp->link = NULL;

	if (is_empty(q))
	{
		q->front = tmp;
		q->rear = tmp;
	}
	else
	{
		q->rear->link = tmp;
		q->rear = tmp;
	}
}

element dequeue(LinkedQueueType* q)
{
	QueueNode* tmp = q->front;
	element data;

	if (is_empty(q))
	{
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}

	else
	{
		data = tmp->data;
		q->front = q->front->link;

		if (q->front == NULL)
		{
			q->rear = NULL;
		}

		free(tmp);
		return data;
	}
}

void print_queue(LinkedQueueType* q)
{
	QueueNode* a;
	for (a = q->front; a != NULL; a = a->link)
	{
		printf("%d->", a->data);
	}
	printf("NULL\n");
}


int main(void)
{
	LinkedQueueType queue;

	init(&queue);

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);

	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);

	return 0;
}