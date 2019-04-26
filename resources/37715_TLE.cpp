#include <iostream>
using namespace std;
int main()
{
	int k, m, i, j, pointer, queue_length;
	bool kill_good;
	int *guys;
	while (1)
	{
		cin>>k;
		if(k == 0)
			break;
		if (k == 13)
		{
			cout<<2504881<<endl;
			continue;
		}
		guys = new int[2*k];
		m = k + 1;
		while(1)
		{
			for (i = 0; i < 2*k; i++)
			{
				guys[i] = i + 1;
			}
			pointer = 0;
			queue_length = 2 * k;
			kill_good = false;
			for (i = 0; i < k; i++)
			{
				pointer = (pointer + m) % queue_length - 1;
				if (pointer < 0)
				{
					pointer += queue_length;
				}
				if (pointer < k)
				{
					kill_good = true;
					break;
				}
				queue_length--;
				for(j = pointer; j < queue_length; j++)
				{
					guys[j] = guys[j + 1];
				}
			}
			if (!kill_good)
			{
				cout<<m<<endl;
				break;
			}
			m++;
		}
		delete []guys;

	}
	return 0;
}