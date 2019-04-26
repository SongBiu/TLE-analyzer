#include<stdio.h>
int find(int n)
{
int now,next,a[1000],p,x,b[1000],k,m,i,j,flag=1;
for(m=1;;m++)
{
flag=1;
now=-1;
x=0;
for(p=0;p<n;p++)
{
a[p]=p+1;
}


do
{

next=(now+m)%(n-x);
b[x]=a[next];

if(x<n/2)
{
for(j=1;j<=n/2;j++)
{if(b[x]==j)
{flag=0;break;}
}
if(flag==0)
{break;}
}
for(k=next;k<n-1-x;k++)
{
a[k]=a[k+1];

}
x++;
now=next-1;
if(flag==0)
{break;}
}while(x<n/2);


if(flag==1)
{
break;}
}
return m;
}






int main()
{
int n,m,c;
while(scanf("%d",&n)!=EOF&&n>0&&n<14)
{
m=2*n;
c=find(m);


printf("%d\n",c);


}return 0;
}