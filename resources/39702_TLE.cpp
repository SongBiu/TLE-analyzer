#include<stdio.h>
#include<string.h>

int vis[30];
int k,m;
bool flag;

int main()
{
    while(scanf("%d",&k)==1&&k)
    {
        flag=false;
        m=k;
        while(!flag)
        {
            int cur=m%(2*k);
            int cnt=m+1;
            int ok=1;
            memset(vis,0,sizeof(vis));
            for(int i=0;i<k;i++)
            {
                vis[cur]=1;
                if(cur<=k-1) {ok=0;break;}
                while(cnt)
                {
                    cur=(cur+1)%(2*k);
                    if(!vis[cur]) cnt--;
                }
                cnt=m+1;
            }
            if(ok) flag=true;
            else m++;
        }
        printf("%d\n",m+1);
    }
    return 0;
}
