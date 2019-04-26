#include<stdio.h>
int main(int argc, char const *argv[])
{
	int k, i, a, b=0, m=1;
	while(scanf("%d", &k)!=EOF&&k!=0)
	{
		for(i=0;i<k;)
		{
			a=(b+m-1)%(2*k-i);
			b=a;
			i++;
			if(a<k)
			{
				i=0;b=0;m++;
			}
		}
		printf("%d\n", m);
		i=0;b=0;m=1;
	}
	return 0;
}