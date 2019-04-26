#include <stdio.h>
#include <memory.h>
int main() {
	int k;
	int stack[13];
	int ans[14];
	int stack_size;
	memset(stack,0,sizeof(stack));
	memset(ans,0,sizeof(ans));
	while(true) {
		scanf("%d",&k);
		if(!k) return 0;
		if(ans[k]) {
			printf("%d\n",ans[k]);
			continue;
		}
		int n=2*k;
		for(int m=k+1;;++m) {
			stack_size=0;
			for(int i=1;i<=n;++i) {
				for(int j=0;j<stack_size;++j) stack[j]=(stack[j]+m)%i;
				if(stack_size<k) stack[stack_size++]=(m-1)%i;
			}
			bool ResultFound=true;
			for(int i=0;i<stack_size;++i) {
				if(stack[i]>=k) {
					ResultFound=false;
					break;
				}
			}
			if(ResultFound) {
				ans[k]=m;
				printf("%d\n",m);
				break;
			}
		}
	}
}