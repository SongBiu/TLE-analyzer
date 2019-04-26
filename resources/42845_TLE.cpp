//
//  main.cpp
//  joseph
//
//  Created by 燕欣雨 on 2017/6/21.
//  Copyright © 2017年 燕欣雨. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

bool fun(int k, int m){
    list<int> lst;
    for (int i = 1; i <= 2*k;i++)
        lst.push_back(i);
    list<int>::iterator it = lst.begin();
    while (lst.size() > k) {
        for (int i = 1; i < m; i++){
            ++it;
            if (it == lst.end()) it = lst.begin();
        }
        if (*it <= k) return false;
        it = lst.erase(it);
        if (it == lst.end()) it = lst.begin();
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int k,m;
    while (cin >> k){
        if (k == 0) break;
        bool flag = 1;
        for (int i = 0;flag; i++){
            for (m = k+1; m<=2*k;m++){
                if (fun(k,m + i * 2*k)){
                    cout << m +2 * i * k << endl;
                    flag = 0;
                    break;
                }
            }
        }
        
    }
    return 0;
}
