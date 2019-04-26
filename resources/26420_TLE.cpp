#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int number;
int circle[30];
bool check(int people)
{
	int index,size = people,left = 0;
	while(size > people/2)
	{
		int index = (number-left)%size-1;
		if(index == -1)
			index = size -1;
		if(circle[index] <= people/2)
		{
			return false;
			
		}
		else
		{
			for(int i = index; i < size - 1; i++)
			{
				circle[i] = circle[i+1];
			}
			size--;
			left = size - index;
		}
	}
	return true;
}

int main()
{
	int people;
	while(true){
		scanf("%d",&people);
		if(people == 0)
			break;
		number = people + 1;
		people *= 2;
		
		while(true){
			for(int i = 0; i < people; i++)
			{
				circle[i] = i+1;
			}
			if(check(people))
			{
				break;
			}
			else
				number++;
		}
		printf("%d\n",number);
	}
	return 0;
}