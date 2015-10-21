#include<stdio.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

void crate(){
	H[0] = MINH;
	size = 0;
}

void Insert (int X)
{
	int i;
	for (i=++size; H[i/2]>X; i/=2)
		H[i] = H[i/2];
	H[i] = X;
}

int main()
{
	int n, m, x, i, j;
	scanf ("%d %d", &n, &m);
	crate();
	for (i=0; i<n; i++){
		scanf("%d", &x);
		Insert(x);
	}
	for (i=0; i<m; i++){
		scanf("%d", &j);
		printf("%d", H[j]);
		while (j>1){
			j/=2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}
	return 0;
}
