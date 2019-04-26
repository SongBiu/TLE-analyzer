#include <iostream>
using namespace std;

bool DFS(int pos,int min,int count,int n,int size)
{
    int temp;
    while(true)
    {
    if(count==n)
    {
        return true;
    }
    pos=pos+min;
    temp=pos%size;
    if(temp==0)
    {
        temp=size;
    }
    if(temp<=n)   //若去掉的是好人，出错返回
    {
        return false;
    }

    temp=temp-1;
    size=size-1;    //把坏人去掉一个，具体去掉哪一个不用在意
    pos=temp;
    count++;  //
    }
}

int main(int argc, char *argv[])
{
    int n;
    int number=0;
    int a[13];
    while(scanf("%d",&n)!=EOF)
    {
        number++;

        if(n==0||n>13)
        {
            break;
        }


        if(number==14)
        {
            break;
        }
        a[number]=n;
     }
    int jj;
    for(jj=1;jj<number;jj++)
    {
        n=a[jj];
        int min=n;

        while (true)
        {
            min++;
            if((min%(2*n))>n||min%(2*n)==0)
            {
                if(DFS(0,min,0,n,2*n))
                {
                    cout<<min<<endl;
                    break;
                }
            }

        }

    }
    return 0;
}
