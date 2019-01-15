#include<stdio.h>
#include<stdlib.h> 
typedef int ElementType;
struct LNode{
	ElementType Data;
	struct LNode * Next;
};
typedef struct LNode * List;
//////////////////////函数 
List MakeList();
void PtintList(List L);
int Lenght(List L);
ElementType FindKth(List L,int K);
List FindValue(List L,int K);
List Insert(List L,ElementType X,int i);
List Delete(List L,int i);

int main()
{
	List L = MakeList();
	PtintList(L);
	printf("表的长度是:%d\n",(Lenght(L)));
	printf("第2个的值是:%d\n",FindKth(L,2));
	Insert(L,99,3);
	PtintList(L);
	printf("删除后"); 
	Delete(L,3);
	PtintList(L);
	return 0;
}
List MakeList()
{
	List L,PtrL = (List)malloc(sizeof(struct LNode));
	
	int tmp,i;
	printf("请输入你要输入的次数");
	scanf("%d",&tmp);
	L = (List)malloc(sizeof(struct LNode));
	scanf("%d",&(L->Data));
	L->Next = NULL;
	PtrL = L;
	for(i=1;i<tmp;i++){
		List TmpL = (List)malloc(sizeof(struct LNode));
		scanf("%d",&(TmpL->Data));
		PtrL->Next  = TmpL;
		PtrL = TmpL;
		TmpL->Next = NULL;
	}
	return L;
	 
}
void PtintList(List L)
{
	int i=0;
	while(L!=NULL){	
		printf("%d ",L->Data);
		L = L->Next;
	}
	printf("\n");
}
int Lenght(List L)
{
	int cnt = 0;	
	while(L!= NULL){
		cnt++;
		L = L->Next;
	}
	return cnt;
}
/*按照序号查找*/
ElementType FindKth(List L,int K)
{
	int cnt = 1;
	while(L&& cnt < K){
		cnt++;
		L = L->Next; 
	}
	if(cnt == K && L){
		return L->Data;
	}
	else return -1;
}
List FindValue(List L,int K)
{
	while(L && L->Data != K){
		
		L= L->Next;
	}
	if(L && L->Data == K ){
		return L;
	}
	else return NULL;
}
List Insert(List L,ElementType X,int i)
{
	List PtrL,tempL;
	tempL = L;
	int cnt=1;
	while(L && cnt < i-1){
		L = L->Next;
		cnt++;
	}
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Data = X;
	PtrL->Next =L->Next;
	L->Next = PtrL;
	return  tempL;
}
List Delete(List L,int i)
{
	int cnt=1;
	List returnL,temp;
	returnL = L; 
	while(L && cnt< i-1){
		L = L->Next;
		cnt++;
	}
	temp = L->Next;
	L->Next = temp->Next;
	free(temp);
	return returnL;
}

