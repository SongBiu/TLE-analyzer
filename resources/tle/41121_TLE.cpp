// _Z3dfsi ans
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class road{
	public:
		int s,e,l,m;
		road(int p,int a,int b,int c):s(p),e(a),l(b),m(c){}; 
		bool operator<(const road &p)const
			{if(s==p.s)
				return e<p.e;
			else
				return s<p.s; 
			}
		bool operator==(const road &p)const
			{return (s==p.s&&e==p.e&&l==p.l&&m==p.m);}
};
vector<road> sro;
int n,k,ans=1<<30,ls=0,lans[105][10005]={0};
bool mark[105]={0};
void dfs(int w)
{if(mark[w]==1|ls>=ans|k<0)return;
if(w==n){ans=ans>ls?ls:ans;return;}
mark[w]=1;
auto i=find(sro.begin(),sro.end(),road(w,0,0,0));
i++;
while(i->s==w&&i!=sro.end())
	{
	ls+=i->l;
	k-=i->m;
	//cout << w <<"->"<<i->e<<": "<< ls <<' '<< k<<endl;
	dfs(i->e);
	k+=i->m;
	ls-=i->l;
	i++;
	}
mark[w]=0;
}
int main()
{int r;
cin >> k >> n >> r;
for(int i=1;i<=r;i++)
	{int a,b,c,d;
	cin >> a>>b >> c >>d;
	sro.push_back(road(a,b,c,d));
	}
for(int i=1;i<=n;i++)
	sro.push_back(road(i,0,0,0));
sort(sro.begin(),sro.end());
//mark[1]=1;
dfs(1);
if(ans==1<<30)
	cout << -1 << endl;
else
	cout << ans << endl;
return 0;}