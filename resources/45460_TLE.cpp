#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 14
int jo[SIZE * 2];

int main()
{
	int k, m;
	while ((cin>>k)&&(k>0&&k<SIZE))
	{
		memset(jo, 1, sizeof(jo));
		m = k + 1;
		while (true)
		{
			int pivot = 1;
			int i = 1;
			int die = 0;
			int finish = 0;
			while (true)
			{
				if (die == k)
					break;
				while (jo[pivot] == 0)
				{
					pivot++;
					if (pivot > 2 * k)
						pivot = 1;
				}
				if (i == m)
				{
					if (pivot >= 1 && pivot <= k)
						break;
					else
					{
						jo[pivot] = 0;
						die++;
					}
				}
				i++;
				pivot++;
				if (pivot > 2 * k)
					pivot = 1;
				if (i > m)
					i = 1;
			}
			if (die == k)
				break;
			memset(jo, 1, sizeof(jo));
			m++;
		}
		printf("%d\n", m);
	}
}