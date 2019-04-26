#include<iostream>
using namespace std;
int main(){
	int k;
	while(cin >> k && k != 0){
		for (int m = k+1;; m++){
			int index = 0;
			int total = 2 * k;
			while(total > k){
				index = (index+m-1)%total;
				if (index < k) break;
				total--;
			}
			if (total == k){
				cout << m << endl;
				break;
			}		
		}
	}
	return 0;
} 