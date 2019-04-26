#include<stdio.h>
int k;
int ans;
int a[30]={};
int joseph(int n)
{
	int t=k*2,flag=1;//t剩余人数
	int i;
	for(i=0;i<=k*2+1;i++)
			a[i]=0;
		for(i=1;i<=k*2;i++)
			a[i]=1;
	i=1;
	while(t>k){
		if(a[i]==0)
			i++;
		else if(a[i]!=0 && flag!=n)
		{
			i++;flag++;
		}
		else if(a[i]!=0 && flag==n)
		{
			a[i]=0;i++;flag=1;t--;
		}
		if(i>k*2) i=1;
	}
	int j;
	for(j=1;j<=k;j++)
		if(a[j]==0)	return joseph(n+1);
	return n;
}

int main()
{
	while(1)
	{
		scanf("%d",&k);
		if(k==0) break;
		int i;
		
		ans=joseph(k+1);
		printf("%d\n",ans);
	}
}