#include<iostream>
using namespace std;
int a[14],i,j;
int fun(int k,int m)
{
	int s=0,t=k*2;
	for(i=1;i<=k;i++)
	{
		s=(s+m-1)%t;
		--t;
		if(s<k)
		return 0;
	}
	return 1;
}
int main()
{
	for(i=1;i<=13;i++)
	{
		j=i+1;
		while(!fun(i,j))++j;
		a[i]=j;
	}
	while(cin>>i&&i)
		cout<<a[i]<<endl;
 return 0;
} 