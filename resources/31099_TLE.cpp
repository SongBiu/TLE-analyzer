#include<cstdio>
using namespace std;

int main()
{
	int i;
	int n;
	int left;
	int pre_death,new_death;
	bool finish;
      while(scanf("%d",&n)&&n)
	{
		for(i=n+1;;i++)
		{
			finish=true;
			left=n<<1,pre_death=0;
                  while(left>n)
			{
                         new_death=(pre_death+i-1)%left;
				 if(new_death<n) 
				 {
					 finish=false;
					 break;
				 }
				 left--,pre_death=new_death;
			}
			if(finish) 
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}