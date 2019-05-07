#include<stdio.h> 

int K,N,R;
struct s
{
    int S,D,L,T;
}ss[110][10000]; //300 
int l[110]={0};

bool mark[110]={0};
int min=999999999;

void Find(int place,int L,int T)
{
    /*
    if (L>=min)
        return;
    if (T>K)
        return;  */
    if (place==N)
    {
        if (T<=K&&L<min)
            min=L;
        return;
    }
    for (int i=0;i<l[place];i++)
    {
        if (mark[ss[place][i].D]==1)
            continue;
        if (L+ss[place][i].L >= min)
            continue;
        if (T+ss[place][i].T > K)
            continue;
        mark[ss[place][i].D]=1;
        L+=ss[place][i].L;
        T+=ss[place][i].T;
        Find(ss[place][i].D,L,T);
        mark[ss[place][i].D]=0;
        L-=ss[place][i].L;
        T-=ss[place][i].T;
    }
}

int main ()
{
    scanf("%d%d%d",&K,&N,&R);
    for (int i=0;i<R;i++)
    {
        s temp;
        scanf("%d%d%d%d",&temp.S,&temp.D,&temp.L,&temp.T);
        ss[temp.S][l[temp.S]]=temp;
        l[temp.S]++;
    }
    mark[1]=1;
    Find(1,0,0);
    if (min==999999999)
        min=-1;
    printf("%d\n",min);
    return 0;
}