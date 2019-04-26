#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int m;
vector<int> ori_c;
vector<int> c;
int k;

vector<int>::iterator getIndex(vector<int>::iterator it)
{
    if(it == c.end())
        return c.begin();
    return it;
}

int main()
{
    while(scanf("%d", &k) != EOF)
    {
        if(k==0)
            break;

        ori_c.clear();

        for(int i = 0; i < k; i++)
        {
            ori_c.push_back(i);
        }
        for(int i = 0; i < k; i++)
        {
            ori_c.push_back(i+k);
        }

        int m = 2;
        while(1)
        {
            c = ori_c;
            int goodCount = 0, badCount = 0;
            int counter;

            bool flag = false;
            vector<int>::iterator it = c.end() - 1;
            vector<int>::iterator ic;

            //cout<<"m = "<<m<<endl;
            while(1)
            {
                for(int i = 0; i < m; i++)
                {
                    ic = it;
                    ++it;
                    it = getIndex(it);
                }

                if(*it < k)
                {
                    goodCount++;
                }
                else
                {
                    badCount++;
                }
                //cout<<"mark: "<<*it<<endl;
                c.erase(it);
                it = ic;

                if(badCount == k && goodCount == 0)
                {
                    cout<<m<<endl;
                    flag = true;
                    break;
                }
                if(goodCount > 0)
                {
                    break;
                }
            }
            if(flag)
                break;

            m++;
        }
    }
}
