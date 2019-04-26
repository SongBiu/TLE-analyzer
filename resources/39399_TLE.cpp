#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;
//------------------------------------------------------------
#define LL long long
//#define LL __int64
#define clr_all(a,b) memset(a,b,sizeof(a))
#define clr(a,b,n) memset(a,b,sizeof(a[0])*(n))
template<typename T> T Max(T a, T b){ return a > b ? a : b; }
template<typename T> T Min(T a, T b){ return a < b ? a : b; }
#define P1 puts("1111111111111111111")
#define P2 puts("2222222222222222222")
#define P3 puts("3333333333333333333")
#define Pi printf("i=%d\n",i)
#define Pj printf("j=%d\n",j)
const int MAXN = 30 + 10;
const int MAXM = 10000 + 10;
const int INF = 0x7FFFFFFF;
const int mod = 1e6 + 3;
const double eps = 1e-12;
//------------------------------------------------------------

bool flag[MAXN];
bool cal(int n, int m){
	int a, b;
	a = b = n;
	clr_all(flag, false);
	int tmp = 0;
	int len = n * 2;
	for (int i = 0; i < n; i++){
		tmp = (tmp + m - 1) % len;
		len--;
		if (tmp < n)
			return false;
	}
	return true;
}
int main(){
	int N, M;
	while (~scanf("%d", &N), N){
		for (int i = N + 1;;){
			if (cal(N, i)){
				printf("%d\n", i);
				break;
			}
			if (i % (2 * N) == 0)
				i += N;
			else
				i++;
		}
	}
	return 0;
}