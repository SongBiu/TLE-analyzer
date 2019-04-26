#include <cstdio>
#include <cstring>

int j[30];
int ans[30];
bool judge(int m,int k){
	ans[0] = 0;
	for(int i=1;i<=k;i++){
		ans[i] = (ans[i - 1] + m - 1) % (2 * k - i + 1);
		if(ans[i] < k)
			return false;
	}
	return true;
}
int main(){
	memset(j,0,sizeof(j));
	int k,m;
	while(scanf("%d",&k) && k){
		if(j[k])
			printf("%d\n",j[k]);
		m = k + 1;
		while(1){
			if(judge(m,k))
				break;
			m++;
		}
		j[k] = m;
		printf("%d\n",j[k]);
	}
}