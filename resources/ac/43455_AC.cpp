// _Z2dpi minLen
#include <iostream>
#include <vector>
using namespace std;
struct road{
    int dest,len,toll;
};
int minL[102][10002];
bool visited[102];
int minLen=1<<30,totalMoney,totalLen,n,k;
vector<road> city[102];
void dp(int x){
    if(x==n){
        minLen=min(minLen,totalLen);
        return;
    }
    for(vector<road>::iterator i=city[x].begin();i!=city[x].end();i++){
        if(!visited[i->dest]){
            int tmpMoney=totalMoney+i->toll;
            int tmpLen=totalLen+i->len;
            if(tmpMoney>k||tmpLen>=minLen||tmpLen>=minL[i->dest][tmpMoney]) continue;
            totalMoney+=i->toll;
            totalLen+=i->len;
            visited[i->dest]=true;
            minL[i->dest][tmpMoney]=totalLen;
            dp(i->dest);
            totalMoney-=i->toll;
            totalLen-=i->len;
            visited[i->dest]=false;
        }
    }

}
int main(){
    int r,i,j,tmp;
    cin>>k>>n>>r;
    for(i=0;i<r;i++){
        road r_tmp;
        cin>>tmp;
        cin>>r_tmp.dest>>r_tmp.len>>r_tmp.toll;
        if(r_tmp.dest!=tmp) city[tmp].push_back(r_tmp);
    }
    for(i=0;i<102;i++){
        for(j=0;j<10002;j++){
            minL[i][j]=1<<30;
        }
    }
    dp(1);
    if(minLen==1<<30){
        cout<<"-1";
    }else{
        cout<<minLen;
    }
    return 0;
}
