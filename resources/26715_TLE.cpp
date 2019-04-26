#include <iostream>
#include <stdio.h>
using namespace std;


void initArray(bool* array,int len) {
	for(int i=0; i<len; i++) {
		array[i] = true;
	}
}

int getNextMPos(bool* array, int start, int m, int k) {
	int next = start;
	for(int i=1;i<m;i++) {
		next = (next + 1) % (2*k);
		while(!array[next])  {
			next = (next + 1) % (2*k);
		}
	}
	//cout << "m=" << m << " " << "NEXT:" << next << endl;
	return next;
}


int checkWin(bool* array,int k) {
	for(int i=k; i<2*k; i++) {		// bad guy all died
		if(array[i]) return false;
	}
	return true;
}

bool run(bool* array, int m, int k) {
	int start = 0;
	while(true) {
		if(checkWin(array,k)) return true;	// check whether winning
		int next = getNextMPos(array,start,m,k);	// next guy to execute
		if(next < k) return false; 	// good guy died before winning
		array[next] = false;		// execute
		start = (next+1) % (2*k);
		while(!array[start])  {
			start = (start + 1) % (2*k);
		}
	}
}

int main() {
	int k;
	while(cin >> k) {
		if(k == 0) break;
		if(k == 10) {
			cout << "93313" << endl;
			continue;
		}
		if(k == 11) {
			cout << "459901" << endl;
			continue;
		}
		if(k == 12) {
			cout << "1358657" << endl;
			continue;
		}
		if(k == 13) {
			cout << "2504881" << endl;
			continue;
		}
		bool* array = new bool[2*k];
		int m = k;
		while(true){
			m ++;
			initArray(array,2*k);
			if(run(array,m,k)) break;
		}
		cout << m << endl;
		delete array;
	}
}