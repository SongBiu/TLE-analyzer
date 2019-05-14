// _Z3Tryiii lenth
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

int lenth = -1;

struct A
{
	int a[3];
	A(int s, int l, int t)
	{
		a[0] = s;
		a[1] = l;
		a[2] = t;
	}
};

struct City
{
	vector<A> city;
	int count;
	City() {count = 0;}
	void addroad(int s, int l, int t)
	{
		city.push_back(A(s, l, t));
		count++;
	}
}city[101];

int visit[101] = {0};
void Try(int T, int L, int n)
{
	if (T < 0)
		return;
	if (visit[n] == true)
		return;
	if (T >= 0 && n == 1)
	{
		if (lenth == -1 || L < lenth)
			lenth = L;
		return;
	}
	for (int i = 0; i < city[n].count; i++)
	{
		visit[n] = true;
		Try(T - city[n].city[i].a[2], L + city[n].city[i].a[1], city[n].city[i].a[0]);
		visit[n]  =false;
	}
	return;
}

int main()
{
	int K, N, R;
	scanf("%d\n%d\n%d", &K, &N, &R);
	int i;
	int s, d, l, t;
	for (i = 1; i <= R; i++)
	{
		scanf("%d %d %d %d", &s, &d, &l, &t);
		city[d].addroad(s, l, t);
	}
	Try(K, 0, N);
	if (lenth != -1)
		printf("%d\n", lenth);
	else
		printf("-1\n");
	return 0; 
}