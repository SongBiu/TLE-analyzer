// _Z3dfsiii
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int SZ=101;
int K, N, R;
int rt;
bool visited[SZ];

struct node
{
    int ed;
    int l;
    int t;
    node* next;
};
node g[SZ];
node sp[SZ*SZ];
int cnt;

void dfs(int st, int m, int len)
{
    for(node* p=g[st].next; p!=NULL; p=p->next)
    {
        if(!visited[p->ed] && m+p->t<=K && (len+p->l<rt || rt==-1))
        {
            if(p->ed==N)
            {
                rt=len+p->l;
                continue;
            }
            visited[p->ed]=1;
            dfs(p->ed, m+p->t, len+p->l);
            visited[p->ed]=0;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d%d%d", &K, &N, &R);
    for(int i=1; i<=N; i++) g[i].next=NULL;
    cnt=0;
    for(int i=1; i<=R; i++)
    {
        int s, d, l, t;
        scanf("%d%d%d%d", &s, &d, &l, &t);
        node* p=&sp[cnt++];
        p->ed=d; p->l=l; p->t=t;
        p->next=g[s].next;
        g[s].next=p;
    }
    rt=-1;
    memset(visited, 0, sizeof(visited));
    visited[1]=1;
    dfs(1, 0, 0);
    printf("%d\n", rt);
    return 0;
}
