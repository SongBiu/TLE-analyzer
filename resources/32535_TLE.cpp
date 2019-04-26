#include<iostream>

using namespace std;


int main(){
	int k;
	while(cin >> k){
		if(!k)
			break;
		
		int kill[30] = {0};
		int m = k;

		for(int j = 1; j <= k; j ++){
			kill[j] = (kill[j - 1] + m - 1) % (2 * k - j + 1);
			if(kill[j] < k){
				j = 0;
				m ++;
			}
		} 
		cout << m << endl;
	}//done
	return 0;
}