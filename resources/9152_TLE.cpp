#include<iostream>
using namespace std;
int main()
{
	int kk,n,m,a[301];
	while(1)
	{
		cin>>kk;
		if(kk==0)
			break;
		n=2*kk;
		m=2;
		while(1)
		{
			int count=0,k=1,i=1,judge=1;
			for(i=1;i<=n;i++)
				a[i]=1;
			i=1;
			while(count<=kk-1)
			{
				i=i%n;
				if(i==0)
					i=n;
				if(k%m!=0)
				{
					if(a[i]==1)
						k++;
					i++;				
				}
				else
				{
					if(a[i]==1)
					{
						if(i<=kk)
						{
							judge=0;
							break;
						}
						a[i]=0;
						count++;
						k=1;					
					}
					else
					{
						i++;
					}
				}	
			}
			if(judge)
				break;
			m++;
		}
		cout<<m<<endl;
	}
	return 0;
}



