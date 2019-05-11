// _Z4seariii res
#include<iostream>
#include<cstdio>
using namespace std;
int mark[103][103]={};
int city[103]={};
int top[102]={};
int K,N,R;
int res=999999;
struct road
{
	int so,des,len,toll;
};
road mat[102][1000]={};
void sear(int n,int to,int le)
{
	int i;
	if(le>res||to>K)return;
	if(n==N)
	{
		if(to<=K&&le<res)
		res=le;
		return;
	}
	for(i=top[n]-1;i>=0;i--)
	{
		if(mark[n][mat[n][i].des]==1||le+mat[n][i].len>res||to+mat[n][i].toll>K||city[mat[n][i].des]==1)
		continue;
		mark[n][mat[n][i].des]=1;
		city[mat[n][i].des]=1;
		sear(mat[n][i].des,to+mat[n][i].toll,le+mat[n][i].len);
		mark[n][mat[n][i].des]=0;
		city[mat[n][i].des]=0;
	}
	return;
}
int main()
{
	int S,D,L,T;
	scanf("%d%d%d",&K,&N,&R);
	int i;
	for(i=1;i<=R;i++)
	{
		scanf("%d%d%d%d",&S,&D,&L,&T);
		road tmp;
		tmp.so=S;
		tmp.des=D;
		tmp.len=L;
		tmp.toll=T;
		mat[tmp.so][top[tmp.so]++]=tmp;
	}
	city[1]=1;
	sear(1,0,0);
	if(res<999999)printf("%d\n",res);
	else printf("-1\n");
	return 0;
}