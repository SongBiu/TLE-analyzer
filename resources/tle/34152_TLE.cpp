// _Z1fi minL
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Road {
    int d, des, cost;
    
};
vector<vector<Road> > cities(110);
int money, cityNum, roadNum;
int minL = 1<<30;  // 当前找到最优路径的长度
int currentL = 0;  // 当前走的路径长度
int currentCost = 0;  // 当前走的路径花销
bool visited[110] = { false };  // 城市是否走过
struct City{
    int money, length;
};
City faster[110];
void f(int s) {
    // 终止条件（走到终点）
    if (s == cityNum) {
        minL = min(minL, currentL);
        return;
    }
    
    for (vector<Road>::iterator it = cities[s].begin(); it != cities[s].end(); ++it) {
        Road rd = *it;
        int des = rd.des;
        if (visited[des]) continue;
        int cost = currentCost + rd.cost;
        if (cost > money) continue;
        if (currentL + rd.d >= minL ||
            (currentL + rd.d >= faster[des].length && cost >= faster[des].money)) continue;
        currentL += rd.d;
        currentCost = cost;
        if (currentL <= faster[des].length && currentCost <= faster[des].money) {
            faster[des].money = currentCost;
            faster[des].length = currentL;
        }
        visited[des] = 1;
        f(des);
        visited[des] = 0;
        currentL -= rd.d;
        currentCost -= rd.cost;
    }
}

int main() {
    cin >> money >> cityNum >> roadNum;
    for (int i = 0; i < roadNum; ++i) {
        int tmp;
        Road rd;
        cin >> tmp >> rd.des >> rd.d >> rd.cost;
        if (rd.des == tmp) continue;
        cities[tmp].push_back(rd);
    }
    for (int i = 0; i < 110; ++i) {
        faster[i].money = faster[i].length = 1<<30;
    }
    visited[1] = 1;
    f(1);
    if (minL < (1<<30)) cout << minL;
    else cout << -1;
    return 0;
}