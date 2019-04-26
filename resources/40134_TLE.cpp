#include<iostream>

using namespace std;

int main(){
	int k;
	int Joseph[14] = {0};
	while(cin>>k){
		if(!k)
			break;
		if(Joseph[k]){
			cout<<Joseph[k]<<endl;
			continue;
		}
		int n = k*2;
		int ans[30] = {0};
		int m = 1;
		for(int i = 1; i<=n; i++){
			ans[i] = (ans[i-1]+m-1)%(n-i+1);
			if(ans[i]<k){
				i = 0;
				m++;
			}
		}
		cout<<m<<endl;
		Joseph[k] = m;
	}
	return 0;
}