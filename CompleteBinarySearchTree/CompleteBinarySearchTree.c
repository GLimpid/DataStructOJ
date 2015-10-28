#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int A[MAX_SIZE], T[MAX_SIZE];

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int GetLeftLength(int N)
{
	int H, X, L;
	H = (int)(log(N+1)/log(2));
	X = N+1-(int)pow(2,H);
	if (X > (int)pow(2,H-1))
		X = (int)pow(2,H-1);
	L = (int)pow(2,H-1) - 1 + X;
	return L;
}

void solve(int A[], int B[], int ALeft, int ARight, int TRoot)
{
	int n, LeftTRoot, RightTRoot, L;
	n = ARight - ALeft + 1;
	if (n==0) return;
	L = GetLeftLength(n);
	T[TRoot] = A[ALeft+L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot +1;
	solve(A,B,ALeft, ALeft+L-1, LeftTRoot);
	solve(A,B,ALeft+L+1, ARight, RightTRoot);
}

int main()
{
	int N, i, A[MAX_SIZE];
	scanf("%d",&N);
	for (i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	qsort(A,N,sizeof(int),compare);
	solve(A,T,0,N-1,0);
	int flag = 0;
	for (i=0; i<N; i++){
		if (flag == 0){
			printf("%d",T[i]);
			flag = 1;
		}
		else 
			printf(" %d",T[i]);
	}
}
