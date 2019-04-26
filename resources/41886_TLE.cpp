#include<stdio.h>
//#include<string.h>
bool check(int k,int count,int m,int n);
int c(int n,int m,int k);
int main()
{
	int k,n,m,i,now;
	scanf("%d",&k);
	while(k!=0)
	{
		n=k*2;
		for(m=k+1;;m++)
		{
			if(check(k,k,m,n))break;
		}
		printf("%d\n",m);
		scanf("%d",&k);
	}
	return 0;
}
bool check(int k,int count,int m,int n)
{
	for(int i=1;i<=count;i++)
	{
		if(c(n,m,i)<=k)return false;
	}
	return true;
}
int c(int n,int m,int k)
{
	if(k==1)
		return (m-1)%n+1;
	else 
	{
		int kk=c(n-1,m,k-1);
		if(kk<=(n-(m-1)%n-1))
			return kk+(m-1)%n+1;
		else
			return kk-(n-(m-1)%n-1);
	}
}