#include<stdio.h>
int main()
{
	int k, m, position, remain, i, j;

	while(1)
	{
		scanf("%d", &k);
		if(!k) break;

		i = 1;
		while(1)
		{
			for(m = i * k + 1; m <= (i + 1) * k; m++)
			{
				remain = 2 * k;
				position = 0;
				for(j = 0; j < k; j++)
				{
					position = (position + m - 1) % remain;
					if(position < k) break;
					else remain --;
				}
				if(j == k) break;
			}
			if(j == k) break;
			i += 2;
		}
		printf("%d\n", m);
	}

	return 0;
}