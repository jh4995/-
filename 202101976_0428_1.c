#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct Graphtype {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}Graphtype;

void init_graph(Graphtype *g)
{
	g->n = 0;

	for (int a = 0; a < MAX_VERTICES; a++)
	{
		for (int b = 0; b < MAX_VERTICES; b++)
		{
			g->adj_mat[a][b] = 0;
		}
	}
}

void insert_vertex(Graphtype *g, int i)
{
	if ( (g->n)+1 > MAX_VERTICES )
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
	}

	g->n++;
}

void insert_edge(Graphtype *g, int a, int b)
{
	if ( a>= g->n || b>=g->n )
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
	}

	g->adj_mat[a][b] = 1;
	g->adj_mat[b][a] = 1;
}

void print_adj_mat(Graphtype *g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("%d", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	Graphtype* g;
	g = (Graphtype*)malloc(sizeof(Graphtype));

	init_graph(g);
	for (int i = 0; i < 4; i++)
	{
		insert_vertex(g, i);
	}

	insert_edge(g,0,1);
	insert_edge(g,0,2);
	insert_edge(g,0,3);
	insert_edge(g,1,2);
	insert_edge(g,2,3);
	print_adj_mat(g);

	free(g);
}