// _Z4Passi
#include<iostream>
#include<cstdio>
using namespace std;

int K = 0, N = 0, R = 0;
int D[101][10000] = {0}, L[101][10000] = {0}, T[101][10000] = {0};
int Idx[101] = {0};
bool City[101] = {0};
int Shortest = 10001;

int Coins = 0, Total = 0;

void Pass(int Current)
{
	if (Current == N)
	{
		if (Shortest > Total) Shortest = Total;
		return;
	}

	City[Current] = true;
	for (int r = 0; r < Idx[Current]; ++r)
	{
		if (City[D[Current][r]] || Coins < T[Current][r]) continue;
//		if (Total + L[Current][r] > Shortest) continue;

		Coins -= T[Current][r], Total += L[Current][r];
		Pass(D[Current][r]);
		Coins += T[Current][r], Total -= L[Current][r];
	}
	City[Current] = false;
}
int main()
{
	scanf("%d%d%d",&K,&N,&R);
	Coins = K;
	int s = 0;
	for (int i = 0; i < R; ++i)
	{
scanf("%d",&s);
scanf("%d%d%d",&D[s][Idx[s]],&L[s][Idx[s]],&T[s][Idx[s]]);
		++Idx[s];
	}

	Pass(1);
	if (Shortest > 10000) cout << -1;
	else cout << Shortest;
	return 0;
}