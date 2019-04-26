#include<stdio.h>
#include<string.h>
int main()
{
	long k[14]={0},p;
	int i,j,n,m,t,a[27];
	for(i=1;i<14;i++)
	{
		p=1;
		while(1)
		{
			memset(a,0,sizeof(a));
			t=0;
			for(j=2*i;j>i;j--)
			{	
				m=p%j;
				if(m==0)m=j;
				while(m)
				{
					t++;t%=(2*i);
					if(t==0)t=2*i;
					if(a[t]==0)m--;
				}
				if(t<=i)break;
				a[t]=1;
			}
			if(j==i){k[i]=p;break;}
			p++;
		}
		printf("%d\n",k[i]);
	}
	/*while(scanf("%d",&n)&&n!=0)
	{
		printf("%ld\n",k[n]);
	}*/
	return 0;
}
