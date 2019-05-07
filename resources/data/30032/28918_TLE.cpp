// _Z9Goforwardiiii
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#define MAXLEN 10000000
using namespace std;
struct Road {
	int beg, end, len, toll;
};
Road roads[10001];
int K, N, R, minlen, cost;
bool operator < (const Road &p1, const Road & p2){
	if (p1.beg == p2.beg)
		return p1.end < p2.end;
	else return p1.beg < p2.beg;
}
int used[10001];
void Goforward(int sou, int des, int tocost, int tolen) {
	int i;
	if (des == N) {
		if (tolen < minlen && tocost <= K)
			minlen = tolen;
		return;
	}
	if (tocost > K || tolen >= minlen)
		return;
	for (i = 0; i < R; ++i) {
		if (roads[i].end == des)
			continue;
		if (roads[i].beg == des && used[i] == 0) {
			used[i] = 1;
			Goforward(des, roads[i].end, tocost + roads[i].toll, tolen + roads[i].len);
			used[i] = 0;
		}
	}
}
int main() {
	int i;
	scanf("%d %d %d", &K, &N, &R);
	for (i = 0; i < R; ++i)
		scanf("%d %d %d %d", &roads[i].beg, &roads[i].end, &roads[i].len, &roads[i].toll);
	sort(roads, roads + R);
	minlen = MAXLEN;
	cost = 0;
	memset(used, 0, sizeof(used));
	for (i = 0; ; ++i) {
		if (roads[i].beg != 1)
			break;
		used[i] = 1;
		Goforward(1, roads[i].end, roads[i].toll, roads[i].len);
		used[i] = 0;
	}
	if (minlen != MAXLEN)
		printf("%d\n", minlen);
	else
		printf("-1\n");
	return 0;
}