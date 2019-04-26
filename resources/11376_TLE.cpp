#include "stdio.h"

int k,m;

bool find(int bad,int pop)
{
	if(bad==0) return true;
	pop=(pop+m-1)%(bad+k);
	if(pop<k) return false;
	else return find(bad-1,pop);
}

int main()
{
	while(1)
	{
		scanf("%d",&k);
		if(k==0) break;

		for(m=1;;m++)
			if(find(k,0))
				break;

		printf("%d\n",k);
	}
	return 0;
}