#include<iostream>
using namespace std;

int find(int k)
{
	int m,i,dead,begin,next;
	for(m=k+1; ;m++)
	{
		if(m%(k+1)!=0&&m%(k+1)!=1)
			continue;

		begin=1;
		dead=0;
		
		for(i=1;i<=k;i++)
		{	
			next = (begin+m-1)%(2*k-dead);
			if(next==0)
				next=2*k-dead;

			if(next == 2*k-dead)
				begin =1;
			else
				begin =next;

			dead++;
			
			if(next<=k)
				break;
		}
		if(i==k+1)
			break;
	}
	return m;
}
int main()
{
	int k,m;
	while(cin>>k&&k!=0)
	{	
		int m = find(k);
		cout<<m<<endl;
		
	}
	return 0;  
} 
