// _Z4walkiii minLen
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
#define MAX_CITY 103
#define MAX_AFFORD 10002

class Road {
public:
	int d, l, t;
};

vector<vector<Road> > Roads(MAX_CITY);
int mid[MAX_CITY][MAX_AFFORD] = {0};
int K, N, R, minLen;
bool visited[MAX_CITY] = {false};

void walk(int now, int spendMoney, int nowLen) {
	if (now == N) {
		minLen = minLen < nowLen ? minLen : nowLen;
		return;
	}
	for(int i = 0; i < Roads[now].size(); i++) {
		int next = Roads[now][i].d;
		if (!visited[next])  {
			int spend = spendMoney + Roads[now][i].t;
			if (spend > K)
				continue;
			int length = nowLen + Roads[now][i].l;
			if (length >= minLen || length >= mid[next][spend])
				continue;
			visited[next] = true;
			walk(next, spend, length);
			visited[next] = false;
		}
	}
}

int main() {
	int s;
	scanf("%d %d %d", &K, &N, &R);
	while(R--) {
		Road r;
		scanf("%d %d %d %d", &s, &r.d, &r.l, &r.t);
		if(s == r.d)
			continue;
		Roads[s].push_back(r);
	}
	for(int i = 0; i < MAX_CITY; i++)
		for (int j = 0; j < MAX_AFFORD; j++)
			mid[i][j] = INT_MAX;
	minLen = INT_MAX;
	visited[1] = true;
	walk(1, 0, 0);
	printf("%d\n", minLen == INT_MAX ? -1 : minLen);
	return 0;
}