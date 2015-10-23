#include <stdio.h>

#define MaxSize 1000

typedef struct stack Stack;
struct stack{
	int Data[MaxSize];
	int top,maxstack;
};

Stack stack;
void CreateStack(int M)
{
	stack.top = -1;
	stack.maxstack = M; 
}

void Push (int X)
{
	if (stack.top < stack.maxstack-1) 
		stack.Data[++stack.top] = X;
}

int Pop()
{
	if (stack.top > -1)
		return stack.Data[stack.top--];
}

int IsEmpty ()
{
	return 	(stack.top <= -1);
}

int IsFull ()
{
	return (stack.top >= stack.maxstack-1);
}

int TopNum ()
{
	return (stack.Data[stack.top]);
}



int main()
{
	int M,N,K;
	int i,j;
	int temp,flag;
	scanf ("%d %d %d", &M, &N, &K);
	for (j=0; j<K; j++){
		CreateStack(M);
		int X;
		temp = 1;
		flag = 1;
		for (i=0; i<N; i++){
			scanf ("%d", &X);
			while (1){
				if (IsEmpty()||TopNum()!=X){
					if (!IsFull())
						Push(temp++);
					else {
						flag =0;
						break;
					}
				}
				else if (TopNum() == X){
					Pop();
					break;
				}
			}

		}
		if (flag&&IsEmpty())
			printf ("YES\n");
		else 
			printf ("NO\n");
		
	}
	return 0;
}
