#include <stdio.h>
int main()
{
	long k,m[100],num,n,i,t;
	for(n=0;n<100;n++)
	{
		scanf("%ld",&k);
		if(k==0)	break;
		num=2*k;
		for(m[n]=1;;m[n]++)
		{
			t=1;
			for(i=0;i<k;i++)
			{
				t=(t-1+m[n])%(num-i);
				if(t==0)	t=num-i;
				if(t<=k)	break;
				if(i==k-1)	goto skip;
			}
		}
skip:;
	}
	for(i=0;i<n;i++)
	{
		printf("%ld\n",m[i]);
	}
	return 0;
}
