#include <cstdio>
#include <cstring>
bool check(int k, int m){
	int total = k + k, current = -1;
	int kill = 0;
	for (int i = 0; i < k; i ++){
		current = current + m;
		if (current >= total){
			current -= total;
			total -= kill;
			kill = 0;
		}
		current %= total;
		if (current < k){
			return false;
		}
		kill ++;
	}
	return true;
}
int main(){
	int n;
	while (scanf("%d", &n), n){
		int i = 1;
		while (!check(n, i))
			i ++;
		printf("%d\n", i);
	}
	return 0;
}
