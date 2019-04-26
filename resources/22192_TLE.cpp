#include <stdio.h>
#include <stdlib.h>

int save[15] = {0};

int main(void)
{
	int k, i, j, m, total;
	int count, start;

	while(scanf("%d", &k), k != 0)
	{
		if(save[k] != 0)
		{
			printf("%d\n", save[k]);
			continue;
		}
		total = 2 * k;
		for(i = 1; ; i++)
		{
			for(j = i * total / 2 + 1; j < i * total + 1; j++)
			{
				if(((j + k) % (k + 1) != 0) && (j % (k + 1) !=0))
					continue;
				m = total;
				count = 0;
				for(start = 1; m > k; m--)
				{
					start = (start + j - 1) % m;
					if(start > 0 && start <= k)
						break;
					else
						count++;					
					start = (start == 0) ? 1 : start;
				}
				if(count >= k)
					break;
			}
			if(count >= k)
				break;
		}
		save[k] = j;
		printf("%d\n", j);
	}
	
	return 0;
}
