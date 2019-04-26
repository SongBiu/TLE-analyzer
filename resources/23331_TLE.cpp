#include<stdio.h>
#include <string.h>
int main()
{
	int i,j,k,t,x; 
	int a[14];
	memset(a,0,14*sizeof(int));
	do
	{
		scanf("%d",&k);
		if (k==0) break;
		for(j=k+1;;j+=1+k)
		{
			for(i=j;i<=j+1;i++)
			{
				t=2*k;
				x=0;
				while (1)
				{
					x=(x+i-1)%t+1;
					if(x>k)
					{
						t--;
						x--;
					}					
					else break;
				}
				if (t==k)
				{
					a[k]=i;
					break;
				}
			}
			if (t==k)
			{
				printf("%d\n",a[k]);
				break;
			}
		}		
	}while(1);
	return 0;
}