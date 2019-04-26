#include<stdio.h>
int main()
{
	int k,n,m,temp,p;
	while(scanf("%d",&k))
	{
		if(k==0)
			break;
		m=k;
		temp=k+1;
		while(1)
		{
			n=2*k;
			while(1)
			{
				m++;
				if((m%n==0||m%n>=k+1)&&(m%temp==0||m%temp==1))
					break;
			}
			p=1;
			while(1)
			{
				if(n==k)
				{
					printf("%d\n",m);
					goto end;
				}
				p=(m%n+p)%n-1;
				if(p<0)
					p=p+n;
				if(p<=k&&p>0)
					break;
				if(p==0)
					p=p+1;
				n--;
				p=p%n;
			}
		}
end:;
	}
	return 0;
}