
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 150

struct Node
{
	int b;
	int c;
	int l;
}a[N][N];
int k,n,r;
int max;
int visit[N];

void DFS(int c,int sum,int s)
{
	
	int i;
    for(i = 1; i<=a[c][0].b;i++)
	{
		if(!visit[a[c][i].b]&&s+a[c][i].c<=k&&(sum+a[c][i].l<max||max==-1))
		{
			if(a[c][i].b==n)
			{
				max = sum + a[c][i].l;
				continue;
			}
			visit[a[c][i].b] = 1;
			DFS(a[c][i].b,sum+a[c][i].l,s+a[c][i].c);
			visit[a[c][i].b] = 0;
		}
	}
}

int main()
{
	int i,j;
	int begin,end;
	clock_t s;
	
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&k,&n,&r);
	memset(a,0,sizeof(a));
	for(i = 1; i<= r; i++)
	{
		scanf("%d %d",&begin,&end);
		a[begin][0].b++;
		a[begin][a[begin][0].b].b = end;
		scanf("%d %d",&a[begin][a[begin][0].b].l,&a[begin][a[begin][0].b].c);
	}
	max = -1;
	memset(visit,0,sizeof(visit));
	visit[1] = 1;
	DFS(1,0,0);
	if(max==-1)
		printf("-1\n");
	else
		printf("%d\n",max);
	return 0;
}
