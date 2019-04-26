#include<iostream>
using namespace std;
void compute(int n)
{
	int i=0;
	long j=n+1;
	int max=2*n;
	while(1)
	{
		if((i+j-1)%max<n)
		{
			j++;
			max=2*n;
			i=0;
		}
		else
		{
			i=(i+j-1)%max;
			max--;
			if(max==n)
			{
				printf("%ld\n",j);
				break;
			}
		}
	}
}
int main()
{
	int n;
	
	while(scanf("%d",&n)&&n)
	{
		
			compute(n);
		
		
	}
	return 0;
}
