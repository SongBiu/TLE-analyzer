// _Z3funiii result
#include<iostream>
#include<memory.h>
#include<stdlib.h>
using namespace std;
int result = 0;
struct Choice
{
	int sourse;
	int destination;
	int length;
	int pay;
};
Choice choice[10000];
int arrived[101];
int  money = 0, R = 0, N = 0;
//int start[101];
/*int Mycompare(const void * a1, const void * b1)
{
	Choice *a, *b;
	a = (Choice *)a1;
	b = (Choice *)b1;
	if(a->destination > b->destination )
		return -1;
	else if(a->destination  < b->destination  )return 1;
	else if(a->sourse  < b->sourse  ) return -1;
	return 1;
}*/
void fun(int dest, int spent, int have_gone)
{
	bool flag = true;
	int temp = 0;
	if(dest == 1)
	{
		if(spent < money && (result > have_gone || result == 0))
			result = have_gone;
	}
	arrived[dest] = 1;
	for(int i = 0; i < R;i++)
	{	
		if(choice[i].destination != dest) continue;
		if(arrived[choice[i].sourse] == 1)  continue;
		if(spent + choice[i].pay > money) continue;
		if(result != 0 && have_gone + choice[i].length > result) continue;
		if(choice[i].sourse == 1)
		{
			temp = have_gone + choice[i].length ;
			result = temp;
			continue;
		}
		fun(choice[i].sourse , spent + choice[i].pay , have_gone + choice[i].length);
	}
	arrived[dest] = 0;
	return;
}

int main()
{
	int i, j;

	memset(arrived, 0, sizeof(arrived));
	cin >> money >> N >> R;

	for(i = 0; i < R; i++)
	{
		cin >> choice[i].sourse ;
		cin >> choice[i].destination >> choice[i].length >> choice[i].pay ;
	}
/*	qsort(choice, R, sizeof(Choice), Mycompare);
	j = N;
	for(i = 0; i < R; i++)
	{
		if(choice[i].destination == j)
		{
			start[j] = i;
			j--;
		}
		else
		{
			if(choice[i].destination  < j)
			{
				j = i;
				start[j] = i;
				j--;
			}
		}
	}*/
	arrived[N] = 1;
	for(i = 0; i < R ; i++)
	{
		if(choice[i].destination  != N) continue;
		fun(choice[i].sourse , choice[i].pay , choice[i].length);
	}
	if(result != 0) 
		cout << result << endl;
	else
		cout << "-1" << endl;
	return 0;
}