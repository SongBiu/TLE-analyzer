#include <iostream>

using namespace std;

bool Check(int m, int start, int k, int n){
	if(n == k)
		return true;
	int end = ((m % n) + start - 1 + n) % n;
//	cout << m << start << k << n << end << endl;
	if(end >= k){
		if(end == n - 1)
			start = 0;
		else
			start = end;
		return Check(m, start, k, n - 1);
	}
	else
		return false;
}

int Process(int k){
	int cnt = 1;
	while(1){
		int result = (k + 1) * cnt;
		if(Check(result, 0, k, 2 * k))
			return result;
		result = (k + 1) * cnt + 1;
		if(Check(result, 0, k, 2 * k))
			return result;
		cnt++;
	}
}

int main(){
	int k, m;
	while(true){
		cin >> k;
		if(k == 0)
			break;
		//Check(30, 0, 4, 8);
		cout << Process(k) << endl;
	}
	return 0;
}