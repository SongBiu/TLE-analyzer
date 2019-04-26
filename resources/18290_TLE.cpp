
#include <iostream>   
using namespace std;   
  
int main()   
{   
    long result;
    int k;   
    while (cin>>k&&k>0)   
    {   

            int m = k+1;   
            int numOfPeopleLeft,curPerson;   
            while (1)   
            {      
                numOfPeopleLeft=2*k;       
                curPerson=0;   
                while (1)   
                {   
                    curPerson=(curPerson+m)%numOfPeopleLeft;       
                    if(curPerson==0)   
                        curPerson=numOfPeopleLeft;   
                    if(curPerson>k)   
                    {   
                        curPerson--;   
                        numOfPeopleLeft--;   
                    }   
                    else  
                        break;   
                }   
                if(numOfPeopleLeft<=k)   
                {   
                    result=m;   
                    break;   
                }   
                m++;   
            }    
        cout<<result<<endl;   
    }   
}  
