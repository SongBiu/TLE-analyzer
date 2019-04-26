#include<stdio.h>
#include<string.h>
int a[30];
int ans[15];
int main()
{
	int i,j,k,t;
	memset(ans,0,sizeof(ans));
	scanf("%d",&k);
	while(k>0)
	{
		if(ans[k]>0)
			printf("%d\n",ans[k]);
		else
		{
		for(i=k+1;;i++)
		{
			if(i%(2*k)==1)
				i+=k;
		    for(j=0;j<k;j++)
			   a[j]=j;
			for(t=0;t<k;t++)
			{
			   for(j=k+1;j<=2*k;j++)
			   {
				   a[t]=(a[t]+i)%j;
			   } 
			   if(a[t]>=k)
				 break;
			}
			if(t==k)
			{
				ans[k]=i;
				printf("%d\n",i);
				break;
			}
		}
		}
		scanf("%d",&k);
	}
	return 0;
}


			
