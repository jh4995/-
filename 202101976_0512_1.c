#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 10000000

typedef struct Graphtype {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}Graphtype;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(Graphtype *g, int n, int found[])
{

}

void print_status()
{

}


void shortest_path(Graphtype *g, int start)
{
	int i,u,w;
	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;


	for (i = 0; i < g->n - 1; i++)
	{
		u = choose(g, g->n, found);

	}

	for (w = 0; w < g->n; w++)
	{
		if (!found[w])
		{
			if( && )
		}
	}


}

int main(void)
{
	Graphtype g = { 7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}	}
	};

	shortest_path(&g, 0);
	return 0;
}