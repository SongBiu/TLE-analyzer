#include<stdio.h>
bool work(int k,int m)
{
	int i=0;
	int len=2*k;
	while(len>k)
	{
		i=(i+m-1)%len;
		if(i<k)
		return 0;
		len--;
	}
	return 1;
}
int main()
{
	int m,k;
	int i,j,sign,r;
	
	while(1)
	{
		scanf("%d",&k);
		if(k==0) break;
		
		sign=0;
		for(i=0;;++i)
		{
			if(sign)
				break;
			
			for(j=k+1;j<=2*k;j++)
			{
			  m=2*k*i+j;
			  if(work(k,m))
			  {
			  	sign=1;
			  	break;
			  }
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
	