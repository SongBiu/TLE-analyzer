#include<iostream>
using namespace std;


int main()
{
	int k;
	while(cin>>k && k)
	{
		int location=0;
		int total=2*k;
		int stride=k+1;
		for(int i=1;i<=k;i++)
		{
			location=(location+stride-1)%(total-i+1);
			if(location<k)
			{
				stride++;
				i=0;
				location=0;
			}
		}
		cout<<stride<<endl;
	}
}