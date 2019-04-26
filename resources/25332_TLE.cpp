#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int k;
deque<int> joseph(1);
deque<int> circle;
int main()
{
	while (scanf("%d",&k) == 1){
		int i,j;
		circle.clear();
		joseph.clear();
		joseph.push_back(0);
		for (i = 1; i <= 2*k; i++)
			joseph.push_back(i);
		int l = 0;
		bool findflag = false;
		int m;
		int cnt;
		int pointer;
		while (!findflag){
			for (j = k+1; j <= 2*k; j++){
				m = j + 2*l*k;
				pointer = m%(joseph.size()-1);
				circle.clear();
				circle = joseph;
				cnt = k;
				while (cnt != 0){
					if (circle[pointer] > k)
					{
						circle.erase(circle.begin()+pointer);
						cnt--;
						pointer = (pointer+m-1)%(circle.size()-1);
						if (pointer == 0) pointer = circle.size()-1;
					}
					else{
						break;
					}
				}
				if (cnt == 0){
					findflag = true;
					break;
				}
			}
			l++;
		}
		printf("%d\n",m);
	}
	return 0;
}

