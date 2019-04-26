#include <stdio.h>
#include<iostream>
using namespace std;
int test(int k,int m)
{
    int i,j=0,n=k<<1;
    for(i=0;i<k;i++)
    {
        j=(j+m-1)%(n-i);//下一个要杀的人 
        if(j<k) return 0;  
    }
    return 1;          
}

int main()
{
    int i,j,k;
    int x[13];
    while(1)
    {
        cin>>k;
        if(k==0) break;
        i=k+1;
        while(1)
        {
            if(test(k,i)) 
            {
                x[k-1]=i;
                break;
            }
            if(test(k,i+1))
            {
                x[k-1]=i+1;
                break;
            }
            i+=(k+1);
        }
        cout<<x[k-1]<<endl;
    }
        
   // system("PAUSE");
    return 0;
}
