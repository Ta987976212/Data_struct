#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int KMP(char * string,char * pattern);
void BuildNext(char * pattern,int *Next );

int main()
{
	char string[]="tjsahhah";
	char pattern[] ="AA";
	int P = KMP(string,pattern);
	if(P==-1)  printf("ц╩спур╣╫");
	else printf("%s",string+P);
	return 0;
}
int KMP(char * string,char * pattern)
{
	int n = strlen(string);
	int m = strlen(pattern);
	int i=0,j=0,*Next;
	
	Next =(int *)malloc(sizeof(int)*m);
	BuildNext(pattern,Next);
	
	while(i<n && j<m){
		if(string[i] == pattern[j]) { i++;j++; }
		else if(j>0) j = Next[j-1]+1;
		else i++;
	}
	return (j==m) ? (i-m) :-1;
}
void BuildNext(char * pattern,int *Next )
{
	int i,j;
	int m = strlen(pattern);
	Next[0] = -1;
	for(j=1;j<m;j++){
		i=Next[j-1];
		while((i>=0) && pattern[i+1] != pattern[j] )
			i = Next[i];
		if(pattern[i+1] ==pattern[j])
			Next[j] = i+1;
		else Next[j] =-1;
	}
}
