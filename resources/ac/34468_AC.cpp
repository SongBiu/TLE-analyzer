// _Z3dfsi minlength
//
//  main.cpp
//  6.13. practice 寻路问题
//
//  Created by 张峻伟 on 15/6/13.
//  Copyright (c) 2015年 张峻伟. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int K, N, R;
int dist=0, money=0;
int minlength=1<<30; 
bool cover[102]={};
int minl[102][10110]={};

struct ROAD
{
    int to;
    int length;
    int fee;
};

vector<vector<ROAD> > city(110);

void dfs( int x )
{
    if( x==N && dist<minlength ){
        minlength=dist;
        return;
    }
    int num=(int)city[x].size();
    for( int i=0;i<num;i++ ){
        int t=city[x][i].to;
        if( cover[t] ) continue;
        if( money+city[x][i].fee>K ) continue;
        if( dist+city[x][i].length>minlength ) continue;
        if( dist+city[x][i].length>minl[t][money+city[x][i].fee] ) continue;
        minl[t][money+city[x][i].fee]=dist+city[x][i].length;
        cover[t]=1;
        dist+=city[x][i].length;
        money+=city[x][i].fee;
        dfs(t);
        money-=city[x][i].fee;
        dist-=city[x][i].length;
        cover[t]=0;
    }
}

int main()
{
    cin>>K>>N>>R;
    for( int i=0;i<R;i++ ){
        int temp;
        cin>>temp;
        ROAD road;
        cin>>road.to>>road.length>>road.fee;
        city[temp].push_back(road);
    }
    for( int i=0;i<102;i++ ) 
        for( int j=0;j<10110;j++ ) 
            minl[i][j]=1<<30;
    dfs(1);
    if( minlength<(1<<30) ) cout<<minlength<<endl;
    else cout<<-1<<endl;
}
    
