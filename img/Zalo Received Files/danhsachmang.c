#include<stdio.h>
#define MAXSIZE 100

typedef int ElementType;

typedef struct {

  ElementType Elements[MAXSIZE];

  int size;

}Array;
void makenull(Array *pL){
    pL->size=0;
}
void build(int A[], int n, Array *pL){
    int i;
    for(i=0;i<n;i++){
        pL->Elements[i]=A[i];
    }
    pL->size=n;
}
void print_array(Array L){
    int i;
    for(i=0;i<L.size;i++){
        printf("%d ",L.Elements[i]);
    }
}
ElementType get_at(int p, Array L){
    if((p<0) || (p>L.size-1)) return -10000;
	return L.Elements[p];
}
void set_at(ElementType x, int p, Array *pL){
    if((p<0) || (p>pL->size-1)) printf("Invalid position\n");
	else pL->Elements[p]=x;
}
void insert_at(ElementType x, int p, Array *pL){
	if((p<0) || (p>pL->size)) printf("Invalid position\n");
	else if(pL->size==MAXSIZE) printf("Full array\n");
	else{
		int i;
		for(i=pL->size;i>p;i--){
			pL->Elements[i]=pL->Elements[i-1];
		}
		pL->Elements[p]=x;
		pL->size++;
	}
}
ElementType delete_at(int p, Array *pL){
	if(p<0 || p>pL->size-1) return -10000;
	else{
		int i;
		int x=pL->Elements[p];
		for(i=p;i<(pL->size-1);i++){
			pL->Elements[i]=pL->Elements[i+1];
		}
		pL->size--;
		return x;
	}
}
void insert_first(ElementType x, Array *pL){
	if(pL->size==MAXSIZE) printf("Full array\n");
	else{
		int i;
		for(i=pL->size;i>0;i--){
			pL->Elements[i]=pL->Elements[i-1];
		}
		pL->Elements[0]=x;
		pL->size++;
	}
}
ElementType delete_first(Array *pL){
	int i;
	int x=pL->Elements[0];
	for(i=0;i<(pL->size-1);i++){
		pL->Elements[i]=pL->Elements[i+1];
	}
	pL->size--;
	return x;
}
void insert_last(ElementType x, Array *pL){
	if(pL->size==MAXSIZE) printf("Full array\n");
	else{
		pL->Elements[pL->size]=x;
		pL->size++;
	}
}
ElementType delete_last(Array *pL){
	int x =pL->Elements[pL->size-1] ;
	pL->size--;
	return x;
}
int locate(int x, Array L){
	int i;
	for(i=0;i<L.size;i++){
		if(L.Elements[i]==x) return i;
	}
	return -1;
}
int member(int x, Array L){
	if(locate(x,L)!= -1) return 1;
	else return 0;
}
void delete_x(int x, Array *pL){
	int p=locate(x,*pL);
	if(p==-1) return;
	int i;
	for(i=p;i<(pL->size-1);i++){
		pL->Elements[i]=pL->Elements[i+1];
	}
	pL->size--;
	return;
}
void delete_all(int x, Array *pL){
	while(locate(x,*pL)!=-1){
		delete_x(x,pL);
	}
}
float getAVG(Array L){
	if(L.size==0) return -10000;
	int sum=0,i;
	for(i=0;i<L.size;i++){
		sum=sum+L.Elements[i];
	}
	return (float)sum/L.size;
}
void sort(Array *pL){
	int i,j,t;
	for(i=0;i<pL->size-1;i++){
		for(j=i+1;j<pL->size;j++){
			if(pL->Elements[i]<pL->Elements[j]){
				t=pL->Elements[i];
				pL->Elements[i]=pL->Elements[j];
				pL->Elements[j]=t;
			}
		}
	}
}

void unionSet(Array L1, Array L2, Array *pL){
	makenull(pL);    // ham makenullList()
	int i;
	for(i=0;i<L1.size;i++){    //chen het L1 vao L
		insert_last(L1.Elements[i],pL); //ham chen phan tu vao cuoi danh sach insertSet()
	}
	for(i=0;i<L2.size;i++){
		if(!member(L2.Elements[i],*pL))   // neu L2 khong trung L1 thi chen vao
			insert_last(L2.Elements[i],pL);
	}
} 

int main(){
Array L1;
int A[]= {1, 2, 3, 6, 3, 12};
int n = sizeof(A)/sizeof(int);
build(A, n, &L1);
Array L2,L;
int B[]= {2, 9, 4, 7, 8, 13};
n = sizeof(B)/sizeof(int);
build(B, n, &L2);
unionSet(L1,L2,&L);
print_array(L);
	return 0;
}

