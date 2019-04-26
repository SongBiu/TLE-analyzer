#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long k,i,m;
	int a[28];
	while(scanf("%d",&k))
	{
		if(k==0)
		{
			break;
		}
		a[0]=0;
		int n=2*k;
		m=k+1;
		for(i=1;i<=k;i++)
		{
			a[i]=(a[i-1]+m-1)%(n-i+1);
			if(a[i]<k)
			{
				m++;
				i=0;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
