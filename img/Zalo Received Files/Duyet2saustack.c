#include<stdio.h>

#define MAX_VERTICES 100

typedef struct {
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			G->A[i][j]=0;
		}
	}
}
void add_edge(Graph *G,int x, int y){
	G->A[x][y] +=1;
	G->A[y][x] +=1;
}
int adjacent (Graph *G, int x, int y){
	return G->A[x][y]!=0;
}
int degree (Graph *G, int x){
	int y, deg = 0;
	for(y=1;y<=G->n;y++){
		deg+=G->A[x][y];
	}
	return deg;
}

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

void makenull(List *L){
	L->size = 0;
}
void push_back(List *L, ElementType x){
	L->data[L->size] = x;
	L->size++;
}
ElementType element_at(List *L, int i){
	return L->data[i-1];
}
int count_list(List *L){
	return L->size;
}

List neighbors (Graph *G, int x){
	int y;
	List list;
	makenull(&list);
	for(y=1;y<=G->n;y++){
		if( adjacent(G,x,y))
			push_back(&list, y);
	}
	return list;
}
#define MAX_ELEMENTS 100
typedef struct {
int data[MAX_ELEMENTS];
int front, rear;
} Queue;
void make_null_queue(Queue* Q) {
Q->front = 0;
Q->rear = -1;
}
void push(Queue* Q, int x) {
Q->rear++;
Q->data[Q->rear] = x;
}
int top(Queue* Q) {
return Q->data[Q->front];
}
void pop(Queue* Q) {
Q->front++;
}
int empty(Queue* Q) {
return Q->front > Q->rear;
}

//void depth_first_search(Graph *G){
//	Stack L;
//	int mark[MAX_VERTICES];
//	make_null_stack(&L);
//	int j;
//	for(j=1;j<=G->n;j++){
//		mark[j]=0;
//	}
//	push(&L,1);
//	while(!empty(&L)){
//		int x = top(&L);pop(&L);
//		if (mark[x] != 0) 
//			continue;
//		printf("%d\n", x);
//		mark[x] = 1; 
//		List list = neighbors(G, x);
//
//		for (j = 1; j <= list.size; j++) {
//			int y = element_at(&list, j);
//			push(&L, y);
//		}
//	}
//	for(j=1;j<=G->n;j++){
//			if(mark[j]==0){
//				push(&L,j);
//			while(!empty(&L)){
//				int x = top(&L);pop(&L);
//				if (mark[x] != 0) 
//					continue;
//				printf("%d\n", x);
//				mark[x] = 1; 
//				List list = neighbors(G, x);
//		
//			for (j = 1; j <= list.size; j++) {
//				int y = element_at(&list, j);
//				push(&L, y);
//			}
//		}
//		}
//	}
//}

int p;
void breath_first_search(Graph* G) {
	Queue L;
	int mark[MAX_VERTICES];
	make_null_queue(&L);

	int j;
	for (j = 1; j <= G->n; j++)
	mark[j] = 0;
	
	push(&L, p);
	
	printf("%d ",p);
	mark[p] = 1;

	while (!empty(&L)) {
	
		int x = top(&L); pop(&L);
		
		List list = neighbors(G, x);
		
		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
			if (mark[y] == 0) { 
				printf("%d ", y);
				mark[y] = 1; 
				push(&L, y); 
			}
		}
	}
	
	
	
}
int main(){
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	scanf("%d", &p);

	breath_first_search(&G);
	
	return 0;
}

