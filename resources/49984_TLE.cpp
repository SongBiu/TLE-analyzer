#include<iostream> 
#include<memory.h>
using namespace std;
int main()
{
	int n;
	int i,j,k;
	
	int b[100];
	int good,bad;
	int count;
	int sum;
	cin>>k;
	int flag;
	j = 0;
	while(k != 0)
	{	
		
		flag = 0;
		for(i = 2;; i++)
		{	
		 	sum = 2*k;good = k;bad = k;
			int visit[100]={0};
			n=0;
			while(sum>0)
			{
				count = 0;
				while(count < i)
				{			
					if(!visit[n])
					{
						count++;
					}
					if(count == i) break;
					n = (n+1)%(2*k);
				}
				//cout<<n;
				if(n<k&&bad>0) break;
				if(n<k&&bad==0) {flag = 1;break;}
				if(n>=k) 	   bad--;
				visit[n]=1;
				sum--;
			}
			if(flag==1) {b[j++] = i;break;}
		}
		cin>>k;
	}
	for(i = 0;i<j;i++)
	cout<<b[i]<<endl;
	return 0;
}