#include<iostream>  
#include<cstring>
using namespace std;  
int joseph[14]={0};
int main()
{
	int k,m;
	cin>>k;
	while(k)
	{
		m=k+1;
		for(int i=1;i<=k;i++)
		{
			joseph[i]=(joseph[i-1]+m-1)%(2*k-i+1);
			if(joseph[i]<k)
			{
				i=0;
				m++;
			}
		}
		cout<<m<<endl;
		cin>>k;
	}
	return 0;
}




