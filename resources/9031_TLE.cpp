#include <iostream>
using namespace std;
int f(int n,int m,int t)
{
    if(t==1) return (m-1)%n;
    else return (m%n+f(n-1,m,t-1))%n;
}
int main()
{
	int k,m,i,j;
	bool a[27];
	while(cin>>k)
	{
		if(k==0)break;
		for(m=k+1;;m++)
		{
			memset(a,true,sizeof(a));
			for(i=0;i<k;i++)
			{
				j=f(2*k,m,i+1);
				a[j]=false;
				if(j<k)break;
			}
			if(i>=k)
			{
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}