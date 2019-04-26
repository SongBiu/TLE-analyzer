#include <iostream>
using namespace std;
bool prove(int i,int j,int size,int k)
{
	while(1)
	{
		if(i>0&&i<=k)
			return false;
		size--;
		if(size==k)
			return true;
		i+=j-1;
		if(i%size)
			i%=size;
		else i=size;
	}
}
int main()
{
	int k,i,j,size,k2,n;
	bool result;
	while(cin>>k,k!=0)
	{
		k2=2*k;
		for(n=1;;n++)
		{
			result=false;
			for(j=(2*n-1)*k+1;j<2*n*k;j++)
			{
				size=k2;
				i=j%k2;
			    result=prove(i,j,size,k);
			    if(result)
				{
					cout<<j<<endl;
					break;
				}
			}
			if(result)
				break;
			else
			{
				size=k2;
				i=k2;
			    result=prove(i,j,size,k);
			    if(result)
				{
					cout<<j<<endl;
					break;
				}
			}

		}
	}
	return 0;
}