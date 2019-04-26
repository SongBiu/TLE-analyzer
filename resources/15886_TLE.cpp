#include <iostream>
using namespace std;

void cir(int k)
{
	for(int m = k+1; ; ++m)
	{
		int i = 0, p;
		for(p = 1; p <= k; ++p)
			if((i = (i+m-1)%(k*2+1-p)) < k)
				break;
		if(p > k)
		{
		    printf("%d\n", m);
		    return;
		}
	}
	return;
}

int main(void)
{
	int k;
	while(scanf("%d", &k) && k)
		cir(k);
	return 0;
}