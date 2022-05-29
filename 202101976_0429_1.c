#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
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

void dfs_list(Graphtype* g, int v)
{
	Graphnode* w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = g->adg_list[v]; w; w = w->link)
	{
		if (!visited[w->vertex])
		{
			dfs_list(g, w->vertex);
		}
	}
}

int main(void)
{
	Graphtype* g;
	g = (Graphtype *)malloc(sizeof(Graphtype));
	init(g);

	for (int i = 0; i < 4; i++)
	{
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_list(g, 0);
	printf("\n");
	free(g);

	return 0;
}