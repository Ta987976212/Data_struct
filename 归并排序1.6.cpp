#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 15
typedef int ElementType;
/////////////////////函数
void Msort(ElementType A[],ElementType TmpA[],int L,int RightEnd);
void MergeSort(ElementType A[],int N);
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd);


int main()
{
	int A[MAXSIZE] = {44,12,59,36,62,43,94,7,35,52,85};
	int i;
	MergeSort(A,11);
	for(i=0;i<11;i++){
		printf("%d ",A[i]);
	}
	return 0;
} 
void MergeSort(ElementType A[],int N)
{
	ElementType * TmpA;
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));
	/*如果申请成功*/
	if(TmpA != NULL){
		Msort(A,TmpA,0,N-1);
		free(TmpA);
	}
	else{
		printf("申请失败");
	}
}
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd)
{
	int LeftEnd = R-1;int Tmp = L;
	int NumElements = RightEnd-L+1;
	int i;
	
	while(L<=LeftEnd && R <= RightEnd){
		if(A[L] <= A[R]){
			TmpA[Tmp++] = A[L++];
		}
		else{
			TmpA[Tmp++] = A[R++];
		}
	}
	while(L<=LeftEnd){
		TmpA[Tmp++] = A[L++];
	}
	while(R <= RightEnd){
		TmpA[Tmp++] = A[R++];
	}
	
	for(i=0;i<NumElements;i++,RightEnd--){
		A[RightEnd] = TmpA[RightEnd];
	}
}
void Msort(ElementType A[],ElementType TmpA[],int L,int RightEnd)
{
	int Center;
	
	if(L< RightEnd){
		Center = (L+RightEnd)/2;
		Msort(A,TmpA,L,Center);
		Msort(A,TmpA,Center+1,RightEnd);
		Merge(A,TmpA,L,Center+1,RightEnd);
	}
}
