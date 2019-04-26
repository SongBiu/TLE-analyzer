#include <iostream>
using namespace std;

int main() {
	int k;
	while(cin>>k) {
		if(k == 0) break;
		int n = k * 2;
		for(int s = k + 1; ; ++s) {
			if(s % n <= k && s % n >= 1) continue;
			int bad = k;
			int pos = 0;
			int success = true;
			for(;;) {
				int out = (pos + s - 1) % (bad + k);
				if(out < k) { success = false; break; }
				--bad;
				if(bad == 0) break;
				pos = out;
			}
			if(success) { cout<<s<<endl; break; }
		}
	}
}
