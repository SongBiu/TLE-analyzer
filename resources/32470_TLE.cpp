#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
	
int main(void)
{
	int k = 0;
	int m = 0;
	int a = 0, b = 0;
	int cnt = 0;
	int n = 0;
	while(1)
	{

		scanf("%d", &k);
		if(!k)
			break;
		for(n = 0; ; n++)
		{
			for(m = (2*n+1)*k+1; m <= (2*n+2)*k; m++)
			{
				cnt=0;
				a=m; 
				b = 2*k;
				while(1)
				{
					int c = a%b;
					if(!c)
						c = b;
					if(c > k)
						cnt++;
					else
						break;
					a = m + c - b;
					b--;
				}
				if(cnt >= k)
				{
					printf("%d\n", m);
					goto label;
				}
			}
		}
label:;
		
	}


	return 0;

}