#include <cstdio>

using namespace std;

struct Element {
	int before;
	int next;
	bool life;

};

bool work (int k, int m) {
	Element tmp[31];
	for (int i = 1; i <= 2*k; i++ ) {
		tmp[i].life = true;
		if (i == 1)
			tmp[i].before = 2 * k;
		else
			tmp[i].before = i - 1;
		if (i == 2*k)
			tmp[i].next = 1;
		else
			tmp[i].next = i + 1;
	}
		
	int num = 0;
	int i = 1;
	int kill = 0;
	while(kill <= k) {
		int numnum = m % (2*k - kill);
		if (numnum == 0)	numnum = 2*k - kill;
		if (i > 2 * k)
			i = i % (2*k);
		num ++;
		if (num == numnum) {
			kill ++;
			tmp[i].life = false;
			tmp[tmp[i].before].next = tmp[i].next;
			tmp[tmp[i].next].before = tmp[i].before;
			if (i <= k && kill <= k) 
				return false;
			i = tmp[i].next;
			num = 0;
		}
		else 
			i = tmp[i].next;

	}
	return true;
}

int main() {
	int k;
	int ret[15] = {0};
	while (true) {
		scanf("%d", &k);
		if (k == 0)
			break;
		if (ret[k] != 0) {
			printf("%d\n", ret[k]);
			continue;
		}
		for (int m = 1; ; m++) {
			if (work(k, m)) {
				printf("%d\n", m);
				ret[k] = m;
				break;
			}
		}
	}

	return 0;
}
