#include<iostream>
using namespace std;
int main()                                                       //主体程序，利用此程序得到1——13对应的结果，打表
{
int k,M[14];
M[0]=0;

while(cin>>k&&k!=0)
{
      bool flag=false;
      int m=k-1;
      while(!flag){
       flag=true;
       m++;
          for(int i=0;i<k;i++)
          {
        M[i+1]=(M[i]+m-1)%(2*k-i);
           if(M[i+1]<k) flag=false;
           if(!flag) break;
           else flag=true;
           }
      }
      cout<<m<<endl;
}
return 0;
}