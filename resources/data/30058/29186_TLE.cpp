#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct road{
	int start,end,length,toll;
};
bool mycomp(road a1,road a2){return a1.start<a2.start;}
int money,n,roadnum,minlength=10000000,Index[100];
bool flag[100];
road r[10000];
void getcity(int,int,int);
int main()
{
	int i;
	memset(Index,0,sizeof(Index));
	memset(flag,false,sizeof(flag));
	scanf("%d%d%d",&money,&n,&roadnum);
	for(i=0;i<roadnum;i++)
	{
		int s,e,l,t;
		scanf("%d%d%d%d",&s,&e,&l,&t);
		r[i].start=s;
		r[i].end=e;
		r[i].length=l;
		r[i].toll=t;
		Index[s]++;
	}
	sort(r,r+roadnum,mycomp);
	for(i=1;i<n;i++)
		Index[i]+=Index[i-1];
	getcity(1,0,money);
	printf("%d\n",minlength==10000000? -1:minlength);
	return 0;
}
void getcity(int m,int l,int c)
{
	int i;
	if(l>minlength) return;
	if(m==n)
	{
		if(minlength>l)
			minlength=l;
		return;
	}
	for(i=Index[m-1];i<Index[m];i++)
	{
		int re=r[i].end,rl=r[i].length,rt=r[i].toll;
		if(!flag[re-1] && rt <= c)
		{
			flag[re-1]=true;
			getcity(re,l+rl,c-rt);
			flag[re-1]=false;
		}
	}
}
