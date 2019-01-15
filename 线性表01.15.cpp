#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElementType;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};
typedef struct LNode * List;
/////////////////////////º¯Êý
List MakeEmpty();
int  Find(List L,ElementType X);
bool Insert(List L,ElementType X,int i);
bool Delete(List L,int i);

int main()
{
	List L = MakeEmpty();
	int i;
	Insert(L,1,3);
	//Delete(L,3);
	for(i=0;i<10;i++){
		printf(" %d",L->Data[i]);
	}
	
	return 0;
} 
List MakeEmpty()
{
	List L;
	L =(List)malloc(sizeof(struct LNode));
	L->Last = 0;
	return L;
}
int  Find(List L,ElementType X)
{
	int i=0;
	while(i<=L->Last && L->Data[i]!=X){
		i++;
	}
	if(i>L->Last){
		return -1;
	}else return i;
}
bool Insert(List L,ElementType X,int i)
{
	int j;
	for(j=L->Last;j>=i-1;j--){
		L->Data[j+1] = L->Data[j];
	}
	L->Data[i-1] = X;
	L->Last++;
	return true;
}
bool Delete(List L,int i)
{
	int j;
	for(j=i;j<=L->Last;j++){
		L->Data[j-1] = L->Data[j];
	}
	L->Last--;
	return true;
} 
