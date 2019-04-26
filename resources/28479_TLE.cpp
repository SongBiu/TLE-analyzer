#include <iostream>
using namespace std;

int main()
{
    int k,n,m;
    int a[30];
    while(cin>>k)
    {
        if(!k) break;
        n=2*k;
        int s=n;
        int start=0;
        int b=1;
        for(m=k+1;;b?m++:m+=k,b=!b)
        {
            if(m%(k+1)!=1&&m%(k+1)!=0) continue;
            while(s>k)
            {
                start=(start+m-1)%s;
                if(start<k)
                {
                    start=0;
                    s=n;
                    break;
                }
                else
                {
                    s--;
                }
            }
            if(s==k) break;
        }

        cout<<m<<endl;
    }
    return 0;
}
