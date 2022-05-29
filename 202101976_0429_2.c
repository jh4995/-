#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}Queuetype;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void queue_init(Queuetype* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(Queuetype* q)
{
	return (q->front == q->rear);
}

int is_full(Queuetype* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queuetype* q, element item)
{
	if (is_full(q))
	{
		error("큐가 포화상태입니다");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(Queuetype* q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


#define MAX_VERTICES 50

typedef struct Graphnode {
	int vertex;
	struct Graphnode* link;
}Graphnode;

typedef struct Graphtype {
	int n;
	Graphnode* adg_list[MAX_VERTICES];
}Graphtype;

void init(Graphtype* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adg_list[v] = NULL;
	}
}

void insert_vertex(Graphtype* g, int v)
{
	if ((g->n) + 1 > MAX_VERTICES)
	{
		fprintf(stderr, "그래프:정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(Graphtype* g, int u, int v)
{
	Graphnode* node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프:정점 번호 오류");
		return;
	}

	node = (Graphnode*)malloc(sizeof(Graphnode));
	node->vertex = v;
	node->link = g->adg_list[u];
	g->adg_list[u] = node;
}

int visited[MAX_VERTICES];

void bfs_list(Graphtype* g, int v)
{
	Graphnode* w;
	Graphtype q;

	init(&q);
	visited[v] = TRUE;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);

	while (!is_empty(&q))
	{
		v = dequeue(&q);

		for (w = g->adg_list[v]; w; w = w->link)
		{
			if (!visited[w->vertex])
			{
				visited[w->vertex] = TRUE;
				printf("%d 방문 -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
}

int main(void)
{
	Graphtype* g;
	g = (Graphtype *)malloc(sizeof(Graphtype));
	init(g);

	for (int i = 0; i < 6; i++)
	{
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("너비 우선 탐색\n");
	bfs_list(g, 0);
	printf("\n");
	free(g);

	return 0;
}