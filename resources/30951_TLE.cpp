#include<iostream>
#include<cstring>
using namespace std;
const int M=300;
int main()
{bool f[M];
int m,n,c,t=0,i;
cin>>n>>m;
while(m||n)
{memset(f,1,M);
for(i=0,c=0;c<n-1;i++)
{if(f[i%n])t++;
if(t==m){f[i%n]=0;
t=0;c++;}}
for(i=0;i<n;i++)
{if(f[i])
{cout<<i+1<<endl;break;}}
cin>>n>>m;}
return 0;}
