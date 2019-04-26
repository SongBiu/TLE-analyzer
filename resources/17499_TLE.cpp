#include<iostream>
using namespace std;
int k;
int vis[14];
int find(int begin,int n,int m)
{
	int pos = (m+begin-1)%n;
	if(pos < k) return 0;
	if(n == k) return 1;
	return find(pos%(n-1),n-1,m);
}
int main()
{
	memset(vis,-1,sizeof(vis));
	while(cin>>k && k)
	{
		if(vis[k-1] != -1) cout<<vis[k-1]<<endl;
		else
		{
			int i = 1;
			while(true)
			{
				if(find(0,2*k,i)) 
				{
					cout<<i<<endl;
					vis[k-1] = i;
					break;
				}
				i++;
			}
		}
	}
	return 0;
}