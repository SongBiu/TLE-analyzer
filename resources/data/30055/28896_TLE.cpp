// _Z3dfsiiii
#include<iostream>
#include<cstdlib>

using namespace std;

const int MAXROAD = 10010;
int k, n, r, Min = -1, b[MAXROAD] = {};

struct Road{
	int destination, length, toll;
};

int com(const void * fc1, const void * fc2){
	Road *r1 = (Road *)fc1, *r2 = (Road *)fc2;
	return r1->destination - r2->destination;
}

class City{
	Road R[MAXROAD];
public:
	int num;
	City():num(0){}
	~City(){}
	void sort(){
		qsort(R, num, sizeof(Road), com);
	}
	friend istream & operator>>(istream &is, City &a){
		is >> a.R[a.num].destination >> a.R[a.num].length >> a.R[a.num].toll;
		a.num++;
		return is;
	}
	Road &operator[](int i){
		return R[i];
	}
}*p;

void dfs(int place, int len, int coins, int num){
	int i;
	if(place == n){
		if(Min == -1 || len < Min)
			Min = len;
		return;
	}
	if(len >= Min && Min != -1)
		return;
	for(i = 1; i < b[0]; ++i){
		if(b[i] == place){
			return;
		}
	}
	for(int i = 0; i < p[place - 1].num; ++i){
		if(p[place - 1][i].toll <= coins){
			b[0]++;
			b[num] = place;
			dfs(p[place - 1][i].destination, len + p[place - 1][i].length, coins - p[place - 1][i].toll, num + 1);
			b[0]--;
		}
	}
}

int main(){
	int Number;
	cin >> k >> n >> r;
	p = new City[n];
	for(int i = 0; i < r; ++i){
		cin >> Number;
		cin >> p[Number - 1];
	}
	//for(int i = 0; i < n; ++i){
		//p[i].sort();
//	}
	b[0] = 1;
	dfs(1, 0, k, 1);
	cout << Min << endl;
	return 0;
}