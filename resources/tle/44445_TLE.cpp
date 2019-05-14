// _Z4findi res_len
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAXN 105//number of city
#define MAXR 10005//number of road
#define MAXL 105 //road length
#define MAXK 10005 //coin
struct road{
    int des;
    int len;
    int cost;
};
int minlen[MAXN][MAXK]; //minlen[n][k]表示走到城市n路费为k时的最短路径
vector<vector<road>> city_map(MAXN);
bool visit[MAXN];
int current_cost = 0;
int current_len = 0;
int res_len = -1;
int N;
int K;
void find(int s)
{
    //从城市s向N走
    if (s == N) {
        if (res_len == -1) {//得到的第一个可行解
            res_len = current_len;
        }
        else
            res_len = min(res_len, current_len);
    }
    else{
        int des_num = (int)city_map[s].size();
        for (int i = 0; i < des_num; i++) {
            if (visit[city_map[s][i].des] == true) {
                continue;
            }
            
            current_len += city_map[s][i].len;
            current_cost += city_map[s][i].cost;
            if (current_cost > K) {//out of coins
                current_len -= city_map[s][i].len;
                current_cost -= city_map[s][i].cost;
                continue;
            }
            if (minlen[city_map[s][i].des][current_cost] == 0) {
                minlen[city_map[s][i].des][current_cost] = current_len;
            }
            else{
                if (minlen[city_map[s][i].des][current_cost] < current_len) {
                    current_len -= city_map[s][i].len;
                    current_cost -= city_map[s][i].cost;
                    continue;
                }
                else
                    minlen[city_map[s][i].des][current_cost] = min(minlen[city_map[s][i].des][current_cost], current_len);//update
            }
            visit[city_map[s][i].des] = true;
            find(city_map[s][i].des);
            //回溯
            visit[city_map[s][i].des] = false;
            current_len -= city_map[s][i].len;
            current_cost -= city_map[s][i].cost;
        }
    }
    
}
int main()
{
    int r;
    cin>>K>>N>>r;
    memset(minlen, 0, sizeof(int) * MAXN * MAXK);
    memset(visit, 0, sizeof(bool) * MAXN);
    for (int i = 0; i < r; i++) {
        int src;
        road tmp;
        cin>>src>>tmp.des>>tmp.len>>tmp.cost;
        city_map[src].push_back(tmp); //add to city map
    }
    
    find(1);
    cout<<res_len<<endl;
    return 0;
    
    
}