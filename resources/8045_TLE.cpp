#include <stdio.h>

int joseph(int n)
{
	int i;
	int midval = 0;
	
	for (i = 1; 1; i++)
	{
		int count = n;
		midval = 0;
		while (count > 0)
		{
			midval = (midval + i) % (n + count);
			if(midval < n)
				break;
			count--;
		}
		if (count != 0)
		{
			continue;
		}
		return i + 1;
	}
}

int main(void)
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		printf("%d\n", joseph(n));
	}
	return 0;
}
