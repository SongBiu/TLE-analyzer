#include <iostream>
using namespace std;

struct Road
{
	int L;
	int T;
	Road *next;
};

int K,N,R;
Road croad[101];

bool find(Road *road[][101],int source,int money,int meter,bool* pass,bool *calcued,int &shortest)
{
	if(source==N)
	{
		if(shortest>meter)
			shortest=meter;
	}
	else
	{
		int tmoney,tmeter;
		bool found=0;
		Road *t;
		for(int j=1;j<N+1;j++)
		{
			if(road[source][j]!=NULL&&!pass[j])
			{
				t=road[source][j];
				while(t!=NULL)
				{
					pass[j]=1;//到过j了
					tmoney=money-t->T;
					if(tmoney<0)//没钱了
					{
						pass[j]=0;//pass还原
						t=t->next;
						continue;
					}
					tmeter=meter+t->L;
					if(shortest<tmeter)//太远了
					{
						pass[j]=0;//pass还原
						t=t->next;
						continue;
					}
					if(calcued[j]&&tmeter>=croad[j].L&&tmoney<=croad[j].T)//有更短的
					{
						pass[j]=0;//pass还原
						t=t->next;
						continue;
					}
					croad[j].L=tmeter;
					croad[j].T=tmoney;
					calcued[j]=1;
					find(road,j,tmoney,tmeter,pass,calcued,shortest);
					pass[j]=0;//pass还原
					t=t->next;
				}
			}
		}
		return found;
	}
}

int main()
{
	Road *road[101][101];
	bool pass[101],calcued[101];
	int shortest=10000000;
	int S,D,L,T;
	cin>>K>>N>>R;

	for(int i=1;i<N+1;i++)
	{
		pass[i]=calcued[i]=0;
		for(int j=1;j<N+1;j++)
			road[i][j]=NULL;
	}
	for(int w=0;w<R;w++)
	{
		cin>>S>>D>>L>>T;
		Road *p,*t=road[S][D];
		p=new Road;
		p->L=L;
		p->T=T;
		p->next=NULL;
		if(t==NULL)road[S][D]=p;
		else
		{
			while(t->next)
				t=t->next;
			t->next=p;
		}
	}
	pass[1]=1;
	find(road,1,K,0,pass,calcued,shortest);
	if(shortest==10000000)
		cout<<-1;
	else cout<<shortest;
	return 0;
}