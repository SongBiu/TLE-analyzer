#include<stdio.h>

int main()
{
	int k,s,m;
	int ans[30];
	for (int i=0;i<=29;++i)
	{
		ans[i]=0;
	}
	
	while(true)
	{
		scanf("%d",&k);
		if (k==0) break;
		m=k+1;
		while(true)
		{
			ans[0]=1;
			for (int i=1;i<=k;++i)
			{
				ans[i]=(ans[i-1]+m-2)%(2*k+1-i)+1;
				//printf("Case %d : the %dth killed person is %d\n",m,i,ans[i]);
				if (ans[i]<=k)
				{	
					break;
				}
				s=i;
			}
			if (s==k)
			{
				printf("%d\n",m);
				break;
			}
			else
				m++;
		}
	}
	
	return 0;
}