#include<iostream>
using namespace std;

int main()
{
	int k,v;
	while(cin>>k&&k)
	{
		int m=1,i;
		while(m++)
		{
			int n=2*k;
			int t=0,tmp=0;
			bool end=true;
			for(i=0;i<k;i++)
			{
				if(end)	tmp=m;
				else tmp=m+t-1;
				t=tmp%(n);
				if(t==0) end=true;
				else end=false;
				if(t>=1 && t<=k) break;
				n--;
			}
			if(i==k)
			{
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}
	