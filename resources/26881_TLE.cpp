
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    int   number=0;
    
    while(cin>>number&&number!=0)
    {
    vector<int>    data;
    int   num=0; 
    for(int i=0;i<number*2;++i)
    {
       data.push_back(i+1);
    }
    bool status=true;
    while(status)
    {
      ++num;
      vector<int>   temp=data;
      int  count=0;
      int  sum=0;
      while(sum!=number)
      {
         for(size_t pos=0;pos!=temp.size() && sum!=number;++pos)
         {
           if(temp[pos]!=0)
              ++count;
           if(count==num)
           {
             temp[pos]=0;
             count=0;
             ++sum;
           }
         }
      }
      size_t i=0;
      for(;i<number;++i)
      {
         if(temp[i]==0)
           break;
      }
      if(i==number)
        status=false;
     }
     cout<<num<<endl;
     }
}
