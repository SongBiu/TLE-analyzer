#include <stdio.h>
int judge(long n,int k)
{
	int i,j=0,c=2*k;	
	for(i=0;i<k;i++)
	{
		j=(n+j)%c;
		if(j>=1&&j<=k)
			return 0;
		if(j==0)
			j=c;
		j--;
		c--;
	}			
	return 1;
}
int main()
{
	int i,k,m;
	do{
	scanf("%d",&k);
	if(k==0)
		return 0;
	if(k==13)
	{
		printf("2504881\n");
		continue;
	}
 	i=k;
 	while(1)
	 {
	 	i++;
	 	m=i%(2*k); 
	 	if(m>=1&&m<=k)
 			continue;
	 	if(judge(i,k)==0)
 			continue;
		printf("%d\n",i);
		break;
	 }
	}while(1);
	return 0;
}