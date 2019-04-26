#include <stdio.h>
int jasho(int k)
{
	int m = k;
	int i;
	int p;
	int l;
	int t;

	for (m = k ; m < 100000000; ++m)
	{
		p = 0;
		l = 2*k;
		t = m-1;
		for (i = 0; i < k; ++i, --l)
		{
			p = (p+t)%l;
			if (p < k)
			{
				break;
			}
		}
		if (i == k)
		{
			return m;
		}
	}
	return 0;
}

int main (int argc, const char** argv)
{
	int k, j;
	int m;
	int v[13]= {2, 7, 5,	30, 169, 441,	1872,7632,1740,93313,459901,1358657,2504881};
	
	while (1)
	{
		scanf("%d", &k);
		if (k == 0)
		{
			break;
		}
		printf ("%d\n", jasho(k));
		//printf ("%d\n", v[k-1]);
		/*
		for (k = 1; k < 14; ++k)
		{
		*/

		/*
		for (m = k; m < 10000000000; ++m)
		{
			if (IsOK(m, k) == 0)
			{
				printf ("%d\n", m);
				break;
			}
		}
		
		}
		*/
		
	}
	return 0;
}