#include<iostream>

using namespace std;

int main()
{
    int k,good,bad,temp;
    while(cin>>k&&k)
    {
        for(int i=1;;i++)
        {
            good=bad=k;
            temp=i;
            for(int m=2*k;good==k;temp+=i,m--)
            {
                temp%=m;
                if(!temp) temp=m;
                if(temp>k) bad--;
                else good--;
                temp--;
            }
            if(!bad)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
