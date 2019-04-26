#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	int n;
	int g[20][20];
	while(cin>>n,n)
	{
		for(int i=0;i<n;++i)
		{
			g[0][i]=i;
		}
		for(int m=n+1;;++m)
		{
			if((m-1)%(2*n)<n)
				continue;
			if(((m-1)%(2*n-1)+m)%(2*n)<n)
				continue;
			for(int j=1;j<=n;++j)
			{				
				for(int i=0;i<n;++i)
				{
					g[j][i]=(g[j-1][i]+m)%(n+j);
				}
			}
			sort(g[n],g[n]+n);
			if(g[n][n-1]==n-1)
			{
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}