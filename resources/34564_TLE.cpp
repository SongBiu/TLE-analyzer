#include <stdio.h>

int fun(int n, int t, int i)
{
    if(i == 1)
        return ( n + t - 1) % n;
    else
        return (fun(n - 1, t, i - 1) + t) % n;
}


int main()
{
	int k;
	scanf("%d", &k);
	
	while(k != 0)
	{
		for(int m = k + 1; ; m++)
		{
			bool success = true;
			
			for(int i = 2; i <= k; i++)
			{
				if(fun(2*k, m, i) < k)
				{
					success = false;
					break;
				}
			}
			
			if(success)
			{
				printf("%d\n", m);
				break;
			}
			
			if(m % (2*k) == 0)
			{
				m += k;
			}
		}

		scanf("%d", &k);
	}
	return 0;
}