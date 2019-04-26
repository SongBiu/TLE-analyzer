#include<iostream>
#include<memory>
using namespace std;
int main()
{
	bool guy[29];
	int k;
line2:	while(cin>>k&&k!=0)
	{
		int i,j,n,p,q=0,count=0;
		for(i=1;i<=10;i++)
		{
			for(j=1;;j++)
			{
				n=(2*i-1)*k+j;
				memset(guy,0,sizeof(guy));
				for(p=1;count!=k;p++)
				{
					if(guy[p]==0)
					{q++;}
					if(q==n)
					{
						if(p<=k)
							goto line;
						guy[p]=1;
						count++;
						q=0;
					}
					if(p==2*k)
						p=0;
				}
				cout<<n<<endl;goto line2;
line:			q=0;count=0;continue;
			}
		}
	}
	return 0;
}
