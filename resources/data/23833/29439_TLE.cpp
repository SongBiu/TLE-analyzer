#include<iostream>
#include <cstdio>
using namespace std;
struct road
{
	int k;
	int len;
	int t;
	int next;
}roads[10005];
int num;
int mark[120],g[105][10005];
int dir[120];
int o,p,q;
int sumlen,sumtime,nowlen;
void pass(int a,int b,int c,int d)
{
	roads[num].k=b;
	roads[num].len=c;
	roads[num].t=d;
	roads[num].next=dir[a];
	dir[a]=num;
	num=num+1;
};
bool judge;
void f(int abc)
{
/*	if(sumtime<g[abc][sumlen])
		g[abc][sumlen]=sumtime;
	else
		return ;*/
	if(abc==p)
	{
		judge=1;
		if(sumlen<nowlen)
		{
			nowlen=sumlen;
		}
	return ;
	}
	for(int i=dir[abc];i!=-1;i=roads[i].next)
	{
		if(!mark[roads[i].k]&&(sumlen+roads[i].len)<nowlen&&(sumtime+roads[i].t)<=o)
		{
			mark[roads[i].k]=1;
			sumtime=roads[i].t+sumtime;
			sumlen=sumlen+roads[i].len;
			f(roads[i].k);
			mark[roads[i].k]=0;
			sumlen=sumlen-roads[i].len;
			sumtime=sumtime-roads[i].t;

		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>o>>p>>q;
	int x,y,len,t;
	for(int i=1;i<=p;i++)
		dir[i]=-1;
	for(int j=1;j<=q;j++)
	{
		scanf("%d%d%d%d",&x,&y,&len,&t);
		pass(x,y,len,t);
	}
/*	for(int i=0;i<=100;i++)
		for(int j=0;j<=10000;j++)
			g[i][j]=100000000;*/
	for(int i=0;i<120;i++)
	{
		mark[i]=0;
	}
	sumlen=0;
	sumtime=0;
	mark[1]=1;
	nowlen=5000000;
	judge=true;
	f(1);
	if(judge==false)
	{
		cout<<"-1";
	}
	cout<<nowlen;
	//system("pause");
	return 0;
}
