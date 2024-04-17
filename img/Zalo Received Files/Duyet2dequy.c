#include <stdio.h>

#define MAX_VERTICES 100

typedef struct
{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *G, int n)
{
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			G->A[i][j] = 0;
		}
	}
}
void add_edge(Graph *G, int x, int y)
{
	G->A[x][y] += 1;
	G->A[y][x] += 1;
}
int adjacent(Graph *G, int x, int y)
{
	return (G->A[x][y] != 0);
}
int degree(Graph *G, int x)
{
	int y, deg = 0;
	for (y = 1; y <= G->n; y++)
	{
		deg += G->A[x][y];
	}
	return deg;
}

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

void makenull(List *L)
{
	L->size = 0;
}
void push_back(List *L, ElementType x)
{
	L->data[L->size] = x;
	L->size++;
}
ElementType element_at(List *L, int i)
{
	return L->data[i - 1];
}
int count_list(List *L)
{
	return L->size;
}

List neighbors(Graph *G, int x)
{
	int y;
	List list;
	makenull(&list);
	for (y = 1; y <= G->n; y++)
	{
		if (adjacent(G, x, y))
			push_back(&list, y);
	}
	return list;
}

void traversal(Graph *G, int x, int mark[], int p[], int pa)
{

	if (mark[x] == 1)
		return;

	mark[x] = 1;
	p[x] = pa;
	pa = x;
	// printf("Duyet %d\n", x);

	List list = neighbors(G, x);
	int j;
	for (j = 1; j <= list.size; j++)
	{
		int y = element_at(&list, j);
		printf("%d", y);
		traversal(G, y, mark,p,pa);
	}
}

void depth_first_search(Graph *G, int mark[])
{
	int p[100];
	int j;
	for (j = 1; j <= G->n; j++)
		mark[j] = 0;
	int pa = 1;
	p[1] = 0;
	traversal(G, 1, mark,p,pa);
	int i;
	for (i = 1; i <= G->n; i++)
	{
		printf("%d %d\n", i, p[i]);
	}
}
int main()
{

	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);

	for (e = 0; e < m; e++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int j;
	int mark[100];
	for (j = 1; j <= G.n; j++)
	{
		mark[j] = 0;
	}
	depth_first_search(&G, mark);

	return 0;
}
