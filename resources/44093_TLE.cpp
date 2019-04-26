#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool isResult(int m,int*data,int n,int k){
	int cur = n;
	int re = (m - 1) % n + 1;
	while(cur > 0){
		if(re <= k){
			for(int i=k+1;i<=n;i++){
				if(data[i] != -1){
					return false;
				}
			}
			return true;
		}
		data[re] = -1;
		cur--;
		int step,feak;
		for(step = 1,feak = 1;feak < m;){
			if(data[(re + step - 1) % n + 1] == -1){
				step++;
			}
			else{
				feak++;
				step++;
			}
		}
		re = (re + step - 1) % n + 1;
		while(data[re] == -1){
			re = re % n + 1;
		}
	}
	return false;
}



int main(){
	int k;
	while(cin>>k && k != 0){
		int n = 2 * k;
		int m = k + 1;
		int*data = new int[n + 1];
		for(m = k + 1;;m++){
			memset(data + k + 1,0,sizeof(int) * k);
			if(isResult(m,data, n,k)){
				break;
			}
		}
		cout<<m<<endl;
	}

}