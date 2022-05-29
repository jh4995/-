#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//////////////////////////////////////////

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element top;
	element stack[MAX_STACK_SIZE];
}Stacktype;
int is_empty(Stacktype *s)
{
	return (s->top == -1);
}
int is_full(Stacktype *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(Stacktype *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
element pop(Stacktype *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}
element peek(Stacktype *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];
}

//////////////////////////////////////

#define MAX_VERTICES 100
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

//////////////////////////////////////////////

int topo_sort(Graphtype* g)
{
	int i;
	Stacktype s;
	Graphnode* node;

	int* in_degree = (int*)malloc((g->n) * sizeof(int));

	for (int i = 0; i < g->n; i++)
	{
		in_degree[i] = 0;
	}

	for (int i = 0; i < g->n; i++)
	{
		Graphnode* node = g->adg_list[i];

		while (node != NULL) 
		{
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	init(&s);
	for (i = 0; i < g->n; i++)
	{
		if (in_degree[i] == 0)
		{
			push(&s, i);
		}
	}

	while (!is_empty(&s))
	{
		int w;
		w = pop(&s);
		printf("정점 %d ->", w);
		node = g->adg_list[w];
		while (node != NULL)
		{
			int u = node->vertex;
			in_degree[u]--;
			
			if (in_degree[u] == 0)
			{
				push(&s, u);
			}
			node = node->link;
		}
	}

	free(in_degree);
	printf("\n");
	return (i == g->n);
}

int main(void)
{
	Graphtype g;
	init(&g);

	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);

	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);

	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);

	insert_edge(&g, 3, 5);

	insert_edge(&g, 4, 5);

	topo_sort(&g);

	return 0;
}