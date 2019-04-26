#include<stack>
#include<list>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<numeric>
#include<queue>
#include<cstring>
#include<stdio.h>
using namespace std;
template<class Ty,class Tx>Ty to (Tx x){Ty y;stringstream ss("");ss<<x;ss.seekg(0);ss>>y;return y;};
long long gcd(long long a,long long b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(a%b,b);};//最大公约数
long long gbs(long long a,long long b){return a*b/gcd(a,b);}//最小公倍数
template<class Ty,class Tx>vector<Ty> to(vector<Tx> x){vector<Ty>r;for(int i=0;i<x.size();i++)r.push_back(to<Ty>(x[i]));return r;}
/*
struct Node
{
	int from,to,v;
};
struct cmp
{
	bool operator ()(Node& a,Node& b)
	{
		return a.v>b.v;
	}
};*/
struct node
{
	bool bad;
	int next;
}t[30];
int main()
{
	//freopen("in.in","r",stdin);
	int k;
	while(cin>>k)
	{
		if(k==0)break;
		bool b=false;
		memset(t,0,sizeof(node));
		long long m=k+1;
		while(1)
		{
			int siz=2*k;
			for(int i=0;i<2*k;i++)
			{
				if(i<k){t[i].bad=false;t[i].next=i+1;}
				else if(i<2*k){t[i].bad=true;t[i].next=i+1;}
			}
			t[2*k-1].next=0;
			long long now=0;
            while(1)
			{
				now+=m;
				now--;
				if(now>siz)
				{
					now=now%siz;
				}
				if(t[now].bad==false)
				{
					if(siz!=k)
					break;
					else
					{
						b=true;
						cout<<m<<endl;
						break;
					}
				}
				siz--;
				t[siz-1].next=0;
			}
            m++;
			if(b)break;
		}
	}
    return 0;
}
