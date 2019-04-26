#include<iostream>
using namespace std;
  
int main()
{
	int k,i,m,n,ans[28]={0};
	//n=2*k;
	while(cin>>k)
	{
		if(k>0)
		{
			m=1;
			for(i=1;i<k+1;i++)
			{
				n=2*k;
				ans[i]=(ans[i-1]+m-1)%(n-i+1);
				if(ans[i]<k)
				{
					m++;
					i=0;
					continue;
				}
			}
				//else
				//{
			cout<<m<<endl;
					//break;
				//}			
		}
		else
			break;
	}
	return 0;
}