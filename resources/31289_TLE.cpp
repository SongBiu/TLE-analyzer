#include<stdio.h>
int main()
{
	int num[30],i,j,k;
	while(1)
	{
		scanf("%d",&k);
		for(i=0;i<2*k;i++)
			num[i]=i+1;
		if(k==0) return 0;
		for(i=k+1;;i++)
		{
			int j,log,a,l,n,del;
			log=0;
			a=0;
			n=2*k;
			for(j=1;j<=k;j++,n--)
			{
				a+=i-1;
				a=a%n;
				del=num[a];
				for(l=i+1;l<n;l++)
					num[l-1]=num[l];
				if(del>k&&del<=2*k) log++; else log=-1;
				if (log==-1) break; 
			}
			if (log==-1) continue;
			if(log==k)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
