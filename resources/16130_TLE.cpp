#include <stdio.h>
void init (int a[],int n)
{
	int i;
	for (i=1;i<=n;i++)
	a[i]=i;
}
int tz(int a[],int n,int j)
{
	int i;
	for (i=j;i<=n;i++)
	a[i]=a[i+1];
	return n-1;
}
int main(int argc, char *argv[])
{
	int a[27]={0},i,count,k,n,flag,term,flag1=1;
	while (scanf("%d",&k)!=EOF)
	{	
		
		flag1=1;
		
		n=k+1;
		while(flag1)
		{count=2*k;
		init(a,count);
		flag=1;
		i=1;
		while (flag)
		{
		term=n%count;
		if(i+term-1>count)
		i=(i+term-1)%count;
		else
		i=i+term-1;
		if (i==0)
		i++;
		if(i>k)
		count=tz(a,count,i);
		else 
		flag=0;
		if(count==k)
		{printf("%d\n",n);
		flag=0;
		flag1=0;
		}
		}
		n++;
		}
	}
	return 0;
}