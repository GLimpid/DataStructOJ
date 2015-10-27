#include<stdio.h>
#include<string.h>

#define MaxSize 30

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

int pre[MaxSize], in[MaxSize], post[MaxSize];
int root;

void solve(int preL, int inL, int postL, int n)
{
	if (n==0) 
		return;
	if (n==1) {
		post[postL] = pre[preL];
		return;
	}
	root = pre[preL];
	post[postL+n-1] = root;
	int i,L,R;
	for (i=0; i<n; i++)
		if(in[inL+i] == root) break;
	L = i; R = n-L-1;
	solve(preL+1, inL, postL, L);
	solve(preL+L+1, inL+L+1, postL+L,R);
}





int main()
{
	int N;
	int Po=0,Pu=0; 
	char *s,str[5];
	s = str;
	int n;
	scanf("%d", &N);
	CreateStack(N);
	int i=0, j=0;
	while (Po<N || Pu<N){	
		scanf("%s",s);
		if (!strcmp(s,"Push")){
			scanf("%d",&n);
			Push(n);
			pre[i] = n;
			i++;
			Pu++;			
		}
		else if(!strcmp(s,"Pop")){
			in[j] = Pop();
			j++;
			Po++;
		}
	}
	
	solve(0,0,0,N);
	int flag = 0;
	for (i=0;i<N;i++){
		if (flag==0){
			printf("%d",post[i]);
			flag =1;
		}
		else
			printf(" %d",post[i]);
	}
	return 0;
	
}
