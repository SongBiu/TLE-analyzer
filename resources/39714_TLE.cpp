#include <stdio.h>
int main()
{
    int i,m,n,p[100]={0},k;
    while(scanf("%d",&k)&&k)
    {
    	
    	n=2*k;
    	m=0;
		p[0]=0;
    	for(i=1;i<=k;i++)
    	{
    		p[i]=(p[i-1]+m-1)%(n-i+1);
		    if(p[i]<k)
		    {
		    	i=0;
		    	m++;
			}
		}
		
    printf("%d",m);	
	}
}