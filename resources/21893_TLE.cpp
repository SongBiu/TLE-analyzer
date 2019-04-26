#include<iostream>
using namespace std;
int main()
{
	int k,n,p,m;
	while(cin>>k)
	{
		if(k==0)
			return 0;
		n = k + k;
		for(m=1;;m++)
		{
			if((m%n)>=1 && (m%n)<=k)
				continue;
			bool flag=0;
			int no=0;
			p=0;
			bool judge[30]={};
			for(int i=1;;i++)
			{
				int num=0;
				int mo=(m-1)%(n-no)+1;
				while(num!=mo)
				{
					p++;
					if(p==n+1)
						p=1;
					while(judge[p])
					{
						p++;
						if(p==n+1)
							p=1;
					}
					num++;
				}
				judge[p]=1;
				no++;
				if(p<=k)
				{
					break;
				}
				if(no==k)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		cout<<m<<endl;
	}
	return 0;
}

