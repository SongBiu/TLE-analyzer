#include<stdio.h>

int k;
int m;
int population;
int the_victim;

int main()
{
	while( scanf( "%d", &k ), k )
	{
		for( m = k + 1;; )
		{
			the_victim = 1;
			population = k<<1;
			for( ; population != k; --population )
			{
				the_victim = ( the_victim + m - 1 ) % population;
				if( !the_victim )
				{
					the_victim = population;
				}

				if( the_victim <= k )
				{
					break;
				}
			}

			if( population == k )
			{
				printf( "%d\n", m );
				break;
			}
			else
			{
				if( !( m % ( 2 * k ) ) )
				{
					m += k + 1;
				}
				else
				{
					++m;
				}
			}
		}//for()
	}//while()
	return 0;
}
