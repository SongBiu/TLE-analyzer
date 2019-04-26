#include<iostream>
using namespace std;

bool Joseph(int k, int m) 
{
     int n=0,a=1;
     for(n=1;n<=k;n++)
     {
         a = (a+m-1)%(k*2-n+1);
         if(a == 0) a = k*2-n+1;
         if(a<=k && a>=1) return false;
     }
     return true;
}


//第一次踢m%2k,m%2k>k,m = 2k*r+h,h>k,最小的m：

int solve(int k)
{
     int m;
     for(int r=0;;r++)
     {
         for(int h=k+1;h<=2*k;h++)
         {
              m = 2*k*r+h;
              if(Joseph(k,m)) goto end; // 找到m跳出
          }
     }
end: 
      return m;
}




int main()
{
	int k;
    while(cin>>k&&k)
	{
		cout<<solve(k)<<endl;
	}
              return 0;
}
