#include <vector>
#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{	int k,n,m,t,u,r=0,s1=1,s2=1;
	vector <int> v;
	while(cin>>k)
	{
		if(k==0) break;
		int *a=new int[2*k+1];
		int *p=new int[2*k];
		for(n=0;n<2*k;k++)
			a[n+1]=2*k+1;//对给定的K赋值给数组
		
		for(n=0;;n++)
		{
			for(m=2*n*k+k+1;m<2*n*k+2*k+1;m++)
			{
				u=1;
				for(t=0;t<2*k-1;t++)
				{
					while(m>0)
					{
						if(u>k) u=1;
						if(a[u++]==0) continue;
						m--;
					}
					p[r++]=a[--u];
					a[u]=0;
				}
				for(t=0;t<k;t++)
					if(p[t+1]<=k) s1=0;
				for(t=0;t<k-1;t++)
					if(p[t+k+1]==1||p[t+k+1]>k) s2=0;
				if(s1*s2!=0) break;
			}
		 	s1=1;s2=1;
			if(s1*s2!=0) {v.push_back(m);break;}
		}
	}
	for(t=1;t<v.size();t++)
		cout<<v[t]<<endl;
	return 0;
}

