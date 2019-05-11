// _Z4funciii fmin
#include <iostream>

using namespace std;

int K,N,R;

struct ROADS
{
	int s;
	int d;
	int l;
	int t;
	int next;
} r[10010];

int fmin=90000;

bool visited[110]={0};

int headlist[110]={0};

void func(int source,int length,int rest)
{
	if(rest<0) return;
	if(source==N && length < fmin)
	{
		fmin=length;return;
	}

	int now=headlist[source];

	while(now!=0)
	{
		if(!visited[r[now].d])
		{
			visited[r[now].d]=1;
		func(r[now].d,r[now].l+length,rest-r[now].t);
		visited[r[now].d]=0;
		}

		now=r[now].next;
	}


}

int main()
{
	cin>>K>>N>>R;

	for(int i=0;i<R;i++)
	{
		cin>>r[i].s>>r[i].d>>r[i].l>>r[i].t;

		r[i].next=headlist[r[i].s];

		headlist[r[i].s]=i;

	}

	func(1,0,K);

	if(fmin<90000) cout<<fmin<<endl;
	else cout<<-1;
	return 0;
}