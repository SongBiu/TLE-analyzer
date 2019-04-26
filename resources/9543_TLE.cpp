#include <iostream>
using namespace std;
int main()
{
	int Removed,count,tag[31],k,stride,i,flag;
	while(cin>>k)
	{
		if(k==0)
			break;
		for(stride=k+1;;stride++)
		{
			for(i=1;i<=2*k;i++)
				tag[i]=1;
			Removed=0,i=1;
			count=1,flag=0;
			while(Removed<k)
			{
				if(i%(2*k)!=0)
					i=i%(2*k);
				if(tag[i]!=0)
				{
					if(count==stride)
					{
						if(i<=k)
						{
							flag=1;
							break;
						}
						tag[i]=0;
						Removed++;
						count=1;
					}
					else
						count++;
				}
				i++;
			}
			if(flag==0)
			{
				cout<<stride<<endl;
				break;
			}
		}
	}
	return 0;
}