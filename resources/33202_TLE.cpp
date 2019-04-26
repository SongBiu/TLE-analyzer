#include<iostream>
using namespace std;
int main()
{
    int k;
    while(cin>>k&&k){
    for(int m=k;;m++){
            bool q=0;
            int c=0,s=0;
            bool a[30]={0};
            int t=-1;
            for(int j=1;;j++){
                for(int i=t+1;;i++){
                t=i%(2*k);
                if(a[t]==0)c++;
                if(c==m){
                    s++;
                    a[t]=1;
                    c=0;
                    if(t<k){q=1;}
                    break;
                    }
                }
                if(q==1)break;
                if(s==k){q=0;break;}
            }
            if(q==0){cout<<m<<'\n';break;}
        }
    }
}