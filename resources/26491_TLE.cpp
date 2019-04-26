#include<iostream>
using namespace std;
bool Try( int m,int k)
{
	int nLeft=2*k,i=0;
	while(nLeft>k)
	{
		i=(i-1+m)%nLeft ;
		if(	i < k )
			return false;
		nLeft--;
	}
	return true;
}
int main()
{
	int k;
	while(1)
	{
		cin>>k;
		if(k==0 )
			break;
		int m=k+1;
		while(1)
		{
			if( Try(m,k) )
				break;
			if( Try(m+1,k) )
				break;
			m+=(k+1);
		}
		cout<<m<<endl;
	}
	return 0;
}